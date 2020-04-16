#pragma once

#include <QPoint>
#include <QVector>
#include <QPair>
#include <QPainter>
#include "IObject.h"


class Object : public IObject
{
public:
    Object(QVector<QPointF> points = {});
    void draw(QPainter &painter) const;
    const QVector<QPointF> points() const;

private:
    QVector<QPointF> m_points;
};
