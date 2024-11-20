#include "Point2D.h"
using namespace std;


// Metoda do odczytania wspó³rzêdnych
void Point2D::GetCoordinates(int& outX, int& outY) const
{
	outX = x;
	outY = y;
}

// Metoda do zmiany wspó³rzêdnych
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
	renderer.PutPixel(x, y);
}

// Metoda do wyœwietlania wspó³rzêdnych w konsoli
void Point2D::DisplayCoordinates() const
{
	cout << "Point coordinates: (" << x << ", " << y << ")" << endl;
}

void Point2D::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

void Point2D::rotate(float angle) {
    float rad = angle * M_PI / 180.0f;
    float newX = x * cos(rad) - y * sin(rad);
    float newY = x * sin(rad) + y * cos(rad);
    x = newX;
    y = newY;
}

void Point2D::scale(float sx, float sy) {
    x *= sx;
    y *= sy;
}