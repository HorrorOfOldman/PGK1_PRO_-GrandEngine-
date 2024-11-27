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
* @brief Klasa odpowiadaj¹ca za dzia³anie okna silnika
*/
class Engine
{
private:
	/**
	* @brief Elementy klasy
	* @param screen_width - szerokoœc okna
	* @param screen_height - wysokoœæ okna
	* @param fullscreen - definiuje czy program ma siê uruchamiaæ w okienku, czy w pe³nym oknie
	* @param running - definiuje stan silnika, wartoœæ false powoduje wy³¹czenie okna
	* @param fps - definiuje liczbê klatek/sekundê(odœwierzanie ekranu) w silniku
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
	* * Inicjalizuje obiekt klasy Engine z domyœlnymi ustawieniami.
	*/
	Engine();

	/**
	* @brief Inicjalizator biblioteki allegro
	* 
	* Zwraca wartoœæ FALSE gdy nie uda³o siê zainicjalizowaæ biblioteki graficznej
	* Inicjalizuje inne elementy biblioteki
	* Jak obs³uge myszy i klawiatury
	*/
	bool Init();

	/**
	* @brief Pozwala na rêszne ustawienie rozdzielczoœci ekranu z poziomu konsoli
	*/
	void ScreenProperties();

	/**
	 * @brief Ustawia parametry graficzne okna.
	 *
	 * @param width         Szerokoœæ okna w pikselach.
	 * @param height        Wysokoœæ okna w pikselach.
	 * @param is_fullscreen Okreœla, czy okno dzia³a w trybie pe³noekranowym.
	 */
	void SetGraphicsMode(int width, int height, bool is_fullscreen);

	/**
	 * @brief Ustawia inne parametry gry, takie jak docelowa liczba klatek na sekundê.
	 *
	 * @param target_fps Docelowa liczba klatek na sekundê.
	 */
	void SetOtherSettings(int target_fps);

	/**
	 * @brief G³ówna pêtla gry.
	 *
	 * Obs³uguje zdarzenia, aktualizuje stan gry i renderuje grafikê.
	 */
	void GameLoop();

	/**
	 * @brief Obs³uguje zdarzenia klawiatury.
	 *
	 * @param keycode Kod klawisza, który zosta³ naciœniêty.
	 */
	void HandleKeyboard(int keycode);

	/**
	* @brief Obs³uguje zdarzenia myszy.
	*
	* @param button Przycisk myszy, który zosta³ naciœniêty.
	* @param x      Pozycja X kursora w momencie klikniêcia.
	* @param y      Pozycja Y kursora w momencie klikniêcia.
	*/
	void HandleMouse(int button, int x, int y);

	/**
	 * @brief Czyœci ekran, wype³niaj¹c go podanym kolorem.
	 *
	 * @param color Kolor u¿ywany do wype³nienia ekranu.
	 */
	void ClearScreen(ALLEGRO_COLOR color);

	/**
	 * @brief Loguje b³êdy.
	 *
	 * Wyœwietla komunikat o b³êdzie w konsoli lub odpowiednim narzêdziu debuguj¹cym.
	 *
	 * @param message Treœæ komunikatu o b³êdzie.
	 */
	void LogError(const char* message);

	/**
	 * @brief Zamyka grê i deinicjalizuje bibliotekê Allegro.
	 */
	void Shutdown();
};