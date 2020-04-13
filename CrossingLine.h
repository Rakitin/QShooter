#pragma once

#include <QPair>
#include <QPoint>

bool isCrossingLine(QPair<QPointF, QPointF> segment1, QPair<QPointF, QPointF> segment2, QPointF& point);
