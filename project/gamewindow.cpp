#include "gamewindow.h"
#include "ui_gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);

    gameScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(gameScene);

    QBrush redBrush(Qt::red);

    QPen blackpen(Qt::black);
    blackpen.setWidth(2);

    ball = gameScene->addEllipse(10,10,13,13,blackpen,redBrush);
    ball->setFlag(QGraphicsItem::ItemIsMovable);
}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_actionExit_triggered()
{
    qApp->exit();
}
