#pragma once
//#include "Engine.h"
#include "PrimitiveRenderer.h"
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

class Point2D
{
public:
	int x, y; // Wsp�rz�dne punktu
	ALLEGRO_COLOR color; // Kolor punktu

public:
	// Konstruktor domy�lny
	Point2D() : x(0), y(0), color(al_map_rgb(255, 255, 255)) {}

	// Konstruktor z parametrami (pozycja + kolor)
	Point2D(int x, int y, ALLEGRO_COLOR color) : x(x), y(y), color(color) {}

	// Metoda do odczytania wsp�rz�dnych
	void GetCoordinates(int& outX, int& outY) const;

	// Metoda do zmiany wsp�rz�dnych
	void SetCoordinates(int newX, int newY);


	// Metoda do zmiany koloru punktu
	void SetColor(ALLEGRO_COLOR newColor);


	// Metoda do rysowania punktu
	void DrawPoint(PrimitiveRenderer& renderer);

	// Metoda do wy�wietlania wsp�rz�dnych w konsoli
	void DisplayCoordinates() const;
};