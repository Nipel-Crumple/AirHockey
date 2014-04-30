#include "ball.h"

ball::ball()
{
    //set speed

    speed = 1;
    //start position
    int StartX = 200;
    int StartY = 300;

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

    setPos(mapToParent(-(speed),-(speed)));
}

void ball::doCollision()
{
    //Set a new position

    //change the angle randomness
//    if ((qrand() % 1))
//    {
//        setRotation(rotation() + (180 - (qrand() % 100)));
//    }
//    else
//    {
//        setRotation(rotation() + (180 + (qrand() % 100)));
//    }

    setRotation(rotation()+45); //HZ
    //see bydlo position
    QPointF newpoint_Y = mapToParent(-(boundingRect().width() +3), -(boundingRect().width()+3));
   // QPointF newpoint_X = mapToParent(-(boundingRect().width()+1), -(boundingRect().width()));
    if (scene()->sceneRect().contains(newpoint_Y))
    {
        setPos(newpoint_Y);
    }

}
