#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ball.h"
#include "stick.h"
#include <QRectF>
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>

// shtanga
const int bar = 50;

gameWindow::gameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameWindow)
{
    flag_w = 0;
    flag_s = 0;
    flag_o = 0;
    flag_l = 0;
    ui->setupUi(this);

    gameScene = new QGraphicsScene(this);

    ball *myBall;                   //creating ball
    myBall = new ball();

    left_stick = new stick(0); //creating sticks
    right_stick = new stick(1);

    ui->graphicsView->setScene(gameScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);        //quality of picture
    gameScene->setSceneRect(0, 0, this->width()-60, this->height()-80);

    QPen myPen = QPen(Qt::black);

    QPointF left_border_top, left_border_bottom, right_border_top, right_border_bottom;
    left_border_top.setY(bar);
    left_border_top.setX(0);
    left_border_bottom.setY(this->height()-80-bar);
    left_border_bottom.setX(0);

    right_border_top.setY(bar);
    right_border_top.setX(this->width()-60);
    right_border_bottom.setY(this->height()-80-bar);
    right_border_bottom.setX(this->width()-60);


    QLineF TopLine(gameScene->sceneRect().topLeft(), gameScene->sceneRect().topRight());
    QLineF LeftLineTop(gameScene->sceneRect().topLeft(), left_border_top);
    QLineF LeftLineBottom(gameScene->sceneRect().bottomLeft(), left_border_bottom);
    QLineF RightLineTop(gameScene->sceneRect().topRight(), right_border_top);
    QLineF RightLineBottom(gameScene->sceneRect().bottomRight(), right_border_bottom);
    QLineF BottomLine(gameScene->sceneRect().bottomLeft(), gameScene->sceneRect().bottomRight());

    gameScene->addLine(TopLine,myPen);                  //box of playing game
    gameScene->addLine(LeftLineTop,myPen);
    gameScene->addLine(LeftLineBottom,myPen);
    gameScene->addLine(RightLineTop,myPen);
    gameScene->addLine(RightLineBottom,myPen);  
    gameScene->addLine(BottomLine,myPen);

    //filling objects

    gameScene->addItem(myBall);
    gameScene->addItem(left_stick);
    gameScene->addItem(right_stick);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), gameScene, SLOT(advance()));
    timer->start(1);

}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void gameWindow::keyPressEvent(QKeyEvent *event)
{
    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
    int k = keyEvent->key();

    // chose movement usin keyevents
    if(1) // add execution condition
    {
        switch(k)
        {
            case Qt::Key_W:
                flag_w=1;
                break;

            case Qt::Key_S:
                flag_s=1;
                break;

            case Qt::Key_O:
                flag_o=1;
                break;

            case Qt::Key_L:
                flag_l=1;
                break;
        }
    }

    key_event();
}

void gameWindow::keyReleaseEvent(QKeyEvent *event)
{
    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
    int k = keyEvent->key();

    if(1) // add execution condition
    {
        switch(k)
        {
            case Qt::Key_W:
                flag_w=0;
                break;

            case Qt::Key_S:
                flag_s=0;
                break;

            case Qt::Key_O:
                flag_o=0;
                break;

            case Qt::Key_L:
                flag_l = 0;
                break;
        }
    }
}

void gameWindow::key_event()
{
    if (flag_w == 1)
        left_stick->move_up(1);
    if (flag_s == 1)
        left_stick->move_down(1);
    if (flag_o == 1)
        right_stick->move_up(1);
    if (flag_l == 1)
        right_stick->move_down(1);
}
