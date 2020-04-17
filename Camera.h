#pragma once

#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QLine>
#include "IObject.h"
#include "World.h"


class Camera
{
public:
    Camera(World &world, QPointF position = {10.0, 10.0}, double direction = 0);
    void draw(QPainter &painter) const;
    void drawView(QPainter &painter) const;
    void update();
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

    struct Ray
    {
        double distance;
        QLineF seg;
    };

    QVector<Ray> m_rays;


};
