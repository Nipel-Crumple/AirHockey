#ifndef BALL_H
#define BALL_H
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

class ball: public QGraphicsEllipseItem
{
public:
    ball(QGraphicsScene *scene);
    QBrush redBrush;
    QPen blackpen;
};

#endif // BALL_H
