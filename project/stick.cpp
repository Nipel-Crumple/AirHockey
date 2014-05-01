#include "stick.h"

stick::stick()
{
    int StartX = 0;
    int StartY = 195;
    setPos(mapToParent(StartX, StartY));
}
QRectF stick::boundingRect() const
{
    return QRect(0,0,20,50);
}

void stick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush Brush(Qt::black);

    painter->setBrush(Brush);
    painter->drawRect(rect);

}
