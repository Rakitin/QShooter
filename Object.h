#pragma once

#include <QPoint>
#include <QVector>


class Object
{
public:
    Object(QPoint position = {0, 0});

private:
    QVector<QPoint> m_points;
    QPoint m_position;
};
