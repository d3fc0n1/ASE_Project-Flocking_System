#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Openglwidget.h"
#include "Boid.h"
#include <iostream>
#include <string>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_gl=new OpenGLWidget(this);
    //m_gl->resize();

    m_ui->m_obstacleType->addItem("teapot");
    m_ui->m_obstacleType->addItem("octahedron");
    m_ui->m_obstacleType->addItem("dodecahedron");
    m_ui->m_obstacleType->addItem("icosahedron");
    m_ui->m_obstacleType->addItem("tetrahedron");
    m_ui->m_obstacleType->addItem("football");
    m_ui->m_obstacleType->addItem("cube");
    m_ui->m_obstacleType->addItem("troll");

    m_ui->m_initialPosition->addItem("Center");
    m_ui->m_initialPosition->addItem("Random");

    connect(m_ui->m_newFlock,SIGNAL(pressed()),this,SLOT(newFlock()));
    connect(m_ui->m_addBoid,SIGNAL(pressed()),this,SLOT(addBoid()));
    connect(m_ui->m_removeBoid,SIGNAL(pressed()),this,SLOT(removeBoid()));
    connect(m_ui->m_velocity, SIGNAL(valueChanged(int)), this, SLOT(updateMaxVelocity(int)));
    connect(m_ui->m_force, SIGNAL(valueChanged(int)), this, SLOT(updateMaxForce(int)));
    connect(m_ui->m_viewRadius, SIGNAL(valueChanged(int)), this, SLOT(updateViewRadius(int)));
    connect(m_ui->m_leader,SIGNAL(toggled(bool)),m_gl,SLOT(toggleLeader(bool)));
    connect(m_ui->m_quit, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(m_ui->m_addObstacle, SIGNAL(clicked(bool)), this, SLOT(addObstacle()));
    connect(m_ui->m_addFood, SIGNAL(clicked(bool)), this, SLOT(addFood()));
    connect(m_ui->m_removeFood, SIGNAL(clicked(bool)), this, SLOT(removeFood()));
    connect(m_ui->m_obstacleSize, SIGNAL(valueChanged(int)), this, SLOT(updateObstacleSize(int)));
    connect(m_ui->m_removeObstacle, SIGNAL(clicked(bool)), this, SLOT(removeObstacle()));
    connect(m_ui->m_addPredator, SIGNAL(clicked(bool)), this, SLOT(setPredator()));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::updateMaxVelocity(int _value)
{
    //m_gl->m_world->m_flock[i].setVelocity()
    m_ui->maxVelLabel->setText(QString::fromStdString(std::to_string(_value)));
}

void MainWindow::updateMaxForce(int _value)
{
    m_ui->maxForceLabel->setText(QString::fromStdString(std::to_string(_value)));
}

void MainWindow::updateViewRadius(int _value)
{
    m_ui->viewRadiusLabel->setText(QString::fromStdString(std::to_string(_value)));
}

void MainWindow::newFlock()
{
    m_gl->newFlock(m_ui->m_newFlockBoidCount->value(), m_ui->m_initialPosition->currentIndex());
    m_ui->m_currentBoidCount->setText(QString::fromStdString(std::to_string(m_ui->m_newFlockBoidCount->value())));
}

void MainWindow::addBoid()
{
    m_gl->addBoid(false);
    m_ui->m_currentBoidCount->setText(QString::fromStdString(std::to_string(m_ui->m_currentBoidCount->text().toInt() + 1)));
}

void MainWindow::removeBoid()
{
    m_gl->removeBoid();
    if (m_ui->m_currentBoidCount->text().toInt() - 1 >= 0)
    {
        m_ui->m_currentBoidCount->setText(QString::fromStdString(std::to_string(m_ui->m_currentBoidCount->text().toInt() - 1)));
    }
}

void MainWindow::addObstacle()
{
    std::string selectedObstacle = m_ui->m_obstacleType->currentText().toStdString();
    m_gl->addObstacle(selectedObstacle);
}

void MainWindow::removeObstacle()
{
    m_gl->removeObstacle();
}

void MainWindow::addFood()
{
    m_gl->addFood();
}
void MainWindow::removeFood()
{
    m_gl->removeFood();
}

void MainWindow::updateObstacleSize(int _size)
{
    float obstacleSize = static_cast<float>(_size) / 10;
    m_ui->m_obstacleSizeText->setText((QString::fromStdString(std::to_string(obstacleSize))).left(4));
    m_gl->updateObstacleSize(static_cast<float>(obstacleSize));
}

void MainWindow::toggleLeader(bool _leaderState)
{
    m_gl->toggleLeader(_leaderState);
}
void MainWindow::setPredator()
{
    m_gl->setPredator();
}
