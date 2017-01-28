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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *m_quit;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *horizontalSlider;
    QCheckBox *m_leader;
    QPushButton *m_newFlock;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *m_velocity;
    QLabel *maxVelLabel;
    QSpinBox *m_newFlockBoidCount;
    QLabel *label_7;
    QPushButton *m_removeBoid;
    QPushButton *m_addFood;
    QPushButton *m_removePredator;
    QPushButton *m_addPredator;
    QPushButton *m_addBoid;
    QComboBox *m_initialPosition;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *m_viewRadius;
    QLabel *viewRadiusLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *m_force;
    QLabel *maxForceLabel;
    QPushButton *m_removeFood;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *m_currentBoidCount;
    QWidget *tab_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QComboBox *m_obstacleType;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_addObstacle;
    QPushButton *m_removeObstacle;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSlider *m_obstacleSize;
    QLabel *m_obstacleSizeText;
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

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(250, 0));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        layoutWidget = new QWidget(tab_1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 231, 530));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_8, 8, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 40));

        horizontalLayout_5->addWidget(label_5);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(0, 40));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider);


        gridLayout_3->addLayout(horizontalLayout_5, 5, 0, 1, 2);

        m_leader = new QCheckBox(layoutWidget);
        m_leader->setObjectName(QStringLiteral("m_leader"));
        m_leader->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_leader, 15, 0, 1, 2);

        m_newFlock = new QPushButton(layoutWidget);
        m_newFlock->setObjectName(QStringLiteral("m_newFlock"));
        m_newFlock->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_newFlock, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(label);

        m_velocity = new QSlider(layoutWidget);
        m_velocity->setObjectName(QStringLiteral("m_velocity"));
        m_velocity->setMinimumSize(QSize(120, 40));
        m_velocity->setMinimum(1);
        m_velocity->setMaximum(50);
        m_velocity->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(m_velocity);

        maxVelLabel = new QLabel(layoutWidget);
        maxVelLabel->setObjectName(QStringLiteral("maxVelLabel"));

        horizontalLayout->addWidget(maxVelLabel);


        gridLayout_3->addLayout(horizontalLayout, 4, 0, 1, 2);

        m_newFlockBoidCount = new QSpinBox(layoutWidget);
        m_newFlockBoidCount->setObjectName(QStringLiteral("m_newFlockBoidCount"));
        m_newFlockBoidCount->setMinimumSize(QSize(0, 20));
        m_newFlockBoidCount->setMinimum(1);
        m_newFlockBoidCount->setMaximum(1000);
        m_newFlockBoidCount->setValue(100);

        gridLayout_3->addWidget(m_newFlockBoidCount, 0, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_7, 6, 0, 1, 2);

        m_removeBoid = new QPushButton(layoutWidget);
        m_removeBoid->setObjectName(QStringLiteral("m_removeBoid"));
        m_removeBoid->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(18);
        m_removeBoid->setFont(font);

        gridLayout_3->addWidget(m_removeBoid, 7, 1, 1, 1);

        m_addFood = new QPushButton(layoutWidget);
        m_addFood->setObjectName(QStringLiteral("m_addFood"));
        m_addFood->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_addFood, 11, 0, 1, 1);

        m_removePredator = new QPushButton(layoutWidget);
        m_removePredator->setObjectName(QStringLiteral("m_removePredator"));
        m_removePredator->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_removePredator, 9, 1, 1, 1);

        m_addPredator = new QPushButton(layoutWidget);
        m_addPredator->setObjectName(QStringLiteral("m_addPredator"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_addPredator->sizePolicy().hasHeightForWidth());
        m_addPredator->setSizePolicy(sizePolicy3);
        m_addPredator->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_addPredator, 9, 0, 1, 1);

        m_addBoid = new QPushButton(layoutWidget);
        m_addBoid->setObjectName(QStringLiteral("m_addBoid"));
        sizePolicy.setHeightForWidth(m_addBoid->sizePolicy().hasHeightForWidth());
        m_addBoid->setSizePolicy(sizePolicy);
        m_addBoid->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_addBoid, 7, 0, 1, 1);

        m_initialPosition = new QComboBox(layoutWidget);
        m_initialPosition->setObjectName(QStringLiteral("m_initialPosition"));
        sizePolicy3.setHeightForWidth(m_initialPosition->sizePolicy().hasHeightForWidth());
        m_initialPosition->setSizePolicy(sizePolicy3);
        m_initialPosition->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_initialPosition, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 40));

        horizontalLayout_3->addWidget(label_3);

        m_viewRadius = new QSlider(layoutWidget);
        m_viewRadius->setObjectName(QStringLiteral("m_viewRadius"));
        m_viewRadius->setMinimumSize(QSize(120, 40));
        m_viewRadius->setMaximum(100);
        m_viewRadius->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(m_viewRadius);

        viewRadiusLabel = new QLabel(layoutWidget);
        viewRadiusLabel->setObjectName(QStringLiteral("viewRadiusLabel"));

        horizontalLayout_3->addWidget(viewRadiusLabel);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 40));

        horizontalLayout_2->addWidget(label_2);

        m_force = new QSlider(layoutWidget);
        m_force->setObjectName(QStringLiteral("m_force"));
        m_force->setMinimumSize(QSize(120, 40));
        m_force->setMinimum(1);
        m_force->setMaximum(10);
        m_force->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(m_force);

        maxForceLabel = new QLabel(layoutWidget);
        maxForceLabel->setObjectName(QStringLiteral("maxForceLabel"));

        horizontalLayout_2->addWidget(maxForceLabel);


        gridLayout_3->addLayout(horizontalLayout_2, 3, 0, 1, 2);

        m_removeFood = new QPushButton(layoutWidget);
        m_removeFood->setObjectName(QStringLiteral("m_removeFood"));
        m_removeFood->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(m_removeFood, 11, 1, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_9, 10, 0, 1, 2);

        label_4 = new QLabel(tab_1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 560, 81, 16));
        m_currentBoidCount = new QLabel(tab_1);
        m_currentBoidCount->setObjectName(QStringLiteral("m_currentBoidCount"));
        m_currentBoidCount->setGeometry(QRect(90, 560, 60, 16));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 231, 141));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        m_obstacleType = new QComboBox(gridLayoutWidget);
        m_obstacleType->setObjectName(QStringLiteral("m_obstacleType"));
        m_obstacleType->setMinimumSize(QSize(0, 40));
        m_obstacleType->setFrame(true);

        gridLayout_2->addWidget(m_obstacleType, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        m_addObstacle = new QPushButton(gridLayoutWidget);
        m_addObstacle->setObjectName(QStringLiteral("m_addObstacle"));
        m_addObstacle->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(m_addObstacle);

        m_removeObstacle = new QPushButton(gridLayoutWidget);
        m_removeObstacle->setObjectName(QStringLiteral("m_removeObstacle"));
        m_removeObstacle->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(m_removeObstacle);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, -1, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(0, 40));

        horizontalLayout_7->addWidget(label_6);

        m_obstacleSize = new QSlider(gridLayoutWidget);
        m_obstacleSize->setObjectName(QStringLiteral("m_obstacleSize"));
        m_obstacleSize->setMinimumSize(QSize(120, 40));
        m_obstacleSize->setMinimum(1);
        m_obstacleSize->setMaximum(100);
        m_obstacleSize->setSliderPosition(1);
        m_obstacleSize->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(m_obstacleSize);

        m_obstacleSizeText = new QLabel(gridLayoutWidget);
        m_obstacleSizeText->setObjectName(QStringLiteral("m_obstacleSizeText"));

        horizontalLayout_7->addWidget(m_obstacleSizeText);


        gridLayout_2->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        m_obstacleType->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Flocker", 0));
        m_quit->setText(QApplication::translate("MainWindow", "Quit", 0));
        label_8->setText(QApplication::translate("MainWindow", "Predator", 0));
        label_5->setText(QApplication::translate("MainWindow", "Speed", 0));
        m_leader->setText(QApplication::translate("MainWindow", "Leader", 0));
        m_newFlock->setText(QApplication::translate("MainWindow", "New Flock", 0));
        label->setText(QApplication::translate("MainWindow", "Alignment", 0));
        maxVelLabel->setText(QApplication::translate("MainWindow", "0", 0));
        label_7->setText(QApplication::translate("MainWindow", "Boid", 0));
        m_removeBoid->setText(QApplication::translate("MainWindow", "-", 0));
        m_addFood->setText(QApplication::translate("MainWindow", "+", 0));
        m_removePredator->setText(QApplication::translate("MainWindow", "-", 0));
        m_addPredator->setText(QApplication::translate("MainWindow", "+", 0));
        m_addBoid->setText(QApplication::translate("MainWindow", "+", 0));
        label_3->setText(QApplication::translate("MainWindow", "Cohesion", 0));
        viewRadiusLabel->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "Separation", 0));
        maxForceLabel->setText(QApplication::translate("MainWindow", "0", 0));
        m_removeFood->setText(QApplication::translate("MainWindow", "-", 0));
        label_9->setText(QApplication::translate("MainWindow", "Food", 0));
        label_4->setText(QApplication::translate("MainWindow", "Boid count : ", 0));
        m_currentBoidCount->setText(QApplication::translate("MainWindow", "100", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Flock", 0));
        m_addObstacle->setText(QApplication::translate("MainWindow", "Add Obstacle", 0));
        m_removeObstacle->setText(QApplication::translate("MainWindow", "Remove Obstacle", 0));
        label_6->setText(QApplication::translate("MainWindow", "Size :", 0));
        m_obstacleSizeText->setText(QApplication::translate("MainWindow", "1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Obstacles", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
