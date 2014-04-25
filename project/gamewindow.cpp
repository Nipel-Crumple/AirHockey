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
    gameScene->setSceneRect(0, 0, 780, 450);

//    myBall->ellipse = gameScene->addEllipse(QRectF(390,225,12,20), myBall->blackpen, myBall->redBrush);
//    myBall->ellipse->setFlag(QGraphicsItem::ItemIsMovable);

    QPen myPen = QPen(Qt::blue);

    QLineF TopLine(gameScene->sceneRect().topLeft(), gameScene->sceneRect().topRight());
    QLineF LeftLine(gameScene->sceneRect().topLeft(), gameScene->sceneRect().bottomLeft());
    QLineF RightLine(gameScene->sceneRect().topRight(), gameScene->sceneRect().bottomRight());
    QLineF BottomLine(gameScene->sceneRect().bottomLeft(), gameScene->sceneRect().bottomRight());

    gameScene->addLine(TopLine,myPen);                  //box of playing game
    gameScene->addLine(LeftLine,myPen);
    gameScene->addLine(RightLine,myPen);
    gameScene->addLine(BottomLine,myPen);

    int ItemCount = 1;
    for (int i = 0; i < ItemCount; i++)         //how many item
    {
        ball *myBall = new ball();
        gameScene->addItem(myBall);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), gameScene, SLOT(advance()));
    timer->start(100);
}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_actionExit_triggered()
{
    qApp->exit();
}
