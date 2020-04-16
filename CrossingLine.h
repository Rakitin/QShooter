#pragma once

#include <QLine>
#include <QPoint>

bool isCrossingLine(QLineF segment1, QLineF segment2, QPointF& point);
