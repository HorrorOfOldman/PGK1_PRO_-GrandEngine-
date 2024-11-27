#pragma once
#include "BitmapHandler.h"
#include <allegro5/allegro.h>
#include <vector>

/**
 * @class Player
 * @brief Klasa reprezentuj¹ca gracza, jego pozycjê, ruch oraz animacjê.
 */
class Player
{
public:
    /**
     * @brief Flagi okreœlaj¹ce, czy gracz porusza siê w okreœlonym kierunku.
     */
    bool up;    ///< Flaga ruchu w górê.
    bool down;  ///< Flaga ruchu w dó³.
    bool left;  ///< Flaga ruchu w lewo.
    bool right; ///< Flaga ruchu w prawo.

    /**
     * @brief Prêdkoœæ poruszania siê gracza.
     */
    float speed;

    /**
     * @brief Aktualna pozycja gracza.
     */
    float x; ///< Wspó³rzêdna X pozycji gracza.
    float y; ///< Wspó³rzêdna Y pozycji gracza.

    /**
     * @brief Handler bitmap u¿ywany do zarz¹dzania grafik¹ gracza.
     */
    BitmapHandler bit;

    /**
     * @brief Wektory przechowuj¹ce ID bitmap animacji.
     */
    vector<long> BitmapID;    ///< Wektor identyfikatorów bitmap animacji.
    vector<long> bitmapIDs;   ///< Wektor dla aktualnej klatki animacji.

    /**
     * @brief Licznik klatek u¿ywany do sterowania tempem animacji.
     */
    long frameCounter;

    /**
     * @brief Aktualnie wyœwietlana klatka animacji.
     */
    long currentFrame;

    /**
     * @brief Konstruktor klasy Player.
     *
     * @param SX Pocz¹tkowa pozycja X gracza (domyœlnie 100).
     * @param SY Pocz¹tkowa pozycja Y gracza (domyœlnie 100).
     */
    Player(float SX = 100, float SY = 100);

    /**
     * @brief Rysuje gracza na ekranie przy u¿yciu aktualnej klatki animacji.
     */
    void draw();

    /**
     * @brief Aktualizuje pozycjê gracza na podstawie aktywnych flag ruchu.
     */
    void update();

    /**
     * @brief Ustawia now¹ pozycjê gracza.
     *
     * @param x Nowa wspó³rzêdna X gracza.
     * @param y Nowa wspó³rzêdna Y gracza.
     */
    void setPosition(float x, float y);

    /**
     * @brief Obs³uguje zdarzenia klawiatury i aktualizuje flagi ruchu.
     *
     * @param ev Obiekt zdarzenia Allegro.
     */
    void keyevent(ALLEGRO_EVENT& ev);
};
