#include "ball.h"
#include <QDebug>

ball::ball()
{
    //set speed
    speed_x = 1;
    speed_y = 1;
    //start position
    int StartX = 100;
    int StartY = 165;

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

    QPointF location = this->pos();

    setPos(mapToParent(-(speed_x),-(speed_y)));
}

void ball::doCollision()
{
    //Set a new position
    setRotation(rotation()+180);
    //reverse speed because of hit
    QPointF newpoint_y = mapToParent(-boundingRect().width(), -(boundingRect().width()+speed_y));
    QPointF newpoint_x = mapToParent(-(boundingRect().width()+speed_x), -boundingRect().width());

    if (scene()->sceneRect().contains(newpoint_y))
    {
        setPos(newpoint_y);
        rev_speed_x();
    } else
    if (scene()->sceneRect().contains(newpoint_x))
    {
        setPos(newpoint_x);
        rev_speed_y();
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
