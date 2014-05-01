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
    void rev_speed_x();
    void rev_speed_y();

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed_x;
    qreal speed_y;
    void doCollision();
};

#endif // BALL_H
