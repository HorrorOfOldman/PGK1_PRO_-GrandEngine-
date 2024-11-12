#include"Engine.h"
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
using namespace std;



// Konstruktor
Engine::Engine()
{
	display = nullptr;
	event_queue = nullptr;
	timer = nullptr;
	screen_width = 800; // Domyœlna szerokoœæ
	screen_height = 600; // Domyœlna wysokoœæ
	fullscreen = false; // Domyœlnie tryb okienkowy
	fps = 60; // Domyœlna liczba FPS
	running = true;
}

// Inicjalizacja Allegro
bool Engine::Init()
{
	if (!al_init())
	{
		LogError("Failed to initialize Allegro.");
		return false;
	}

	// Inicjalizacja dodatków do Allegro
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();


	// W³¹czamy podwójne buforowanie (domyœlne w Allegro)
	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 0, ALLEGRO_SUGGEST);  // Wy³¹czamy pojedyncze buforowanie
	al_set_new_display_option(ALLEGRO_SWAP_METHOD, 2, ALLEGRO_SUGGEST);   // 2 oznacza podwójne buforowanie

	return true;
}

//Podanie rozmiaru okna w konsoli-do pretestów
void Engine::ScreenProperties()
{
	cout << endl << "Podaj rozmiar x okna = "; cin >> screen_width;
	cout << endl << "Podaj rozmiar y okna = "; cin >> screen_height;
}

// Ustawienia trybu graficznego (parametryzacja)
void Engine::SetGraphicsMode(int width, int height, bool is_fullscreen)
{
	screen_width = width;
	screen_height = height;
	fullscreen = is_fullscreen;

	// Ustawienia trybu pe³noekranowego
	if (fullscreen)
	{
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	}
	else
	{
		al_set_new_display_flags(ALLEGRO_WINDOWED);
	}

	display = al_create_display(screen_width, screen_height);
	al_set_window_position(display, 300, 300);
	al_set_window_title(display, "GrandeEngine(PapajEngine_WERSZYN)");

	if (!display)
	{
		LogError("Failed to create display.");
	}
}

// Parametryzacja innych ustawieñ (FPS, input)
void Engine::SetOtherSettings(int target_fps)
{
	fps = target_fps;

	// Tworzenie timera na podstawie FPS
	timer = al_create_timer(1.0 / fps);
	if (!timer)
	{
		LogError("Failed to create timer.");
	}

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		LogError("Failed to create event queue.");
	}

	// Rejestracja Ÿróde³ zdarzeñ
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
}

// G³ówna pêtla gry
void Engine::GameLoop()
{
	al_start_timer(timer);
	while (running)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			// Aktualizacja logiki gry

			// Rysowanie ekranu
			//ClearScreen(al_map_rgb(0, 0, 0)); // Czarny ekran
			// Dodaj kod rysowania elementów gry


			al_flip_display();  // Zamiana buforów po rysowaniu
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false; // Zamyka grê
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			HandleKeyboard(ev.keyboard.keycode); // Obs³uga klawiatury
//				HandleKeyboard()
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			HandleMouse(ev.mouse.button, ev.mouse.x, ev.mouse.y); // Obs³uga myszy
		}


	}
}

// Obs³uga klawiatury
void Engine::HandleKeyboard(int keycode)
{
	if (keycode == ALLEGRO_KEY_ESCAPE)
	{
		running = false; // Zamknij grê po wciœniêciu ESC
	}
	if (keycode == ALLEGRO_KEY_W) // Rysuj kwadrat po wciœniêciu "w"
	{
		//cout << "W wciœniête" << endl;
		// Rysuj kwadrat, korzystaj¹c z metody DrawRectangle
		float side_length = 100; // D³ugoœæ boku kwadratu
		float x_start = 10;      // Pocz¹tkowa pozycja X
		float y_start = 10;      // Pocz¹tkowa pozycja Y
		// Rysowanie kwadratu o boku `side_length`
		r1.DrawRectangle(x_start, y_start, side_length, side_length, red);

		// Odœwie¿ ekran, aby wyœwietliæ rysunek
		al_flip_display();
		//Sleep(1000);

	}
	if (keycode == ALLEGRO_KEY_1) // odœwierz ekran po wciœniêciu "1"
	{
		al_flip_display();
		cout << "Special 1\n";
	}
	if (keycode == ALLEGRO_KEY_2) // zrób czarny ekran/"oczyœæ go"
	{
		ClearScreen(al_map_rgb(0, 0, 0)); // Czarny ekran
		cout << "Special 2\n";
	}
	if (keycode == ALLEGRO_KEY_F1)
	{
		screen_width = 800; // Domyœlna szerokoœæ
		screen_height = 600; // Domyœlna wysokoœæ
		fullscreen = false;

		al_resize_display(display, screen_width, screen_height);
		cout << "F1 - okno standard(800x600)\n";
	}
	if (keycode == ALLEGRO_KEY_F2)
	{
		screen_width = 400; // Domyœlna szerokoœæ
		screen_height = 300; // Domyœlna wysokoœæ
		fullscreen = true;

		al_resize_display(display, screen_width, screen_height);
		cout << "F2 - (400x300)\n";
	}
	// Dodaj obs³ugê innych klawiszy
}

// Obs³uga myszy
void Engine::HandleMouse(int button, int x, int y)
{
	if (button == 1) // Lewy przycisk myszy
	{
		cout << "LMouse clicked at (" << x << ", " << y << ")" << endl;
	}
	if (button == 2)// Prawy przycisk myszy
	{
		cout << "RMouse clicked at (" << x << ", " << y << ")" << endl;
	}
}

// Czyszczenie ekranu (bitmapy) do zadanego koloru
void Engine::ClearScreen(ALLEGRO_COLOR color)
{
	al_clear_to_color(color);
}

// Logowanie b³êdów
void Engine::LogError(const char* message)
{
	al_show_native_message_box(nullptr, "Error", "Engine Error", message, nullptr, ALLEGRO_MESSAGEBOX_ERROR);
}

// Zamykanie gry (deinicjacja Allegro)
void Engine::Shutdown()
{
	if (timer)
	{
		al_destroy_timer(timer);
	}
	if (display)
	{
		al_destroy_display(display);
	}
	if (event_queue)
	{
		al_destroy_event_queue(event_queue);
	}
}