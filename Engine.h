#pragma once
#include"PrimitiveRenderer.h"
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

class Engine
{
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* timer;
	int screen_width;
	int screen_height;
	bool fullscreen;
	bool running;
	int fps;

	PrimitiveRenderer r1;
	//	Player player;


public:
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

public:
	// Konstruktor
	Engine();

	// Inicjalizacja Allegro
	bool Init();

	//Podanie rozmiaru okna w konsoli-do pretestów
	void ScreenProperties();

	// Ustawienia trybu graficznego (parametryzacja)
	void SetGraphicsMode(int width, int height, bool is_fullscreen);

	// Parametryzacja innych ustawieñ (FPS, input)
	void SetOtherSettings(int target_fps);

	// G³ówna pêtla gry
	void GameLoop();

	// Obs³uga klawiatury
	void HandleKeyboard(int keycode);

	// Obs³uga myszy
	void HandleMouse(int button, int x, int y);

	// Czyszczenie ekranu (bitmapy) do zadanego koloru
	void ClearScreen(ALLEGRO_COLOR color);

	// Logowanie b³êdów
	void LogError(const char* message);

	// Zamykanie gry (deinicjacja Allegro)
	void Shutdown();
};