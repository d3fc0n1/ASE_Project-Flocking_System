/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *m_quit;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *m_force;
    QLabel *maxForceLabel;
    QPushButton *m_addObstacle;
    QCheckBox *m_leader;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *m_viewRadius;
    QLabel *viewRadiusLabel;
    QPushButton *m_removeObstacle;
    QPushButton *m_removePredator;
    QPushButton *m_addPredator;
    QPushButton *m_addBoid;
    QComboBox *m_obstacleType;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *m_velocity;
    QLabel *maxVelLabel;
    QPushButton *m_removeBoid;
    QPushButton *m_newFlock;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1029, 720);
        MainWindow->setMinimumSize(QSize(1024, 720));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_quit = new QPushButton(centralWidget);
        m_quit->setObjectName(QStringLiteral("m_quit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_quit->sizePolicy().hasHeightForWidth());
        m_quit->setSizePolicy(sizePolicy);
        m_quit->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(m_quit, 2, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 40));

        horizontalLayout_2->addWidget(label_2);

        m_force = new QSlider(centralWidget);
        m_force->setObjectName(QStringLiteral("m_force"));
        m_force->setMinimumSize(QSize(120, 40));
        m_force->setMinimum(1);
        m_force->setMaximum(10);
        m_force->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(m_force);

        maxForceLabel = new QLabel(centralWidget);
        maxForceLabel->setObjectName(QStringLiteral("maxForceLabel"));

        horizontalLayout_2->addWidget(maxForceLabel);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        m_addObstacle = new QPushButton(centralWidget);
        m_addObstacle->setObjectName(QStringLiteral("m_addObstacle"));
        sizePolicy.setHeightForWidth(m_addObstacle->sizePolicy().hasHeightForWidth());
        m_addObstacle->setSizePolicy(sizePolicy);
        m_addObstacle->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_addObstacle, 9, 0, 1, 1);

        m_leader = new QCheckBox(centralWidget);
        m_leader->setObjectName(QStringLiteral("m_leader"));
        m_leader->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_leader, 12, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 40));

        horizontalLayout_3->addWidget(label_3);

        m_viewRadius = new QSlider(centralWidget);
        m_viewRadius->setObjectName(QStringLiteral("m_viewRadius"));
        m_viewRadius->setMinimumSize(QSize(120, 40));
        m_viewRadius->setMaximum(100);
        m_viewRadius->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(m_viewRadius);

        viewRadiusLabel = new QLabel(centralWidget);
        viewRadiusLabel->setObjectName(QStringLiteral("viewRadiusLabel"));

        horizontalLayout_3->addWidget(viewRadiusLabel);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        m_removeObstacle = new QPushButton(centralWidget);
        m_removeObstacle->setObjectName(QStringLiteral("m_removeObstacle"));
        m_removeObstacle->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_removeObstacle, 9, 1, 1, 1);

        m_removePredator = new QPushButton(centralWidget);
        m_removePredator->setObjectName(QStringLiteral("m_removePredator"));
        m_removePredator->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_removePredator, 6, 1, 1, 1);

        m_addPredator = new QPushButton(centralWidget);
        m_addPredator->setObjectName(QStringLiteral("m_addPredator"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_addPredator->sizePolicy().hasHeightForWidth());
        m_addPredator->setSizePolicy(sizePolicy1);
        m_addPredator->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_addPredator, 6, 0, 1, 1);

        m_addBoid = new QPushButton(centralWidget);
        m_addBoid->setObjectName(QStringLiteral("m_addBoid"));
        sizePolicy.setHeightForWidth(m_addBoid->sizePolicy().hasHeightForWidth());
        m_addBoid->setSizePolicy(sizePolicy);
        m_addBoid->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_addBoid, 5, 0, 1, 1);

        m_obstacleType = new QComboBox(centralWidget);
        m_obstacleType->setObjectName(QStringLiteral("m_obstacleType"));
        m_obstacleType->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_obstacleType, 8, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(label);

        m_velocity = new QSlider(centralWidget);
        m_velocity->setObjectName(QStringLiteral("m_velocity"));
        m_velocity->setMinimumSize(QSize(120, 40));
        m_velocity->setMinimum(1);
        m_velocity->setMaximum(50);
        m_velocity->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(m_velocity);

        maxVelLabel = new QLabel(centralWidget);
        maxVelLabel->setObjectName(QStringLiteral("maxVelLabel"));

        horizontalLayout->addWidget(maxVelLabel);


        gridLayout_3->addLayout(horizontalLayout, 3, 0, 1, 2);

        m_removeBoid = new QPushButton(centralWidget);
        m_removeBoid->setObjectName(QStringLiteral("m_removeBoid"));
        m_removeBoid->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_removeBoid, 5, 1, 1, 1);

        m_newFlock = new QPushButton(centralWidget);
        m_newFlock->setObjectName(QStringLiteral("m_newFlock"));
        m_newFlock->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_newFlock, 0, 0, 1, 2);


        gridLayout->addLayout(gridLayout_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Flocker", 0));
        m_quit->setText(QApplication::translate("MainWindow", "Quit", 0));
        label_2->setText(QApplication::translate("MainWindow", "Max. Force", 0));
        maxForceLabel->setText(QApplication::translate("MainWindow", "0", 0));
        m_addObstacle->setText(QApplication::translate("MainWindow", "Add Obstacle", 0));
        m_leader->setText(QApplication::translate("MainWindow", "Assign Leader", 0));
        label_3->setText(QApplication::translate("MainWindow", "View Radius", 0));
        viewRadiusLabel->setText(QApplication::translate("MainWindow", "0", 0));
        m_removeObstacle->setText(QApplication::translate("MainWindow", "Remove Obstacle", 0));
        m_removePredator->setText(QApplication::translate("MainWindow", "Remove Predator", 0));
        m_addPredator->setText(QApplication::translate("MainWindow", "Add Predator", 0));
        m_addBoid->setText(QApplication::translate("MainWindow", "Add Boid", 0));
        label->setText(QApplication::translate("MainWindow", "Max. Velocity", 0));
        maxVelLabel->setText(QApplication::translate("MainWindow", "0", 0));
        m_removeBoid->setText(QApplication::translate("MainWindow", "Remove Boid", 0));
        m_newFlock->setText(QApplication::translate("MainWindow", "New Flock", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
