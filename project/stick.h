#ifndef STICK_H
#define STICK_H
#include <QBrush>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QRectF>
class stick: public QGraphicsItem
{
public:
    stick();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STICK_H
