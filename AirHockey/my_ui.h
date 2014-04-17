/********************************************************************************
** Form generated from reading UI file 'hockey.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOCKEY_H
#define UI_HOCKEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QIcon>


QT_BEGIN_NAMESPACE

class Ui_Hockey
{
public:
    QWidget *centralWidget;
    QAction *actionNew;
    QPushButton *play;
    QPushButton *exit;
    QMenuBar *menuBar;
    QMenu *menufile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QIcon icon;
    QWidget *horizontalWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *gameField;
    QLayout *layout;

    void setupUi(QMainWindow *Hockey)
    {
        if (Hockey->objectName().isEmpty())
            Hockey->setObjectName(QStringLiteral("Hockey"));
        Hockey->resize(900, 600);

        centralWidget = new QWidget(Hockey);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        //centralWidget->setStyleSheet("background-image: url(:/mainback.jpg); background-origin: 400px 300px;");

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 900, 50));
        horizontalLayoutWidget->setStyleSheet("background-color: white");

        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        play = new QPushButton(horizontalLayoutWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(0,0,100,100));
        play->setText(QStringLiteral("PLAY"));
        play->setStyleSheet(QStringLiteral("height: 60; background-color: grey"));
        horizontalLayout->addWidget(play);

        exit = new QPushButton(horizontalLayoutWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(0, 0, 100, 100));
        exit->setText(QStringLiteral("EXIT"));
        exit->setStyleSheet(QStringLiteral("height: 60; background-color: grey"));
        horizontalLayout->addWidget(exit);


        gameField = new QWidget(Hockey);
        gameField->setObjectName(QStringLiteral("gameField"));
        gameField->setGeometry(QRect(0, 60, 900, 540));
        gameField->setStyleSheet("background-color: limegreen");



        Hockey->setCentralWidget(centralWidget);

        //Hockey->setStyleSheet("background-color: limegreen");

//        play = new QPushButton(verticalWidget);
//        play->setObjectName(QStringLiteral("play"));
//        verticLayout->addWidget(play);
//        Hockey->setCentralWidget(centralWidget);
//        menuBar = new QMenuBar(Hockey);
//        menuBar->setObjectName(QStringLiteral("menuBar"));
//        menuBar->setGeometry(QRect(20, 20, 20, 20));
//
//        actionNew = new QAction(Hockey);
//        actionNew->setIcon(icon);
//        actionNew->setText("&Huilo");
//        menufile = new QMenu(menuBar);
//        menufile->setTitle("&File");
//        menufile->addAction(actionNew);
//        menuBar->addAction(menufile->menuAction());

//        Hockey->setMenuBar(menuBar);
//        mainToolBar = new QToolBar(Hockey);
//        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
//        Hockey->addToolBar(Qt::TopToolBarArea, mainToolBar);
//        statusBar = new QStatusBar(Hockey);
//        statusBar->setObjectName(QStringLiteral("statusBar"));
//        Hockey->setStatusBar(statusBar);

        retranslateUi(Hockey);

        QMetaObject::connectSlotsByName(Hockey);
    } // setupUi

    void retranslateUi(QMainWindow *Hockey)
    {
        Hockey->setWindowTitle(QApplication::translate("Hockey", "Hockey", 0));
    } // retranslateUi

};

namespace Ui {
    class Hockey: public Ui_Hockey {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOCKEY_H
