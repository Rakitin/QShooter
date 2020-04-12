#pragma once

#include <QPoint>
#include <QVector>
#include <QPainter>
#include "IObject.h"


class Object : public IObject
{
public:
    Object(QVector<QPointF> points = {}, QPointF position = {0.0, 0.0});
    void draw(QPainter &painter) const;

private:
    QVector<QPointF> m_points;
    QPointF m_position;
};
