#ifndef STICK_H
#define STICK_H
#include <QBrush>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QRectF>
class stick
{
public:
    stick();
    QRectF boundingStick() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STICK_H
