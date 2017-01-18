#include "MainWindow.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QSurfaceFormat format; //make instance of format
    format.setSamples(4); //set multisampling rate
    format.setMajorVersion(4); //set OpenGL major version
    format.setMinorVersion(3); //set OpenGL minor version
    format.setProfile(QSurfaceFormat::CoreProfile); //set profile
    format.setDepthBufferSize(24); // set depth buffet bits
    QSurfaceFormat::setDefaultFormat(format); //set format for all widgets
    QApplication a(argc, argv); //instance of QApplication
    MainWindow w;
    w.show();

    return a.exec();
}
