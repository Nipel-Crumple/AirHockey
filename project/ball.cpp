#include "ball.h"

ball::ball(QGraphicsScene *scene)
{
    redBrush = QBrush(Qt::red);
    blackpen = QPen(Qt::black);
    blackpen.setWidth(2);
    scene->addEllipse(10,10,13,13,blackpen,redBrush);
}
