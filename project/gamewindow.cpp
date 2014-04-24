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
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);        //quality of picture
    gameScene->setSceneRect(0, 0, 800, 450);

    myBall->ellipse = gameScene->addEllipse(QRectF(400,225,12,20), myBall->blackpen, myBall->redBrush);
    myBall->ellipse->setFlag(QGraphicsItem::ItemIsMovable);
}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_actionExit_triggered()
{
    qApp->exit();
}
