#include "stick.h"

stick::stick()
{
    int StartX = 0;
    int StartY = 195;
    setPos(mapToParent(StartX, StartY));
}
QRectF stick::boundingStick() const
{
    return QRect(0,0,20,50);
}

void stick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingStick();
    QBrush Brush(Qt::red);

    painter->setBrush(Brush);
    painter->drawEllipse(rect);

}
