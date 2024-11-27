#pragma once
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include <allegro5/allegro.h>

/**
 * @brief Rysuje wielokąt na podstawie listy wierzchołków.
 * @param vertices Wektor wierzchołków (punktów) wielokąta.
 * @param renderer Obiekt PrimitiveRenderer służący do rysowania.
 */
void drawPolygon(const std::vector<Point2D>& vertices, PrimitiveRenderer& renderer);