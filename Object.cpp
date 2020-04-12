#include <QPolygon>
#include <QPen>
#include <QBrush>
#include "Object.h"

Object::Object(QVector<QPointF> points, QPointF position) :
    m_points(points),
    m_position(position)
{

}

void Object::draw(QPainter &painter) const
{
    QPolygon polygon;
    for(auto it = m_points.constBegin(); it < m_points.constEnd(); ++it) {
        polygon << (*it).toPoint();
    }

    painter.setPen(QPen(Qt::red));
    painter.setBrush(QBrush(Qt::red));
    painter.drawPolygon(polygon);
}

