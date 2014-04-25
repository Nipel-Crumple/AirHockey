#ifndef BALL_H
#define BALL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QRectF>

class ball : public QGraphicsItem
{
public:
    ball();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
    void doCollision();
};

#endif // BALL_H
