#include <QPolygon>
#include <QBrush>
#include "Object.h"

Object::Object(QVector<QPoint> points, QPoint position) :
    m_points(points),
    m_position(position)
{

}

void Object::draw(QPainter &painter) const
{
    QPolygon polygon;
    for(auto it = m_points.constBegin(); it < m_points.constEnd(); ++it) {
        polygon << (*it);
    }

    QBrush brush(QColor(255, 0, 0));
    painter.setBrush(brush);
    painter.drawPolygon(polygon);
}

