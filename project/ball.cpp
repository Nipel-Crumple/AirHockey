#include "ball.h"

ball::ball()
{
    //random start rotation;
//    angle = (qrand() % 360);
//    setRotation(angle);

    //set speed
    speed = 11;
    //random start position
    int StartX = 390;
    int StartY = 200;

//    if ((qrand() % 1))
//    {
//        StartX = (qrand() % 200);
//        StartY = (qrand() % 200);
//    }

//    else
//    {
//        StartX = (qrand() % -100);
//        StartY = (qrand() % -100);
//    }

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

    if (scene()->collidingItems(this).isEmpty())
    {
        //no collision
        Brush.setColor(Qt::green);
    }
    else
    {
        //collision!!!
        Brush.setColor(Qt::red);

        //set the new position
        doCollision();
    }

    painter->fillRect(rect,Brush);
    painter->drawRect(rect);
}

void ball::advance(int phase)
{
    if (!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0,-(speed)));
}

void ball::doCollision()
{
    //Set a new position

    //change the angle randomness
//    if ((qrand() % 1))
//    {
//        setRotation(rotation() + (180 + (qrand() % 100)));
//    }
//    else
//    {
//        setRotation(rotation() + (180 - (qrand() % 100)));
//    }

    setRotation(rotation() + 180);
    //see if the new position is in bounds
    QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width()+10));

    if (!scene()->sceneRect().contains(newpoint))
    {
        //move it back in bounds
        newpoint = mapToParent(0,0);
    }
    else
    {
        //set the new position
        setPos(newpoint);
    }
}
