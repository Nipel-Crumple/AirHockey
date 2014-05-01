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



    QPen myPen = QPen(Qt::black);

    QPointF left_border_top, left_border_bottom, right_border_top, right_border_bottom;
    left_border_top.setY(20);
    left_border_top.setX(0);
    left_border_bottom.setY(420);
    left_border_bottom.setX(0);

    right_border_top.setY(20);
    right_border_top.setX(780);
    right_border_bottom.setY(420);
    right_border_bottom.setX(780);


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
