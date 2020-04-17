#include <cmath>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include "CrossingLine.h"
#include "Object.h"
#include "Camera.h"

static const double FIELD_OF_VIEW = 90.0;
static const size_t COUNT_OF_RAY = 300;
static const double DEPTH = 10.0;


//static double radToDeg(double a)
//{
//    return (180.0 * a) / M_PI;
//}

static double degToRad(double a)
{
    return a * (M_PI / 180.0);
}


Camera::Camera(World &world, QPointF position, double direction) :
    m_world(world),
    m_position(position),
    m_direction(direction),
    m_rays(COUNT_OF_RAY)
{
}

void Camera::draw(QPainter &painter) const
{
    //    qDebug() << __FILE__ << __FUNCTION__;
    int d = 2;
    painter.setPen(QPen(Qt::yellow));
    painter.setBrush(QBrush(Qt::yellow));
    painter.drawEllipse(QRect(m_position.x() * 10 - d/2, m_position.y() * 10 - d/2, d, d));

    painter.setPen(QPen(Qt::blue));
    for(size_t i = 0; i < COUNT_OF_RAY; i++) {
        painter.drawLine(m_rays[i].seg.x1() * 10,
                         m_rays[i].seg.y1() * 10,
                         m_rays[i].seg.x2() * 10,
                         m_rays[i].seg.y2() * 10);
    }
}

void Camera::drawView(QPainter &painter) const
{
    QRect viewport = painter.viewport();
    double width = viewport.width() / COUNT_OF_RAY + 1;
    double height = viewport.height();

    for(size_t i = 0; i < COUNT_OF_RAY; i++)
    {
        if(m_rays[i].distance == -1) continue;
        QRectF rect;

        double y1 = (height / 2.0) * (1.0 - (1.0 / m_rays[i].distance));
        double y2 = (height / 2.0) * (1.0 + (1.0 / m_rays[i].distance));

        rect.setX(width * i);
        rect.setY(y1);
        rect.setWidth(width);
        rect.setHeight(y2 - y1);

        int rgb = 255 - (m_rays[i].distance / (DEPTH / 100)) * 2.55;
        QColor color(rgb, rgb, rgb);

        painter.setPen(color);
        painter.setBrush(QBrush(color));
        painter.drawRect(rect);

    }
}

void Camera::moveForward()
{
    double dx = 0.2 * cos(m_direction);
    double dy = 0.2 * sin(m_direction);
    m_position.setX(m_position.x() + dx);
    m_position.setY(m_position.y() + dy);
    update();
}

void Camera::moveBack()
{
    double dx = 2 * (-cos(m_direction));
    double dy = 2 * (-sin(m_direction));
    m_position.setX(m_position.x() + dx);
    m_position.setY(m_position.y() + dy);
    update();
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
    update();
}

void Camera::turnRight()
{
    m_direction += degToRad(1.0);
    //    qDebug() << "direction:" << radToDeg(m_direction);
    update();
}

void Camera::update()
{
    double fieldOfView = degToRad(FIELD_OF_VIEW);
    double step = fieldOfView / COUNT_OF_RAY;
    double start = m_direction - (fieldOfView / 2);

    for(size_t i = 0; i < COUNT_OF_RAY; i++)
    {
        m_rays[i].distance = -1;

        QPointF rayEnd(m_position.x() + DEPTH * cos(start + (i * step)),
                       m_position.y() + DEPTH * sin(start + (i * step)));
        m_rays[i].seg = QLineF(m_position, rayEnd);

        for(auto obj = m_world.objects().constBegin(); obj < m_world.objects().constEnd(); ++obj)
        {
            for(auto point = (*obj)->points().constBegin(); point < (*obj)->points().constEnd(); ++point)
            {
                QPointF point2;
                if((point + 1)==(*obj)->points().constEnd())
                    point2 = *(*obj)->points().constBegin();
                else
                    point2 = *(point + 1);
                QLineF seg((*point), point2);
                QPointF crossingPoint;

                if(isCrossingLine(m_rays[i].seg, seg, crossingPoint))
                {
                    m_rays[i].distance = sqrt(pow(crossingPoint.x() - m_position.x(), 2.0) +
                                              pow(crossingPoint.y() - m_position.y(), 2.0));
                    m_rays[i].seg = QLineF(m_position, crossingPoint);
                }
            }
        }
    }
}
