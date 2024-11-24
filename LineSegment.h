#pragma once
#include "Point2D.h"

class LineSegment
{
private:
	Point2D start; // Pocz�tek odcinka
	Point2D end;   // Koniec odcinka

public:
	Point2D p1, p2;

	// Konstruktor
	LineSegment(Point2D start, Point2D end) : start(start), end(end) {}

	// Metoda do odczytu wsp�rz�dnych pocz�tku i ko�ca
	void GetCoordinates(int& startX, int& startY, int& endX, int& endY) const;

	// Metoda do zmiany wsp�rz�dnych pocz�tku i ko�ca
	void SetCoordinates(Point2D newStart, Point2D newEnd);

	// Metoda do rysowania odcinka
	void DrawSegment(PrimitiveRenderer& renderer, bool incremental = false);

private:
	// Metoda do rysowania przyrostowego (je�li potrzebne)
	void DrawIncremental(PrimitiveRenderer& renderer, int x0, int y0, int x1, int y1);
/*
	void translate(float dx, float dy);
	void rotate(float angle);
	void scale(float sx, float sy);
*/
};