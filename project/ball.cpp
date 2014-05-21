#include "ball.h"
#include "gamewindow.h"
#include <QDebug>
#include <time.h>
const int SCALER = 8;
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

        rev_speed_y();

    }

    if ((location.x() < 0) || (location.x() > 720))     //left and right
    {
        rev_speed_x();
    }

}

void ball::rev_speed_x()
{
    speed_x = (-1)*(speed_x + speed_x/SCALER);

}

void ball::rev_speed_y()
{
    //qDebug() << speed_y;
    speed_y = (-1)*speed_y;
    //qDebug() << speed_y;
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
