#pragma once
#include"PrimitiveRenderer.h"
#include "Player.h"
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

/**
* @class Engine
* @brief Klasa odpowiadaj�ca za dzia�anie okna silnika
*/
class Engine
{
private:
	/**
	* @brief Elementy klasy
	* @param screen_width - szeroko�c okna
	* @param screen_height - wysoko�� okna
	* @param fullscreen - definiuje czy program ma si� uruchamia� w okienku, czy w pe�nym oknie
	* @param running - definiuje stan silnika, warto�� false powoduje wy��czenie okna
	* @param fps - definiuje liczb� klatek/sekund�(od�wierzanie ekranu) w silniku
	*/
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* timer;
	int screen_width;
	int screen_height;
	bool fullscreen;
	bool running;
	int fps;

	PrimitiveRenderer r1;
	Player player;


public:
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

public:
	/**
	* @brief Konstruktor klasy Engine
	* 
	* * Inicjalizuje obiekt klasy Engine z domy�lnymi ustawieniami.
	*/
	Engine();

	/**
	* @brief Inicjalizator biblioteki allegro
	* 
	* Zwraca warto�� FALSE gdy nie uda�o si� zainicjalizowa� biblioteki graficznej
	* Inicjalizuje inne elementy biblioteki
	* Jak obs�uge myszy i klawiatury
	*/
	bool Init();

	/**
	* @brief Pozwala na r�szne ustawienie rozdzielczo�ci ekranu z poziomu konsoli
	*/
	void ScreenProperties();

	/**
	 * @brief Ustawia parametry graficzne okna.
	 *
	 * @param width         Szeroko�� okna w pikselach.
	 * @param height        Wysoko�� okna w pikselach.
	 * @param is_fullscreen Okre�la, czy okno dzia�a w trybie pe�noekranowym.
	 */
	void SetGraphicsMode(int width, int height, bool is_fullscreen);

	/**
	 * @brief Ustawia inne parametry gry, takie jak docelowa liczba klatek na sekund�.
	 *
	 * @param target_fps Docelowa liczba klatek na sekund�.
	 */
	void SetOtherSettings(int target_fps);

	/**
	 * @brief G��wna p�tla gry.
	 *
	 * Obs�uguje zdarzenia, aktualizuje stan gry i renderuje grafik�.
	 */
	void GameLoop();

	/**
	 * @brief Obs�uguje zdarzenia klawiatury.
	 *
	 * @param keycode Kod klawisza, kt�ry zosta� naci�ni�ty.
	 */
	void HandleKeyboard(int keycode);

	/**
	* @brief Obs�uguje zdarzenia myszy.
	*
	* @param button Przycisk myszy, kt�ry zosta� naci�ni�ty.
	* @param x      Pozycja X kursora w momencie klikni�cia.
	* @param y      Pozycja Y kursora w momencie klikni�cia.
	*/
	void HandleMouse(int button, int x, int y);

	/**
	 * @brief Czy�ci ekran, wype�niaj�c go podanym kolorem.
	 *
	 * @param color Kolor u�ywany do wype�nienia ekranu.
	 */
	void ClearScreen(ALLEGRO_COLOR color);

	/**
	 * @brief Loguje b��dy.
	 *
	 * Wy�wietla komunikat o b��dzie w konsoli lub odpowiednim narz�dziu debuguj�cym.
	 *
	 * @param message Tre�� komunikatu o b��dzie.
	 */
	void LogError(const char* message);

	/**
	 * @brief Zamyka gr� i deinicjalizuje bibliotek� Allegro.
	 */
	void Shutdown();
};