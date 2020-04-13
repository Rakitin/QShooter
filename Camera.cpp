#include <cmath>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include "Object.h"
#include "Camera.h"

static const double fieldOfView = M_PI/2;
static const double depth = 200;

static double radToDeg(double a)
{
    return (180.0 * a) / M_PI;
}

static double degToRad(double a)
{
    return a * (M_PI / 180.0);
}


Camera::Camera(World &world, QPointF position, double direction) :
    m_world(world),
    m_position(position),
    m_direction(direction)
{

}

void Camera::draw(QPainter &painter) const
{
    //    qDebug() << __FILE__ << __FUNCTION__;
    int d = 10;
    painter.setPen(QPen(Qt::yellow));
    painter.setBrush(QBrush(Qt::yellow));
    painter.drawEllipse(QRect(m_position.x() - d/2, m_position.y() - d/2, d, d));

    painter.setPen(QPen(Qt::blue));

    for(double i = 0.0; i < fieldOfView/2.0; i+=degToRad(5.0))
    {
//        qDebug() << i;
//        qDebug() << fieldOfView/2.0;
        double x;
        double y;

        x = m_position.x() + depth * cos(m_direction - i);
        y = m_position.y() + depth * sin(m_direction - i);
        painter.drawLine(m_position.x(), m_position.y(), x, y);

        x = m_position.x() + depth * cos(m_direction + i);
        y = m_position.y() + depth * sin(m_direction + i);
        painter.drawLine(m_position.x(), m_position.y(), x, y);

    }

}

void Camera::moveForward()
{
    double dx = 2 * cos(m_direction);
    double dy = 2 * sin(m_direction);
    m_position.setX(m_position.x() + dx);
    m_position.setY(m_position.y() + dy);
}

void Camera::moveBack()
{
    double dx = 2 * (-cos(m_direction));
    double dy = 2 * (-sin(m_direction));
    m_position.setX(m_position.x() + dx);
    m_position.setY(m_position.y() + dy);
}

void Camera::moveLeft()
{

}

void Camera::moveRight()
{

}

void Camera::turnLeft()
{
    m_direction -= degToRad(1.0);
//    qDebug() << "direction:" << radToDeg(m_direction);
}

void Camera::turnRight()
{
    m_direction += degToRad(1.0);
//    qDebug() << "direction:" << radToDeg(m_direction);
}

