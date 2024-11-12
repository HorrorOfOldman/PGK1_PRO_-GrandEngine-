#include "LineSegment.h"


	// Metoda do odczytu wspó³rzêdnych pocz¹tku i koñca
	void LineSegment::GetCoordinates(int& startX, int& startY, int& endX, int& endY) const
	{
		start.GetCoordinates(startX, startY);
		end.GetCoordinates(endX, endY);
	}

	// Metoda do zmiany wspó³rzêdnych pocz¹tku i koñca
	void LineSegment::SetCoordinates(Point2D newStart, Point2D newEnd)
	{
		start = newStart;
		end = newEnd;
	}

	// Metoda do rysowania odcinka
	void LineSegment::DrawSegment(PrimitiveRenderer& renderer, bool incremental )
	{
		int startX, startY, endX, endY;
		GetCoordinates(startX, startY, endX, endY);
		renderer.DrawLine(startX, startY, endX, endY, renderer.white); // Domyœlny kolor
	}

	// Metoda do rysowania przyrostowego (jeœli potrzebne)
	void LineSegment::DrawIncremental(PrimitiveRenderer& renderer, int x0, int y0, int x1, int y1)
	{
		int dx = x1 - x0;
		int dy = y1 - y0;
		int step = max(abs(dx), abs(dy));
		float xIncrement = dx / (float)step;
		float yIncrement = dy / (float)step;
		float x = x0;
		float y = y0;

		for (int i = 0; i <= step; i++) {
			renderer.PutPixel((int)(x + 0.5), (int)(y + 0.5), renderer.white); // Rysowanie pikseli
			x += xIncrement;
			y += yIncrement;
		}
	}