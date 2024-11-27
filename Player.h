#pragma once
#include "BitmapHandler.h"
#include <allegro5/allegro.h>
#include <vector>

/**
 * @class Player
 * @brief Klasa reprezentuj�ca gracza, jego pozycj�, ruch oraz animacj�.
 */
class Player
{
public:
    /**
     * @brief Flagi okre�laj�ce, czy gracz porusza si� w okre�lonym kierunku.
     */
    bool up;    ///< Flaga ruchu w g�r�.
    bool down;  ///< Flaga ruchu w d�.
    bool left;  ///< Flaga ruchu w lewo.
    bool right; ///< Flaga ruchu w prawo.

    /**
     * @brief Pr�dko�� poruszania si� gracza.
     */
    float speed;

    /**
     * @brief Aktualna pozycja gracza.
     */
    float x; ///< Wsp�rz�dna X pozycji gracza.
    float y; ///< Wsp�rz�dna Y pozycji gracza.

    /**
     * @brief Handler bitmap u�ywany do zarz�dzania grafik� gracza.
     */
    BitmapHandler bit;

    /**
     * @brief Wektory przechowuj�ce ID bitmap animacji.
     */
    vector<long> BitmapID;    ///< Wektor identyfikator�w bitmap animacji.
    vector<long> bitmapIDs;   ///< Wektor dla aktualnej klatki animacji.

    /**
     * @brief Licznik klatek u�ywany do sterowania tempem animacji.
     */
    long frameCounter;

    /**
     * @brief Aktualnie wy�wietlana klatka animacji.
     */
    long currentFrame;

    /**
     * @brief Konstruktor klasy Player.
     *
     * @param SX Pocz�tkowa pozycja X gracza (domy�lnie 100).
     * @param SY Pocz�tkowa pozycja Y gracza (domy�lnie 100).
     */
    Player(float SX = 100, float SY = 100);

    /**
     * @brief Rysuje gracza na ekranie przy u�yciu aktualnej klatki animacji.
     */
    void draw();

    /**
     * @brief Aktualizuje pozycj� gracza na podstawie aktywnych flag ruchu.
     */
    void update();

    /**
     * @brief Ustawia now� pozycj� gracza.
     *
     * @param x Nowa wsp�rz�dna X gracza.
     * @param y Nowa wsp�rz�dna Y gracza.
     */
    void setPosition(float x, float y);

    /**
     * @brief Obs�uguje zdarzenia klawiatury i aktualizuje flagi ruchu.
     *
     * @param ev Obiekt zdarzenia Allegro.
     */
    void keyevent(ALLEGRO_EVENT& ev);
};
