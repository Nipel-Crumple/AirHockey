#include "ball.h"

ball::ball()
{
    redBrush = QBrush(Qt::red);
    blackpen = QPen(Qt::black);
    blackpen.setWidth(2);

    //ellipse = this->addEllipse(10,10,13,13,blackpen,redBrush);
    //ellipse->setFlag(QGraphicsItem::ItemIsMovable);
}
