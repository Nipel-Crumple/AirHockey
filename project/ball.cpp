#include "ball.h"
#include "gamewindow.h"
#include <QDebug>
#include <QTimer>
#include <time.h>

const int SCALER = 8;
const int COLLIS_TIME = 300;
const int X_0 = 345, Y_0 = 190;

void ball::setSpeed()
{
    qsrand(time(NULL));
    //set speed
    if (qrand()%2)
        speed_x = (qrand()%8+8)*0.1;
    else
        speed_x = -(qrand()%8+8)*0.1;

    if (qrand()%2)
        speed_y = (qrand()%8+8)*0.1;
    else
        speed_y = -(qrand()%8+8)*0.1;

    flag_x = 1;
    flag_y = 1;
}

ball::ball()
{
    //start position
    int StartX = X_0;
    int StartY = Y_0;
    setSpeed();
    setPos(mapToParent(StartX, StartY));
}

QRectF ball::boundingRect() const
{
    return QRect(0,0,20,20);
}

void ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush Brush(Qt::red);

    //basic Collision detection
    if (!scene()->collidingItems(this).isEmpty())
    {
        //set the new position
        doCollision();
    }

    painter->setBrush(Brush);
    painter->drawEllipse(rect);
}

void ball::advance(int phase)
{
    if (!phase) return;

    //QPointF location = this->pos();
    int pos_x = this->pos().x();

    if (pos_x <= -10)
    {
        emit left_value_changed();
        setSpeed();
        setPos(X_0, Y_0);
    } else
    if (pos_x >= 760)
    {
        emit right_value_changed();
        setSpeed();
        setPos(X_0, Y_0);
    } else
        setPos(mapToParent(-(speed_x),-(speed_y)));
}

void ball::doCollision()
{
    QPointF location = this->pos();

    if ((location.y() > 377) || (location.y() < 0))     //top and bottom border
    {
        if (flag_y)
        {
            rev_speed_y();
            flag_y = 0;
        }
        timer_y = new QTimer(this);
        connect(timer_y, SIGNAL(timeout()), this, SLOT(set_flag_y()));
        timer_y->start(COLLIS_TIME);
    }

    if ((location.x() < 0) || (location.x() > 720))     //left and right
    {
        if (flag_x)
        {
            rev_speed_x();
            flag_x = 0;
        }
        timer_x = new QTimer(this);
        connect(timer_x, SIGNAL(timeout()), this, SLOT(set_flag_x()));
        timer_x->start(COLLIS_TIME);
    }

}

void ball::rev_speed_x()
{
    speed_x = (-1)*(speed_x + speed_x/SCALER);
    // qDebug() << "x";
}

void ball::rev_speed_y()
{
    speed_y = (-1)*speed_y;
    // qDebug() << "y";
}

void ball::set_flag_x()
{
    flag_x = 1;
}

void ball::set_flag_y()
{
    flag_y = 1;
}

void ball::stopSpeed()
{
    speed_x = 0;
    speed_y = 0;
}

void ball::remember_speed()
{
    tempSpeed_x = speed_x;
    tempSpeed_y = speed_y;
}

void ball::installTempSpeed()
{
    speed_x = tempSpeed_x;
    speed_y = tempSpeed_y;
}
