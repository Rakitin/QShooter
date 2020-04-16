#pragma once

#include <QPainter>

class IObject
{
public:
    virtual void draw(QPainter &painter) const = 0;
    virtual const QVector<QPointF> points() const = 0;
};
