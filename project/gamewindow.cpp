#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ball.h"
#include "stick.h"
#include <QRectF>
#include <QWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>


// shtanga
const int bar = 40;
const int WIN_SCORE = 7;

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



    left_stick = new stick(0); //creating sticks
    right_stick = new stick(1);

     myBall = new ball();

    ui->menuBar->setGeometry(QRect(0, 0, 800, 25));
    ui->graphicsView->setGeometry(QRect(20, 40, 760, 420));
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

    ui->lcdNumber->setGeometry(QRect(300, 10, 64, 23));
    ui->lcdNumber->setPalette(Qt::black);
    ui->lcdNumber_2->setGeometry(QRect(400, 10, 64, 23));
    ui->lcdNumber_2->setPalette(Qt::black);

    connect(myBall, SIGNAL(left_value_changed()), this, SLOT(right_display()));
    connect(myBall, SIGNAL(right_value_changed()), this, SLOT(left_display()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), gameScene, SLOT(advance()));
    timer->start(10);

}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::start_new_game(int winner)
{
    if (winner == 0)
    {
        QMessageBox* pmbx = new QMessageBox("The right player is winner!",
                            "Start new game?",
                            QMessageBox::Information,
                            QMessageBox::Yes,
                            QMessageBox::No,
                            QMessageBox::Cancel);
        int n = pmbx->exec();
        delete pmbx;
        if (n == QMessageBox::Yes)
        {
            ui->lcdNumber->display(0);
            ui->lcdNumber_2->display(0);
        }
        else if (n == QMessageBox::No)
            qApp->exit();
        else
            myBall->setSpeed();
    }
    else if (winner == 1)
    {
        QMessageBox* pmbx = new QMessageBox("The left player is winner!",
                            "Start new game?",
                            QMessageBox::Information,
                            QMessageBox::Yes,
                            QMessageBox::No,
                            QMessageBox::Cancel);
        int n = pmbx->exec();
        delete pmbx;
        if (n == QMessageBox::Yes)
        {
            ui->lcdNumber->display(0);
            ui->lcdNumber_2->display(0);
        }
        else if (n == QMessageBox::No)
            qApp->exit();
        else
            myBall->setSpeed();
    }
    else
    {
        myBall->remember_speed();
        myBall->stopSpeed();
        QMessageBox* pmbx = new QMessageBox("Welcome to Hockey 3002",
                            "Start new game?",
                            QMessageBox::Information,
                            QMessageBox::Yes,
                            QMessageBox::No,
                            QMessageBox::Cancel);
        int n = pmbx->exec();
        delete pmbx;
        if (n == QMessageBox::Yes)
        {
            ui->lcdNumber->display(0);
            ui->lcdNumber_2->display(0);
            myBall->setSpeed();
            myBall->setPos(300, 200);
        }
        else if (n == QMessageBox::No)
            qApp->exit();
        else
            myBall->installTempSpeed();
    }
}

void gameWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void gameWindow::left_display()
{
    ui->lcdNumber->display(ui->lcdNumber->value()+1);
    if (ui->lcdNumber->value() == WIN_SCORE)
        start_new_game(0);
}

void gameWindow::right_display()
{
    ui->lcdNumber_2->display(ui->lcdNumber_2->value()+1);
    if (ui->lcdNumber_2->value() == WIN_SCORE)
        start_new_game(1);
}

void gameWindow::keyPressEvent(QKeyEvent *event)
{
    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
    int k = keyEvent->key();

    switch(k)
    {
        case Qt::Key_W:
            flag_w = 1;
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

    key_event();
}

void gameWindow::keyReleaseEvent(QKeyEvent *event)
{
    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
    int k = keyEvent->key();

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

void gameWindow::key_event()
{
    if (flag_w && left_stick->pos().y() > bar)
        left_stick->move_up(1);
    if (flag_s && left_stick->pos().y() < 345-bar)
        left_stick->move_down(1);
    if (flag_o && right_stick->pos().y() > bar)
        right_stick->move_up(1);
    if (flag_l && right_stick->pos().y() < 345-bar)
        right_stick->move_down(1);
}

void gameWindow::on_actionStart_playing_triggered()
{
    this->start_new_game(-1);
}
