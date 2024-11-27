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
 * @brief Klasa reprezentuj�ca dwuwymiarowy punkt na p�aszczy�nie, z mo�liwo�ci� zmiany pozycji, koloru i rysowania.
 */
class Point2D
{
public:
    /**
     * @brief Wsp�rz�dne punktu.
     */
    int x; ///< Wsp�rz�dna X punktu.
    int y; ///< Wsp�rz�dna Y punktu.

    /**
     * @brief Kolor punktu.
     */
    ALLEGRO_COLOR color;

public:
    /**
     * @brief Pobiera wsp�rz�dn� X punktu.
     * @return Warto�� wsp�rz�dnej X.
     */
    float getX() const { return x; }

    /**
     * @brief Pobiera wsp�rz�dn� Y punktu.
     * @return Warto�� wsp�rz�dnej Y.
     */
    float getY() const { return y; }

    /**
     * @brief Konstruktor domy�lny.
     * @param x Wsp�rz�dna X (domy�lnie 0.0f).
     * @param y Wsp�rz�dna Y (domy�lnie 0.0f).
     * @param color Kolor punktu (domy�lnie bia�y).
     */
    Point2D(float x = 0.0f, float y = 0.0f, ALLEGRO_COLOR color = al_map_rgb(255, 255, 255))
        : x(x), y(y), color(color) {}

    /**
     * @brief Konstruktor z parametrami wsp�rz�dnych i koloru.
     * @param x Wsp�rz�dna X punktu.
     * @param y Wsp�rz�dna Y punktu.
     * @param color Kolor punktu.
     */
    Point2D(int x, int y, ALLEGRO_COLOR color) : x(x), y(y), color(color) {}

    /**
     * @brief Pobiera wsp�rz�dne punktu.
     * @param outX Zmienna do zapisania wsp�rz�dnej X.
     * @param outY Zmienna do zapisania wsp�rz�dnej Y.
     */
    void GetCoordinates(int& outX, int& outY) const;

    /**
     * @brief Ustawia nowe wsp�rz�dne punktu.
     * @param newX Nowa wsp�rz�dna X.
     * @param newY Nowa wsp�rz�dna Y.
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
     * @brief Wy�wietla wsp�rz�dne punktu w konsoli.
     */
    void DisplayCoordinates() const;

    /**
     * @brief Przesuwa punkt o dany wektor.
     * @param x Wektor przesuni�cia w osi X.
     * @param y Wektor przesuni�cia w osi Y.
     */
    void MB(const int x, const int y);

    /**
     * @brief Przesuwa punkt do okre�lonej pozycji.
     * @param x Docelowa wsp�rz�dna X.
     * @param y Docelowa wsp�rz�dna Y.
     */
    void MT(const unsigned int x, const unsigned int y);
};
