#include <QPolygon>
#include <QPen>
#include <QBrush>
#include "Object.h"

Object::Object(QVector<QPointF> points) :
    m_points(points)
{

}

void Object::draw(QPainter &painter) const
{
    QPolygon polygon;
    for(auto it = m_points.constBegin(); it < m_points.constEnd(); ++it) {
        polygon << (*it).toPoint() * 10;
    }

    painter.setPen(QPen(Qt::red));
    painter.setBrush(QBrush(Qt::red));
    painter.drawPolygon(polygon);
}

const QVector<QPointF> Object::points() const
{
    return m_points;
}
