#include "ball.h"

ball::ball()
{
    //set speed

    speed_x = -0.5;
    speed_y = 5;
    //start position
    int StartX = 100;
    int StartY = 200;

    setPos(mapToParent(StartX, StartY));
}

QRectF ball::boundingRect() const
{
    return QRect(0,0,30,30);
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

    QPointF location = this->pos();

    setPos(mapToParent(-(speed_x),-(speed_y)));
}

void ball::doCollision()
{
    //Set a new position

    setRotation(rotation()+180); //HZ
    //see bydlo position
    QPointF newpoint = mapToParent(-(boundingRect().width()+speed_x), -(boundingRect().width()+speed_y));
    // QPointF newpoint_X = mapToParent(-(boundingRect().width()+1), -(boundingRect().width()));
    if (scene()->sceneRect().contains(newpoint))
    {
        setPos(newpoint);
        rev_speed_x();
    }

}

void ball::rev_speed_x()
{
    speed_x = (-1)*speed_x;
}

void ball::rev_speed_y()
{
    speed_y = (-1)*speed_y;
}
