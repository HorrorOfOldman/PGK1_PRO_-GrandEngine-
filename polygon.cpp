#include "polygon.h"
#include "LineSegment.h"
#include <iostream>

void drawPolygon(const std::vector<Point2D>& vertices, PrimitiveRenderer& renderer) {
    if (vertices.size() < 3) {
        std::cerr << "A polygon requires at least 3 vertices!" << std::endl;
        return;
    }

    for (size_t i = 0; i < vertices.size(); ++i) {
        // Tworzenie odcinka dla ka¿dej pary wierzcho³ków
        Point2D start = vertices[i];
        Point2D end = vertices[(i + 1) % vertices.size()]; // Zamkniêcie wielok¹ta

        LineSegment segment(start, end);

        // Rysowanie odcinka
        segment.DrawSegment(renderer);
    }
}
