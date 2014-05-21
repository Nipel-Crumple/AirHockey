#ifndef BALL_H
#define BALL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QRectF>
#include <QObject>

class ball : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    ball();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void rev_speed_x();
    void rev_speed_y();
    void stopSpeed();
    void remember_speed();
    void installTempSpeed();
    void setSpeed();
    void doCollision();
    qreal tempSpeed_x;
    qreal tempSpeed_y;

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed_x;
    qreal speed_y;


signals:
    void left_value_changed();
    void right_value_changed();
};

#endif // BALL_H
