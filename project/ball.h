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
    int left_value;
    int right_value;
    void doCollision();

signals:
    void left_value_changed();
};

#endif // BALL_H
