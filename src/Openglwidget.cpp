#include <QMouseEvent>
#include <QGuiApplication>
#include "Openglwidget.h"
#include <ngl/Transformation.h>
#include <ngl/Material.h>
#include <ngl/NGLInit.h>
#include <ngl/ShaderLib.h>
#include <ngl/VAOFactory.h>
#include <ngl/Random.h>
#include <iostream>
#include <math.h>

OpenGLWidget::OpenGLWidget(QWidget *_parent):QOpenGLWidget(_parent)
{
    setFocus();
    this->resize(750 , 700);
    m_leader = false;
}
OpenGLWidget::~OpenGLWidget()
{
    std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
    m_boidVAO->removeVAO();
    m_boundingBoxVAO->removeVAO();
    delete m_world;
}
void OpenGLWidget::resizeGL(int _w, int _h)
{
    m_cam.setShape( 45.0f, static_cast<float>( _w ) / _h, 0.05f, 350.0f );
    m_win.width  = static_cast<int>( _w * devicePixelRatio() );
    m_win.height = static_cast<int>( _h * devicePixelRatio() );
}
void OpenGLWidget::initializeGL()
{
    // we need to initialise the NGL lib which will load all of the OpenGL functions, this must
    // be done once we have a valid GL context but before we call any GL commands. If we dont do
    // this everything will crash
    ngl::NGLInit::instance();

    glClearColor(0.5f, 0.6f, 0.7f, 1.0f);			   // Grey Background
    // enable depth testing for drawing

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    // Now we will create a basic Camera from the graphics library
    // This is a static camera so it only needs to be set once
    // First create Values for the camera position
    ngl::Vec3 from(0,50,350);
    ngl::Vec3 to(0,0,0);
    ngl::Vec3 up(0,1,0);

    m_cam.set(from,to,up);
    // set the shape using FOV 45 Aspect Ratio based on Width and Height
    // The final two are near and far clipping planes of 0.5 and 10
    m_cam.setShape(45,720.0f/576.0f,0.001f,150);
    // now to load the shader and set the values
    // grab an instance of shader manager
    ngl::ShaderLib* shader = ngl::ShaderLib::instance();
    // we are creating a shader called Phong to save typos
    // in the code create some constexpr
    constexpr auto shaderProgram = "Phong";
    constexpr auto vertexShader  = "PhongVertex";
    constexpr auto fragShader    = "PhongFragment";
    // create the shader program
    shader->createShaderProgram( shaderProgram );
    // now we are going to create empty shaders for Frag and Vert
    shader->attachShader( vertexShader, ngl::ShaderType::VERTEX );
    shader->attachShader( fragShader, ngl::ShaderType::FRAGMENT );
    // attach the source
    shader->loadShaderSource( vertexShader, "shaders/PhongVertex.glsl" );
    shader->loadShaderSource( fragShader, "shaders/PhongFragment.glsl" );
    // compile the shaders
    shader->compileShader( vertexShader );
    shader->compileShader( fragShader );
    // add them to the program
    shader->attachShaderToProgram( shaderProgram, vertexShader );
    shader->attachShaderToProgram( shaderProgram, fragShader );
    // bind shader attributes for ngl primitives
    // layout attribute 0 is the vertex data (x,y,z)
    shader->bindAttribute("Phong",0,"inVert");
    // attribute 1 is the UV data u,v (if present)
    shader->bindAttribute("Phong",1,"inUV");
    // attribute 2 are the normals x,y,z
    shader->bindAttribute("Phong",2,"inNormal");

    // now we have associated that data we can link the shader
    shader->linkProgramObject( shaderProgram );
    // and make it active ready to load values
    ( *shader )[ shaderProgram ]->use();
    // the shader will use the currently active material and light0 so set them
    ngl::Material m( ngl::STDMAT::CHROME );
    // load our material values to the shader into the structure material (see Vertex shader)
    m.loadToShader( "material" );
    shader->setShaderParam3f("viewerPos",m_cam.getEye().m_x,m_cam.getEye().m_y,m_cam.getEye().m_z);
    // now create our light this is done after the camera so we can pass the
    // transpose of the projection matrix to the light to do correct eye space
    // transformations


    m_world = new World(100);

    m_obstacle = ngl::VAOPrimitives::instance();

    ngl::Mat4 iv=m_cam.getViewMatrix();
    iv.transpose();
    iv=iv.inverse();
    ngl::Light l(ngl::Vec3(0,1,0),ngl::Colour(1,1,1,1),ngl::Colour(1,1,1,1),ngl::LightModes::POINTLIGHT);
    l.setTransform(iv);
    // load these values to the shader as well
    l.loadToShader("light");

    startTimer(10);

    glViewport(0,0,m_win.width,m_win.height);

    buildBoundingBoxVAO();
    buildBoidVAO();
}

