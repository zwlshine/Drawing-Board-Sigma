#include <QtWidgets>
#include "ellipseplugin.h"

Ellipse::Ellipse()
{
    myShape = ellipse;
}

bool Ellipse::isContains(const QPoint &point)
{
    return QGraphicsEllipseItem(startPoint.x(), startPoint.y(),
                                endPoint.x() - startPoint.x(),
                                endPoint.y() - startPoint.y()).contains(QPointF(point));
}

void Ellipse::paintWith(QPainter &painter)
{
   painter.drawEllipse(startPoint.x(), startPoint.y(),
                                endPoint.x() - startPoint.x(),
                                endPoint.y() - startPoint.y());
}




EllipseFactory::EllipseFactory()
{
    myShape = ellipse;
}

VisualObject *EllipseFactory::create(CurrentShape thisShape)
{
    if (thisShape == myShape)
        return new Ellipse;
    else
        return NULL;
}
