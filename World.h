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

    const QVector<IObject *>& objects() const;

private:
    QVector<IObject *> m_objects;
};
