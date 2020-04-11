#pragma once

#include <QPoint>
#include <QVector>
#include <QPainter>
#include "IObject.h"


class Object : public IObject
{
public:
    Object(QVector<QPoint> points = {}, QPoint position = {0, 0});
    void draw(QPainter &painter) const;

private:
    QVector<QPoint> m_points;
    QPoint m_position;
};