void OpenGLWidget::buildBoundingBoxVAO()
{
    std::vector<ngl::Vec3> verts =
    {
        ngl::Vec3(100,100,100),
        ngl::Vec3(100,100,-100),

        ngl::Vec3(100,100,-100),
        ngl::Vec3(-100,100,-100),

        ngl::Vec3(-100,100,-100),
        ngl::Vec3(-100,100,100),

        ngl::Vec3(-100,100,100),
        ngl::Vec3(100,100,100),

        ngl::Vec3(100,-100,100),
        ngl::Vec3(100,-100,-100),

        ngl::Vec3(100,-100,-100),
        ngl::Vec3(-100,-100,-100),

        ngl::Vec3(-100,-100,-100),
        ngl::Vec3(-100,-100,100),

        ngl::Vec3(-100,-100,100),
        ngl::Vec3(100,-100,100),

        ngl::Vec3(100,-100,100),
        ngl::Vec3(100,100,100),

        ngl::Vec3(100,-100,-100),
        ngl::Vec3(100,100,-100),

        ngl::Vec3(-100,-100,-100),
        ngl::Vec3(-100,100,-100),

        ngl::Vec3(-100,-100,100),
        ngl::Vec3(-100,100,100),
    };

    m_boundingBoxVAO.reset(ngl::VAOFactory::createVAO(ngl::simpleVAO,GL_LINES) );
    m_boundingBoxVAO->bind();
    m_boundingBoxVAO->setData(ngl::SimpleVAO::VertexData(verts.size()*sizeof(ngl::Vec3),verts[0].m_x));
    m_boundingBoxVAO->setVertexAttributePointer(0,3,GL_FLOAT,0,0);

    m_boundingBoxVAO->setNumIndices(verts.size());

    m_boundingBoxVAO->unbind();
}
void OpenGLWidget::buildBoidVAO()
{
    std::vector<ngl::Vec3> verts =
    {
        //top left
        ngl::Vec3(0,0,-3),
        ngl::Vec3(-3,0,4.5),
        ngl::Vec3(0,0.6,3),
        //top right
        ngl::Vec3(0,0,-3),
        ngl::Vec3(0,0.6,3),
        ngl::Vec3(3,0,4.5),
        //bottom left
        ngl::Vec3(0,0,-3),
        ngl::Vec3(0,-0.6,3),
        ngl::Vec3(-3,0,4.5),
        //bottom right
        ngl::Vec3(3,0,4.5),
        ngl::Vec3(0,-0.6,3),
        ngl::Vec3(0,0,-3),
        //rear left
        ngl::Vec3(0,0.6,3),
        ngl::Vec3(-3,0,4.5),
        ngl::Vec3(0,-0.6,3),
        //rear right
        ngl::Vec3(0,0.6,3),
        ngl::Vec3(0,-0.6,3),
        ngl::Vec3(3,0,4.5)

    };

    ngl::Vec3 n=ngl::calcNormal(verts[2],verts[1],verts[0]);
    verts.push_back(n);
    verts.push_back(n);
    verts.push_back(n);

    n=ngl::calcNormal(verts[5],verts[4],verts[3]);
    verts.push_back(n);
    verts.push_back(n);
    verts.push_back(n);

    n=ngl::calcNormal(verts[8],verts[7],verts[6]);
    verts.push_back(n);
    verts.push_back(n);
    verts.push_back(n);

    n=ngl::calcNormal(verts[11],verts[10],verts[9]);
    verts.push_back(n);
    verts.push_back(n);
    verts.push_back(n);

    n=ngl::calcNormal(verts[14],verts[13],verts[12]);
    verts.push_back(n);
    verts.push_back(n);
    verts.push_back(n);

    n=ngl::calcNormal(verts[17],verts[16],verts[15]);
    verts.push_back(n);
    verts.push_back(n);
    verts.push_back(n);

    // create a vao as a series of GL_TRIANGLES
    m_boidVAO.reset(ngl::VAOFactory::createVAO(ngl::simpleVAO,GL_TRIANGLES) );
    m_boidVAO->bind();

    // in this case we are going to set our data as the vertices above
    m_boidVAO->setData(ngl::SimpleVAO::VertexData(verts.size()*sizeof(ngl::Vec3),verts[0].m_x));
    // now we set the attribute pointer to be 0 (as this matches vertIn in our shader)

    m_boidVAO->setVertexAttributePointer(0,3,GL_FLOAT,0,0);

    // now we set the attribute pointer to be 2 (as this matches normal in our shader)
    // as we cast to ngl::Real for offset use 12 * 3 (as in x,y,z is 3 floats)
    m_boidVAO->setVertexAttributePointer(2,3,GL_FLOAT,0,18*3);
    // divide by 2 as we have both verts and normals
    m_boidVAO->setNumIndices(verts.size()/2);

    // now unbind
    m_boidVAO->unbind();
}
void OpenGLWidget::loadMatrices()
{
    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    (*shader)["Phong"]->use();

    ngl::Mat4 MV;
    ngl::Mat4 MVP;
    ngl::Mat3 normalMatrix;
    ngl::Mat4 M;

    M= m_tx.getMatrix() * m_mouseGlobalTX;
    MV=  M*m_cam.getViewMatrix();
    MVP= M*m_cam.getVPMatrix();
    normalMatrix=MV;
    normalMatrix.inverse();
    shader->setShaderParamFromMat4("MV",MV);
    shader->setShaderParamFromMat4("MVP",MVP);
    shader->setShaderParamFromMat3("normalMatrix",normalMatrix);
    shader->setShaderParamFromMat4("M",M);
}

