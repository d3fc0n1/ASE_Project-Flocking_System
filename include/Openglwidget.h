#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <ngl/Camera.h>
#include <ngl/Colour.h>
#include <ngl/Light.h>
#include <ngl/Text.h>
#include <ngl/SimpleVAO.h>
#include <ngl/Transformation.h>
#include <QOpenGLWidget>
#include "WindowParams.h"
#include <memory>
#include "World.h"
#include "Boid.h"


class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget *_parent);
    ~OpenGLWidget();
    void newFlock(int _numBoids, float _cohesion, float _separation, float _alignment);

public slots:
    void toggleLeader(bool _leaderState);

protected:
    WinParams m_win;
    ngl::Camera m_cam;
    ngl::Vec3 m_modelPos;
    ngl::Mat4 m_mouseGlobalTX;
    std::unique_ptr<ngl::AbstractVAO> m_boidVAO;
    std::unique_ptr<ngl::AbstractVAO> m_boundingBoxVAO;

    void initializeGL();
    void paintGL();
    void resizeGL(int _w, int _h);
    void timerEvent(QTimerEvent *);

    void setSeparation(float _separation);
    void setAlignment(float _alignment);
    void setCohesion(float _cohesion);

    void addBoid(float _cohesion, float _separation, float _alignment);
    void removeBoid();

private:
    void keyPressEvent(QKeyEvent *_event);
    void mouseMoveEvent (QMouseEvent * _event );
    void mousePressEvent ( QMouseEvent *_event);
    void mouseReleaseEvent ( QMouseEvent *_event );
    void wheelEvent( QWheelEvent *_event);

    void buildBoidVAO();
    void buildBoundingBoxVAO();
    void loadMatrices();

    ngl::Transformation m_transform;

    std::vector<ngl::Vec3> m_positions;
    World *m_world;
    int m_leaderId;
    bool m_leader;
};

#endif // OPENGLWIDGET_H
