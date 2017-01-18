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
    QGridLayout *gridLayout_3;
    QPushButton *addObstacleButton;
    QPushButton *quitButton;
    QCheckBox *m_leader;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *maxVelSlider;
    QLabel *maxVelLabel;
    QPushButton *addPredatorButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *viewRadiusSlider;
    QLabel *viewRadiusLabel;
    QPushButton *addBoidButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *maxForceSlider;
    QLabel *maxForceLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *m_newFlock;
    QSpacerItem *horizontalSpacer;
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
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        addObstacleButton = new QPushButton(centralWidget);
        addObstacleButton->setObjectName(QStringLiteral("addObstacleButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addObstacleButton->sizePolicy().hasHeightForWidth());
        addObstacleButton->setSizePolicy(sizePolicy);
        addObstacleButton->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(addObstacleButton, 3, 1, 1, 1);

        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        sizePolicy.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy);
        quitButton->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(quitButton, 4, 1, 1, 1);

        m_leader = new QCheckBox(centralWidget);
        m_leader->setObjectName(QStringLiteral("m_leader"));

        gridLayout_3->addWidget(m_leader, 6, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        maxVelSlider = new QSlider(centralWidget);
        maxVelSlider->setObjectName(QStringLiteral("maxVelSlider"));
        maxVelSlider->setMinimumSize(QSize(120, 0));
        maxVelSlider->setMinimum(1);
        maxVelSlider->setMaximum(50);
        maxVelSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(maxVelSlider);

        maxVelLabel = new QLabel(centralWidget);
        maxVelLabel->setObjectName(QStringLiteral("maxVelLabel"));

        horizontalLayout->addWidget(maxVelLabel);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 2);

        addPredatorButton = new QPushButton(centralWidget);
        addPredatorButton->setObjectName(QStringLiteral("addPredatorButton"));
        sizePolicy.setHeightForWidth(addPredatorButton->sizePolicy().hasHeightForWidth());
        addPredatorButton->setSizePolicy(sizePolicy);
        addPredatorButton->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(addPredatorButton, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        viewRadiusSlider = new QSlider(centralWidget);
        viewRadiusSlider->setObjectName(QStringLiteral("viewRadiusSlider"));
        viewRadiusSlider->setMinimumSize(QSize(120, 0));
        viewRadiusSlider->setMaximum(100);
        viewRadiusSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(viewRadiusSlider);

        viewRadiusLabel = new QLabel(centralWidget);
        viewRadiusLabel->setObjectName(QStringLiteral("viewRadiusLabel"));

        horizontalLayout_3->addWidget(viewRadiusLabel);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        addBoidButton = new QPushButton(centralWidget);
        addBoidButton->setObjectName(QStringLiteral("addBoidButton"));
        sizePolicy.setHeightForWidth(addBoidButton->sizePolicy().hasHeightForWidth());
        addBoidButton->setSizePolicy(sizePolicy);
        addBoidButton->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(addBoidButton, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        maxForceSlider = new QSlider(centralWidget);
        maxForceSlider->setObjectName(QStringLiteral("maxForceSlider"));
        maxForceSlider->setMinimumSize(QSize(120, 0));
        maxForceSlider->setMinimum(1);
        maxForceSlider->setMaximum(10);
        maxForceSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(maxForceSlider);

        maxForceLabel = new QLabel(centralWidget);
        maxForceLabel->setObjectName(QStringLiteral("maxForceLabel"));

        horizontalLayout_2->addWidget(maxForceLabel);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 7, 1, 1, 1);

        m_newFlock = new QPushButton(centralWidget);
        m_newFlock->setObjectName(QStringLiteral("m_newFlock"));

        gridLayout_3->addWidget(m_newFlock, 5, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

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
        addObstacleButton->setText(QApplication::translate("MainWindow", "Add Obstacle", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        m_leader->setText(QApplication::translate("MainWindow", "Leader", 0));
        label->setText(QApplication::translate("MainWindow", "Max. Velocity", 0));
        maxVelLabel->setText(QApplication::translate("MainWindow", "0", 0));
        addPredatorButton->setText(QApplication::translate("MainWindow", "Add Predator", 0));
        label_3->setText(QApplication::translate("MainWindow", "View Radius", 0));
        viewRadiusLabel->setText(QApplication::translate("MainWindow", "0", 0));
        addBoidButton->setText(QApplication::translate("MainWindow", "Add Boid", 0));
        label_2->setText(QApplication::translate("MainWindow", "Max. Force", 0));
        maxForceLabel->setText(QApplication::translate("MainWindow", "0", 0));
        m_newFlock->setText(QApplication::translate("MainWindow", "New Flock", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
