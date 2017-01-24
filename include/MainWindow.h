#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Openglwidget.h>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void updateMaxVel(int _value);
    void updateMaxForce(int _value);
    void updateViewRadius(int _value);
    void newFlock();
    void addObstacle();
private:
    Ui::MainWindow *m_ui;
    OpenGLWidget *m_gl;

};

#endif // MAINWINDOW_H
