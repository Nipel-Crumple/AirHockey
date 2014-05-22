#ifndef BALL_H
#define BALL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QRectF>
#include <QObject>
#include <QTimer>

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
    QTimer *timer_x;
    QTimer *timer_y;
    qreal angle;
    qreal speed_x;
    qreal speed_y;
    int flag_x;
    int flag_y;

signals:
    void left_value_changed();
    void right_value_changed();

public slots:
    void set_flag_x();
    void set_flag_y();
};

#endif // BALL_H
