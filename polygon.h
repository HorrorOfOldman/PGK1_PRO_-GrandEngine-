#pragma once
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include <allegro5/allegro.h>

/**
 * @brief Rysuje wielok�t na podstawie listy wierzcho�k�w.
 * @param vertices Wektor wierzcho�k�w (punkt�w) wielok�ta.
 * @param renderer Obiekt PrimitiveRenderer s�u��cy do rysowania.
 */
void drawPolygon(const std::vector<Point2D>& vertices, PrimitiveRenderer& renderer);