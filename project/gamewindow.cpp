#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ball.h"
#include <QRectF>

gameWindow::gameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);

    gameScene = new QGraphicsScene(this);

    ball *myBall;                   //creating ball
    myBall = new ball();

    ui->graphicsView->setScene(gameScene);
    myBall->ellipse = gameScene->addEllipse(QRectF(10.0,10.0,12,20), myBall->blackpen, myBall->redBrush);
    myBall->ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    myBall->ellipse->setPos(12, 12);
}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_actionExit_triggered()
{
    qApp->exit();
}
