#ifndef BALL_H
#define BALL_H
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

class ball
{
public:
    ball();
    QBrush redBrush;
    QPen blackpen;
    QGraphicsEllipseItem *ellipse;
};

#endif // BALL_H
