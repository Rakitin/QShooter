#pragma once

#include <QPainter>

class IObject
{
public:
    virtual void draw(QPainter &painter) const = 0;
};
