#include "Engine.h"
#include "polygon.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>

#define M_PI 3.14
using namespace std;


/**
* @brief Zmienne kolorów.
* @ Pozwalaj¹ podaæ nazwê kolorów.
* @ Dziêki temu nie trzeba za ka¿dym razem u¿ywaæ nowego al_map_rrgb().
*/
ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);




/**
* @brief Funcja main.
*  Pozwala testowaæ nasze klasy i jej metody 
*/
int main()
{
	Engine engine;

	// Inicjalizacja silnika
	if (!engine.Init())
	{
		return -1;
	}

	// Ustawienia trybu graficznego (800x600, tryb okienkowy)
	engine.SetGraphicsMode(800, 600, false);

	// Ustawienia innych parametrów (60 FPS)
	engine.SetOtherSettings(60);

	// Utworzenie obiektu PrimitiveRenderer
	PrimitiveRenderer rysuj;
	rysuj.SetColor(red);
	// Utworzenie punktu 
	Point2D punkt(400, 300, engine.red);

	// Rysowanie punktu
	punkt.DrawPoint(rysuj);

	// Wyœietla wspó³rzêdne w konsoli
	
	punkt.DisplayCoordinates();
	al_flip_display();
	Sleep(2000);
	//////
	Point2D startPoint(100, 150, engine.red);
	Point2D endPoint(200, 450, engine.blue);
	LineSegment segment(startPoint, endPoint);
	segment.DrawSegment(rysuj);
	

	al_flip_display();
	Sleep(2000);
	
	vector<Point2D> vertices = {
		Point2D(400, 100),
		Point2D(500, 300),
		Point2D(400, 500),
		Point2D(300, 400)
	};

	// narysuj okr¹g za pomoc¹ symetrii
	rysuj.DrawCircleSymmetry(100, 100, 50);
	// elipsa za pomoca symetrii
	rysuj.DrawEllipse(300, 300, 50, 70);
	al_flip_display();
	Sleep(1000);
	rysuj.SetColor(blue);
	rysuj.DrawRectangle(300, 10, 400, 110);
	
	rysuj.DrawFilledRectangle(700, 500, 800, 600);
	rysuj.DrawFilledCircle(300, 300, 50);
	rysuj.DrawFilledTriangle(50, 50, 100, 100, 50, 90);

	rysuj.DrawFilledRectangle(700, 500, 800, 600);
	rysuj.FloodFill(750, 550, blue);
	rysuj.DrawLine(50, 50,100, 300);

	rysuj.DisplayImage("testGr/0001.png", 100, 100, 1.0, 1.0);
	
	rysuj.SetColor(white);
	drawPolygon(vertices, rysuj);

	al_flip_display();
	Sleep(1000);
	// Uruchomienie g³ównej pêtli gry
	engine.GameLoop();

	// Zamykanie gry
	engine.Shutdown();

	return 0;
}
