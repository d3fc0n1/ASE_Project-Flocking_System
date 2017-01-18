#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T23:59:56
#
#-------------------------------------------------

QT       += core gui core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

isEqual(QT_MAJOR_VERSION, 5) {
        cache()
        DEFINES +=QT5BUILD
}

TARGET = Flocker
TEMPLATE = app


SOURCES += $$PWD/src/main.cpp \
           $$PWD/src/Boid.cpp \
           $$PWD/src/Openglwidget.cpp \
           $$PWD/src/MainWindow.cpp \
           $$PWD/src/World.cpp \
           $$PWD/src/Octree.cpp

HEADERS  += $$PWD/include/Boid.h \
            $$PWD/include/WindowParams.h \
            $$PWD/include/Openglwidget.h \
            $$PWD/include/MainWindow.h \
            $$PWD/include/World.h \
            $$PWD/include/Octree.h

FORMS   +=  $$PWD/ui/MainWindow.ui

INCLUDEPATH +=./include

OTHER_FILES+= shaders/*.glsl \

NGLPATH=$$(NGLDIR)
isEmpty(NGLPATH){ # note brace must be here
        message("including $HOME/NGL")
        include($(HOME)/NGL/UseNGL.pri)
}
