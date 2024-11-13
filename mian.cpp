//https://www.youtube.com/watch?v=QTqNVHtc_us
#include "Engine.h"
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


ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);



/// //// /// //
//ONLY IN DEATH DOES DUTY END//
// G³ówna funkcja
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
	

	// narysuj okr¹g za pomoc¹ symetrii
	rysuj.DrawCircleSymmetry(100, 100, 50, red);
	// elipsa za pomoca symetrii
	rysuj.DrawEllipse(300, 300, 50, 70, blue);
	al_flip_display();
	Sleep(1000);

	rysuj.DrawRectangle(300, 10, 400, 110, red);

	rysuj.DrawFilledRectangle(700, 500, 800, 600, red);
	rysuj.DrawFilledCircle(300, 300, 50, blue);
	rysuj.DrawFilledTriangle(50, 50, 100, 100, 50, 90, white);

	rysuj.DrawFilledRectangle(700, 500, 800, 600, red);
	rysuj.FloodFill(750, 550, blue);
	rysuj.DrawLine(50, 50,100, 300, blue);

	rysuj.DisplayImage("testGr/0001.png", 100, 100, 1.0, 1.0);

	al_flip_display();
	Sleep(1000);
	// Uruchomienie g³ównej pêtli gry
	engine.GameLoop();

	// Zamykanie gry
	engine.Shutdown();

	return 0;
}
