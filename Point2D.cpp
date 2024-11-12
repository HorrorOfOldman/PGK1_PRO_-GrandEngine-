#include "Point2D.h"
using namespace std;

// Metoda do odczytania wsp�rz�dnych
void Point2D::GetCoordinates(int& outX, int& outY) const
{
	outX = x;
	outY = y;
}

// Metoda do zmiany wsp�rz�dnych
void Point2D::SetCoordinates(int newX, int newY)
{
	x = newX;
	y = newY;
}

// Metoda do zmiany koloru punktu
void Point2D::SetColor(ALLEGRO_COLOR newColor)
{
	color = newColor;
}

// Metoda do rysowania punktu
void Point2D::DrawPoint(PrimitiveRenderer& renderer)
{
	renderer.PutPixel(x, y, color);
}

// Metoda do wy�wietlania wsp�rz�dnych w konsoli
void Point2D::DisplayCoordinates() const
{
	cout << "Point coordinates: (" << x << ", " << y << ")" << endl;
}