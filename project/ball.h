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
    void left_value_changed(int new_val);
    void right_value_changed(int new_val);
};

#endif // BALL_H
