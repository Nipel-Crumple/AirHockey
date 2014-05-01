#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ball.h"
#include "stick.h"
#include <QRectF>

gameWindow::gameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);

    gameScene = new QGraphicsScene(this);

    ball *myBall;                   //creating ball
    myBall = new ball();

    stick *left_stick;              //creating left stick
    left_stick = new stick();

    ui->graphicsView->setScene(gameScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);        //quality of picture
    gameScene->setSceneRect(0, 0, 780, 440);

//    myBall->ellipse = gameScene->addEllipse(QRectF(390,225,12,20), myBall->blackpen, myBall->redBrush);
//    myBall->ellipse->setFlag(QGraphicsItem::ItemIsMovable);

    QPen myPen = QPen(Qt::black);

    QPointF lenght_Y;
    lenght_Y.setY(20);

    QPointF

    QLineF TopLine(gameScene->sceneRect().topLeft(), gameScene->sceneRect().topRight());
    QLineF LeftLineTop(gameScene->sceneRect().topLeft(), lenght_Y);
  //QLineF RightLine(gameScene->sceneRect().topRight(), gameScene->sceneRect().bottomRight());
    QLineF BottomLine(gameScene->sceneRect().bottomLeft(), gameScene->sceneRect().bottomRight());

    gameScene->addLine(TopLine,myPen);                  //box of playing game
    gameScene->addLine(LeftLine,myPen);

    gameScene->addLine(RightLine,myPen);
    gameScene->addLine(BottomLine,myPen);

    //filling objects

    gameScene->addItem(myBall);
    gameScene->addItem(left_stick);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), gameScene, SLOT(advance()));
    timer->start(10);
}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_actionExit_triggered()
{
    qApp->exit();
}
