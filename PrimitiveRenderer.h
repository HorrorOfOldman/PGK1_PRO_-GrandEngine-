#pragma once
#include<stack>
#include <iostream>
#include <vector>
#include <cmath>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
class PrimitiveRenderer
{
public:
	PrimitiveRenderer() {}

public:
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

	// Funkcja pomocnicza do pobierania koloru piksela
	ALLEGRO_COLOR GetPixel(int x, int y);

	// Funkcja pomocnicza do por�wnywania kolor�w (ze wzgl�du na struktur� ALLEGRO_COLOR)
	bool CompareColors(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2);

	//// Funkcje rysuj�ce///////////////////////////////////

	//zr�b pixel
	void PutPixel(int x0, int y0, ALLEGRO_COLOR color);
	
	// Rysowanie linii
	void DrawLine(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color);
	
	// Rysowanie okr�gu- zwyk�a
	void DrawCircle(int x0, int y0, int R, ALLEGRO_COLOR color);
	
	// Metoda rysuj�ca okr�g za pomoc� 8-krotnej symetrii (algorytm Bresenhama)
	void DrawCircleSymmetry(int x0, int y0, int R, ALLEGRO_COLOR color);
	
	// Rysowanie elipsy
	void DrawEllipse(int x0, int y0, int Rx, int Ry, ALLEGRO_COLOR color);
	
	// Funkcja do rysowania prostok�ta
	void DrawRectangle(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color);
	
	// Funkcja do rysowania tr�jk�ta
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, ALLEGRO_COLOR color);
	
	//// Kolorowanie metod� - MA DZIA�A� ////////////////////////

	// Wype�niony prostok�t
	void DrawFilledRectangle(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color);
	
	// Funkcja do rysowania wype�nionego tr�jk�ta (metoda skan-linii)
	void DrawFilledTriangle(int x0, int y0, int x1, int y1, int x2, int y2, ALLEGRO_COLOR color);
	
	// Wype�niony okr�g (rysowanie linii poziomych dla ka�dego "ringu")
	void DrawFilledCircle(int x0, int y0, int R, ALLEGRO_COLOR color);

	//// Inteligentniejsze kolorowanie - to o kt�rym wspomina� �ukawski na wyk�adzie /////////////////////////////////////

	// Border Fill Algorithm (iteracyjny)
	void BorderFill(int x, int y, ALLEGRO_COLOR fillColor, ALLEGRO_COLOR borderColor);
	
	// Flood Fill Algorithm (iteracyjny)
	void FloodFill(int x, int y, ALLEGRO_COLOR fillColor);
	

	///////////// Poligon
	



	// testownik
	void DisplayImage(const char* filePath, float x, float y, float scaleX, float scaleY);

	void xd(int x, int y, int size, ALLEGRO_COLOR color);
};