void OpenGLWidget::paintGL()
{
    // clear the screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    //(*shader)["Phong"]->use();
    // Rotation based on the mouse position for our global
    // transform
    ngl::Mat4 rotX;
    ngl::Mat4 rotY;
    // create the rotation matrices
    rotX.rotateX(m_win.spinXFace);
    rotY.rotateY(m_win.spinYFace);
    // multiply the rotations
    m_mouseGlobalTX=rotY*rotX;
    // add the translations
    m_mouseGlobalTX.m_m[3][0] = m_modelPos.m_x;
    m_mouseGlobalTX.m_m[3][1] = m_modelPos.m_y;
    m_mouseGlobalTX.m_m[3][2] = m_modelPos.m_z;



    m_boidVAO->bind();

    for (int i = 0; i < m_world->getSize(); ++i)
    {
        if(m_world->m_flock[i].isLeader())
        {
            m_tx.setScale(3,3,3);
        }
        else
        {
            m_tx.setScale(1,1,1);
        }
        m_tx.setRotation(m_world->m_flock[i].getRotation());
        m_tx.setPosition(m_world->m_flock[i].getPosition());
        loadMatrices();
        m_boidVAO->draw();
    }
    m_boidVAO->unbind();
    m_tx.reset();
    loadMatrices();
    m_boundingBoxVAO->bind();
    m_boundingBoxVAO->draw();
    m_boundingBoxVAO->unbind();

    for(size_t i=0 ; i<m_world->m_obstacles.size() ; ++i)
    {
        m_tx.reset();
        m_tx.setPosition(m_world->m_obstacles[i].getPosition());
        float size = m_world->m_obstacles[i].getSize();
        m_tx.setScale(size, size, size);
        loadMatrices();
        m_obstacle->draw(m_world->m_obstacles[i].getShape());
    }
    m_world->avoidObstacles();
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::mouseMoveEvent( QMouseEvent* _event )
{
    // note the method buttons() is the button state when event was called
    // that is different from button() which is used to check which button was
    // pressed when the mousePress/Release event is generated
    if ( m_win.rotate && _event->buttons() == Qt::LeftButton )
    {
        int diffx = _event->x() - m_win.origX;
        int diffy = _event->y() - m_win.origY;
        m_win.spinXFace += static_cast<int>( 0.5f * diffy );
        m_win.spinYFace += static_cast<int>( 0.5f * diffx );
        m_win.origX = _event->x();
        m_win.origY = _event->y();
        update();
    }
    // right mouse translate code
    else if ( m_win.translate && _event->buttons() == Qt::RightButton )
    {
        int diffX      = static_cast<int>( _event->x() - m_win.origXPos );
        int diffY      = static_cast<int>( _event->y() - m_win.origYPos );
        m_win.origXPos = _event->x();
        m_win.origYPos = _event->y();
        m_modelPos.m_x += INCREMENT * diffX;
        m_modelPos.m_y -= INCREMENT * diffY;
        update();
    }
}
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::mousePressEvent( QMouseEvent* _event )
{
    // that method is called when the mouse button is pressed in this case we
    // store the value where the maouse was clicked (x,y) and set the Rotate flag to true
    if ( _event->button() == Qt::LeftButton )
    {
        m_win.origX  = _event->x();
        m_win.origY  = _event->y();
        m_win.rotate = true;
    }
    // right mouse translate mode
    else if ( _event->button() == Qt::RightButton )
    {
        m_win.origXPos  = _event->x();
        m_win.origYPos  = _event->y();
        m_win.translate = true;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::mouseReleaseEvent( QMouseEvent* _event )
{
    // that event is called when the mouse button is released
    // we then set Rotate to false
    if ( _event->button() == Qt::LeftButton )
    {
        m_win.rotate = false;
    }
    // right mouse translate mode
    if ( _event->button() == Qt::RightButton )
    {
        m_win.translate = false;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::wheelEvent( QWheelEvent* _event )
{

    // check the diff of the wheel position (0 means no change)
    if ( _event->delta() > 0 )
    {
        m_modelPos.m_z += ZOOM;
    }
    else if ( _event->delta() < 0 )
    {
        m_modelPos.m_z -= ZOOM;
    }
    update();
}
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::keyPressEvent(QKeyEvent *_event)
{
    // this method is called every time the main window recives a key event.
    // we then switch on the key value and set the camera in the GLWindow
    switch (_event->key())
    {
    // escape key to quite
    case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
        // turn on wirframe rendering
    case Qt::Key_W : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
        // turn off wire frame
    case Qt::Key_S : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;
        // show full screen
    case Qt::Key_F : showFullScreen(); break;
        // show windowed
    case Qt::Key_N : showNormal(); break;
    default : break;
    }
    // finally update the GLWindow and re-draw
    //if (isExposed())
    update();
}

void OpenGLWidget::addBoid(float _cohesion, float _separation, float _alignment)
{
    m_world->addBoid(_cohesion, _separation, _alignment);
    setFocus();
}

void OpenGLWidget::removeBoid()
{
    m_world->removeBoid();
    setFocus();
}

void OpenGLWidget::timerEvent(QTimerEvent *)
{
    m_world->updateWorld();
    update();
}

void OpenGLWidget::newFlock(int _numBoids)
{
    delete m_world;
    m_world=new World(_numBoids);
    setFocus();
}

//void OpenGLWidget::setSpeed(int _speed)
//{
//    float speed = _speed/10.0;
//    for(size_t i=0; i<m_world->m_flock.size(); ++i)
//    {
//        m_world->m_flock[i].setSpeed(speed);
//    }
//    setFocus();
//}

void OpenGLWidget::setCohesion(float _cohesion)
{
    for(size_t i=0; i<m_world->m_flock.size(); ++i)
    {
        m_world->m_flock[i].setCohesionWeight(_cohesion);
    }
    setFocus();
}

void OpenGLWidget::setSeparation(float _separation)
{
    for(size_t i=0; i<m_world->m_flock.size(); ++i)
    {
        m_world->m_flock[i].setSeparationWeight(_separation);
    }
    setFocus();
}

void OpenGLWidget::setAlignment(float _align)
{
    for(size_t i=0; i<m_world->m_flock.size(); ++i)
    {
        m_world->m_flock[i].setAlignmentWeight(_align);
    }
    setFocus();
}

void OpenGLWidget::toggleLeader(bool _leaderState)
{
    if(_leaderState==true)
    {
        m_world->setLeader(1);
        m_leader = _leaderState;;
    }
    else
    {
        m_world->clearLeader();
        m_leader = _leaderState;;
    }
    setFocus();
}

void OpenGLWidget::addObstacle(std::string _obstacleType)
{
    m_world->addObstacle(_obstacleType);
    setFocus();
}

void OpenGLWidget::removeObstacle()
{
    m_world->removeObstacle();
    setFocus();
}

void OpenGLWidget::updateObstacleSize(float _size)
{
    m_world->updateObstacleSize(_size);
}

//void OpenGLWidget::setSeparation(float _separation)
//{
//    for(int i=0;i<m_world->m_flock.size();++i)
//    {
//      m_world->m_flock[i].setSeparation(_separation);
//    }
//    setFocus();
//}
