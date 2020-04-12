#include <cmath>
#include <QDebug>
#include <QBrush>
#include "Object.h"
#include "Camera.h"

static const double fieldOfView = M_PI/2;
static const double depth = 25;


Camera::Camera(World &world, QPoint position, double direction) :
    m_world(world),
    m_position(position),
    m_direction(direction)
{

}

void Camera::draw(QPainter &painter) const
{
//    qDebug() << __FILE__ << __FUNCTION__;
    QBrush brush(Qt::yellow);
    painter.setBrush(brush);
    int d = 10;
    painter.drawEllipse(QRect(m_position.x() - d/2, m_position.y() - d/2, d, d));


//    painter.drawLine()
}

void Camera::moveForward()
{

}

void Camera::moveBack()
{

}

void Camera::moveLeft()
{

}

void Camera::moveRight()
{

}

void Camera::turnLeft()
{

}

void Camera::turnRight()
{

}

