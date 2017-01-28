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
    void updateMaxVelocity(int _value);
    void updateMaxForce(int _value);
    void updateViewRadius(int _value);
    void updateObstacleSize(int _size);
    void newFlock();
    void addBoid();
    void removeBoid();
    void addObstacle();
    void addFood();
    void removeFood();
    void removeObstacle();
    void toggleLeader(bool _leaderState);
    void setPredator();
private:
    Ui::MainWindow *m_ui;
    OpenGLWidget *m_gl;

};

#endif // MAINWINDOW_H
