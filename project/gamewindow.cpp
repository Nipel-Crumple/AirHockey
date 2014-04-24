#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ball.h"

gameWindow::gameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);

    gameScene = new QGraphicsScene(this);
    ball *myBall;

    myBall = new ball();

    ui->graphicsView->setScene(gameScene);
    myBall->ellipse = gameScene->addEllipse(10,10,13,13, myBall->blackpen, myBall->redBrush);
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
