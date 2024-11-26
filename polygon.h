#pragma once
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include <allegro5/allegro.h>

void drawPolygon(const std::vector<Point2D>& vertices, PrimitiveRenderer& renderer);