#include <cmath>
#include "CrossingLine.h"


static int sign(double number)
{
    return number >= 0 ? 1 : -1;
}

static double cross(QPointF p1, QPointF p2)
{
    return p1.x()*p2.y() - p1.y()*p2.x();
}

bool isCrossingLine(QLineF segment1, QLineF segment2, QPointF &point)
{
    QPointF cut1 = segment1.p2() - segment1.p1();
    QPointF cut2 = segment2.p2() - segment2.p1();

    double prod1 = cross(cut1, (segment2.p1() - segment1.p1()));
    double prod2 = cross(cut1, (segment2.p2() - segment1.p1()));

    if(sign(prod1) == sign(prod2) || (prod1 == 0) || (prod2 == 0))
        return false;

    prod1 = cross(cut2, (segment1.p1() - segment2.p1()));
    prod2 = cross(cut2, (segment1.p2() - segment2.p1()));

    if(sign(prod1) == sign(prod2) || (prod1 == 0) || (prod2 == 0))
        return false;

    point.setX(segment1.p1().x() + cut1.x() * std::abs(prod1) / std::abs(prod2 - prod1));
    point.setY(segment1.p1().y() + cut1.y() * std::abs(prod1) / std::abs(prod2 - prod1));

    return true;
}
