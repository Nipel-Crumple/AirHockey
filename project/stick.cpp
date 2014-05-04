#include "stick.h"

stick::stick()
{
    int StartX = -5;
    int StartY = 165;
    setPos(mapToParent(StartX, StartY));
}

QRectF stick::boundingRect() const
{
    return QRect(0,0,5,50);
}

void stick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush Brush(Qt::black);

    painter->setBrush(Brush);
    painter->drawRect(rect);

}

void stick::move_up(int phase)
{
    if (!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0,-5));
}

void stick::move_down(int phase)
{
}
