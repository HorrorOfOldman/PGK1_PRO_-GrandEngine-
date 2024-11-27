#pragma once
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include <allegro5/allegro.h>

/**
 * @brief Rysuje wielok¹t na podstawie listy wierzcho³ków.
 * @param vertices Wektor wierzcho³ków (punktów) wielok¹ta.
 * @param renderer Obiekt PrimitiveRenderer s³u¿¹cy do rysowania.
 */
void drawPolygon(const std::vector<Point2D>& vertices, PrimitiveRenderer& renderer);