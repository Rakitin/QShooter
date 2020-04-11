#pragma once

#include <QVector>
#include <QPainter>
#include "IObject.h"


class World
{
public:
    World();
    void add(IObject *object);
    void draw(QPainter &painter) const;


private:
    QVector<IObject *> m_objects;
};
