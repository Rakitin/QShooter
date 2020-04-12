#pragma once

#include <QPoint>
#include <QPainter>
#include "IObject.h"
#include "World.h"

class Camera : public IObject
{
public:
    Camera(World &world, QPointF position = {100.0, 100.0}, double direction = 0);
    void draw(QPainter &painter) const;

    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();
    void turnLeft();
    void turnRight();


private:
    World &m_world;
    QPointF m_position;
    double m_direction;

};
