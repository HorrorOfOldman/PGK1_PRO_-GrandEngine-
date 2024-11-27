#pragma once
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
#define M_PI 3.14

/**
 * @class Point2D
 * @brief Klasa reprezentuj¹ca dwuwymiarowy punkt na p³aszczyŸnie, z mo¿liwoœci¹ zmiany pozycji, koloru i rysowania.
 */
class Point2D
{
public:
    /**
     * @brief Wspó³rzêdne punktu.
     */
    int x; ///< Wspó³rzêdna X punktu.
    int y; ///< Wspó³rzêdna Y punktu.

    /**
     * @brief Kolor punktu.
     */
    ALLEGRO_COLOR color;

public:
    /**
     * @brief Pobiera wspó³rzêdn¹ X punktu.
     * @return Wartoœæ wspó³rzêdnej X.
     */
    float getX() const { return x; }

    /**
     * @brief Pobiera wspó³rzêdn¹ Y punktu.
     * @return Wartoœæ wspó³rzêdnej Y.
     */
    float getY() const { return y; }

    /**
     * @brief Konstruktor domyœlny.
     * @param x Wspó³rzêdna X (domyœlnie 0.0f).
     * @param y Wspó³rzêdna Y (domyœlnie 0.0f).
     * @param color Kolor punktu (domyœlnie bia³y).
     */
    Point2D(float x = 0.0f, float y = 0.0f, ALLEGRO_COLOR color = al_map_rgb(255, 255, 255))
        : x(x), y(y), color(color) {}

    /**
     * @brief Konstruktor z parametrami wspó³rzêdnych i koloru.
     * @param x Wspó³rzêdna X punktu.
     * @param y Wspó³rzêdna Y punktu.
     * @param color Kolor punktu.
     */
    Point2D(int x, int y, ALLEGRO_COLOR color) : x(x), y(y), color(color) {}

    /**
     * @brief Pobiera wspó³rzêdne punktu.
     * @param outX Zmienna do zapisania wspó³rzêdnej X.
     * @param outY Zmienna do zapisania wspó³rzêdnej Y.
     */
    void GetCoordinates(int& outX, int& outY) const;

    /**
     * @brief Ustawia nowe wspó³rzêdne punktu.
     * @param newX Nowa wspó³rzêdna X.
     * @param newY Nowa wspó³rzêdna Y.
     */
    void SetCoordinates(int newX, int newY);

    /**
     * @brief Ustawia nowy kolor punktu.
     * @param newColor Nowy kolor punktu.
     */
    void SetColor(ALLEGRO_COLOR newColor);

    /**
     * @brief Rysuje punkt na ekranie.
     * @param renderer Obiekt PrimitiveRenderer do rysowania.
     */
    void DrawPoint(PrimitiveRenderer& renderer);

    /**
     * @brief Wyœwietla wspó³rzêdne punktu w konsoli.
     */
    void DisplayCoordinates() const;

    /**
     * @brief Przesuwa punkt o dany wektor.
     * @param x Wektor przesuniêcia w osi X.
     * @param y Wektor przesuniêcia w osi Y.
     */
    void MB(const int x, const int y);

    /**
     * @brief Przesuwa punkt do okreœlonej pozycji.
     * @param x Docelowa wspó³rzêdna X.
     * @param y Docelowa wspó³rzêdna Y.
     */
    void MT(const unsigned int x, const unsigned int y);
};
