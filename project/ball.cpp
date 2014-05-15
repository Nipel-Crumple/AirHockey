#include "ball.h"
#include "gamewindow.h"
#include <QDebug>

ball::ball()
{
    //set speed
    speed_x = 2.0;
    speed_y = 0;
    //start position
    int StartX = 200;
    int StartY = 100;

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
    int pos_x = this->pos().x();

    if (pos_x <= -10)
    {
        emit left_value_changed();
        setPos(400, 200);
    } else
    if (pos_x >= 760)
    {
        emit right_value_changed();
        setPos(300, 200);
    } else
        setPos(mapToParent(-(speed_x),-(speed_y)));
}

void ball::doCollision()
{
    /*
      https://qt-project.org/search/tag/collision~detection
      http://qt-project.org/doc/qt-4.7/graphicsview-collidingmice.html#id-63504b08-3dae-4482-8a2d-c636c9b358d7
      http://doc.crossplatform.ru/qt/4.4.3/graphicsview-collidingmice.html
      the third link is the second in russian

      it is something about collisions in qt with example
      i think that we have to rewrite it
      you can see how many times our reverse functions work (thanks to qdebug)
      and another interesting fact: when we want to change speed_x, speed_y is changed.
      so, how does it work?!

      and we also need non-scalable main window. i can't find anything :(
    */


    //set a new position
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
    qDebug() << "x";
    speed_x = (-1)*speed_x;
}

void ball::rev_speed_y()
{
    qDebug() << "y";
    speed_y = (-1)*speed_y;
}
