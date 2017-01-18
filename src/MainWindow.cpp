#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Openglwidget.h"
#include "Boid.h"
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_gl=new OpenGLWidget(this);

    //m_gl->resize();
    //m_ui->
    connect(m_ui->m_newFlock,SIGNAL(pressed()),this,SLOT(newFlockPressed()));
    connect(m_ui->maxVelSlider, SIGNAL(valueChanged(int)), this, SLOT(updateMaxVel(int)));
    connect(m_ui->maxForceSlider, SIGNAL(valueChanged(int)), this, SLOT(updateMaxForce(int)));
    connect(m_ui->viewRadiusSlider, SIGNAL(valueChanged(int)), this, SLOT(updateViewRadius(int)));
    connect(m_ui->m_leader,SIGNAL(toggled(bool)),m_gl,SLOT(toggleLeader(bool)));
    connect(m_ui->quitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::updateMaxVel(int _value)
{
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

void MainWindow::newFlockPressed()
{
//  m_gl->newFlock(m_ui->m_flockCount->value(),
//                 m_ui->m_cohesion->value(),
//                 m_ui->m_separation->value(),
//                 m_ui->m_alignment->value(),
//                 (m_ui->m_speed->value()/10.0));

  m_gl->newFlock(50,
                 20,
                 10,
                 20);
}
