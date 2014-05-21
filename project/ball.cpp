#include "ball.h"
#include "gamewindow.h"
#include <QDebug>


void ball::setSpeed()
{
    //set speed
    speed_x = 1;
    speed_y = 1;
}

ball::ball()
{
    //start position
    int StartX = 200;
    int StartY = 100;
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
//    qDebug() << "location_X" << this->x();
//    qDebug() << "location_Y" << this->y();
    //basic Collision detection
    if (!scene()->collidingItems(this).isEmpty())
    {
        //set the new position
        qDebug() << scene()->collidingItems(this);
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
        setSpeed();
        setPos(400, 200);
    } else
    if (pos_x >= 760)
    {
        emit right_value_changed();
        setSpeed();
        setPos(300, 200);
    } else
        setPos(mapToParent(-(speed_x),-(speed_y)));
}

int ball::doCollision()
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
    QPointF location = this->pos();
    //qDebug() << location.y();
    //qDebug() << location.x();
//    if (this->collidesWithItem(gameWindow.left_stick, Qt::IntersectsItemShape))
//        stopSpeed();

    if ((location.y() > 377) || (location.y() < 0))     //top and bottom border
    {
        rev_speed_y();
    }

    if ((location.x() < 0) || (location.x() > 720))     //left and right
    {
        rev_speed_x();
    }





//    //set a new position
//    setRotation(rotation()+180);
//    QPointF newpoint_y;
//    QPointF newpoint_x;

//    //reverse speed because of hit
//    if (speed_x >= 0)
//    {
//       newpoint_y = mapToParent(-boundingRect().width(), -(boundingRect().width()+speed_y));
//       newpoint_x = mapToParent(-(boundingRect().width()+speed_x), -boundingRect().width());
//    }

//    if (scene()->sceneRect().contains(newpoint_y))
//    {
//        setPos(newpoint_y);
//        rev_speed_x();
//        return 0;
//    }

//    if (scene()->sceneRect().contains(newpoint_x))
//    {
//        setPos(newpoint_x);
//        qDebug() << "x = " << speed_x;
//        rev_speed_y();
//         qDebug() << "x = " << speed_x;
//        return 0;
//    }



}

void ball::rev_speed_x()
{
    speed_x = (-1)*(speed_x + speed_x/8);

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
