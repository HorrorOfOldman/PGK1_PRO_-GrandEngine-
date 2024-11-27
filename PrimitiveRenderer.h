#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include <cmath>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>

/**
 * @class PrimitiveRenderer
 * @brief Klasa odpowiedzialna za rysowanie podstawowych prymityw�w graficznych na ekranie.
 */
class PrimitiveRenderer
{
public:
    /**
     * @brief Konstruktor domy�lny.
     */
    PrimitiveRenderer() {}

    ALLEGRO_COLOR Ucolor = al_map_rgb(255, 255, 255);

public:
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255); /**< Kolor bia�y */
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0); /**< Kolor czerwony */
    ALLEGRO_COLOR green = al_map_rgb(0, 255, 0); /**< Kolor zielony */
    ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255); /**< Kolor niebieski */
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0); /**< Kolor czarny */

    /**
     * @brief Ustawia kolor rysowania.
     * @param color Kolor do ustawienia.
     */
    void SetColor(ALLEGRO_COLOR color);

    /**
     * @brief Funkcja pomocnicza do pobierania koloru piksela.
     * @param x Wsp�rz�dna X piksela.
     * @param y Wsp�rz�dna Y piksela.
     * @return Kolor piksela.
     */
    ALLEGRO_COLOR GetPixel(int x, int y);

    /**
     * @brief Funkcja pomocnicza do por�wnywania kolor�w.
     * @param c1 Pierwszy kolor.
     * @param c2 Drugi kolor.
     * @return Czy kolory s� takie same.
     */
    bool CompareColors(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2);

    /**
     * @brief Rysuje piksel w zadanym miejscu.
     * @param x0 Wsp�rz�dna X.
     * @param y0 Wsp�rz�dna Y.
     */
    void PutPixel(int x0, int y0);

    /**
     * @brief Rysuje lini� pomi�dzy dwoma punktami.
     * @param x0 Wsp�rz�dna X pocz�tkowego punktu.
     * @param y0 Wsp�rz�dna Y pocz�tkowego punktu.
     * @param x1 Wsp�rz�dna X ko�cowego punktu.
     * @param y1 Wsp�rz�dna Y ko�cowego punktu.
     */
    void DrawLine(int x0, int y0, int x1, int y1);

    /**
     * @brief Rysuje okr�g o zadanym promieniu.
     * @param x0 Wsp�rz�dna X �rodka okr�gu.
     * @param y0 Wsp�rz�dna Y �rodka okr�gu.
     * @param R Promie� okr�gu.
     */
    void DrawCircle(int x0, int y0, int R);

    /**
     * @brief Rysuje okr�g za pomoc� 8-krotnej symetrii (algorytm Bresenhama).
     * @param x0 Wsp�rz�dna X �rodka okr�gu.
     * @param y0 Wsp�rz�dna Y �rodka okr�gu.
     * @param R Promie� okr�gu.
     */
    void DrawCircleSymmetry(int x0, int y0, int R);

    /**
     * @brief Rysuje elips�.
     * @param x0 Wsp�rz�dna X �rodka elipsy.
     * @param y0 Wsp�rz�dna Y �rodka elipsy.
     * @param Rx Promie� elipsy w osi X.
     * @param Ry Promie� elipsy w osi Y.
     */
    void DrawEllipse(int x0, int y0, int Rx, int Ry);

    /**
     * @brief Rysuje prostok�t.
     * @param x0 Wsp�rz�dna X lewego g�rnego rogu prostok�ta.
     * @param y0 Wsp�rz�dna Y lewego g�rnego rogu prostok�ta.
     * @param x1 Wsp�rz�dna X prawego dolnego rogu prostok�ta.
     * @param y1 Wsp�rz�dna Y prawego dolnego rogu prostok�ta.
     */
    void DrawRectangle(int x0, int y0, int x1, int y1);

    /**
     * @brief Rysuje tr�jk�t.
     * @param x0 Wsp�rz�dna X pierwszego wierzcho�ka.
     * @param y0 Wsp�rz�dna Y pierwszego wierzcho�ka.
     * @param x1 Wsp�rz�dna X drugiego wierzcho�ka.
     * @param y1 Wsp�rz�dna Y drugiego wierzcho�ka.
     * @param x2 Wsp�rz�dna X trzeciego wierzcho�ka.
     * @param y2 Wsp�rz�dna Y trzeciego wierzcho�ka.
     */
    void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2);

    // Kolorowanie metod�
    /**
     * @brief Rysuje wype�niony prostok�t.
     * @param x0 Wsp�rz�dna X lewego g�rnego rogu.
     * @param y0 Wsp�rz�dna Y lewego g�rnego rogu.
     * @param x1 Wsp�rz�dna X prawego dolnego rogu.
     * @param y1 Wsp�rz�dna Y prawego dolnego rogu.
     */
    void DrawFilledRectangle(int x0, int y0, int x1, int y1);

    /**
     * @brief Rysuje wype�niony tr�jk�t.
     * @param x0 Wsp�rz�dna X pierwszego wierzcho�ka.
     * @param y0 Wsp�rz�dna Y pierwszego wierzcho�ka.
     * @param x1 Wsp�rz�dna X drugiego wierzcho�ka.
     * @param y1 Wsp�rz�dna Y drugiego wierzcho�ka.
     * @param x2 Wsp�rz�dna X trzeciego wierzcho�ka.
     * @param y2 Wsp�rz�dna Y trzeciego wierzcho�ka.
     */
    void DrawFilledTriangle(int x0, int y0, int x1, int y1, int x2, int y2);

    /**
     * @brief Rysuje wype�niony okr�g.
     * @param x0 Wsp�rz�dna X �rodka okr�gu.
     * @param y0 Wsp�rz�dna Y �rodka okr�gu.
     * @param R Promie� okr�gu.
     */
    void DrawFilledCircle(int x0, int y0, int R);

    // Inteligentniejsze kolorowanie
    /**
     * @brief Rysuje wype�nienie obszaru metod� Border Fill.
     * @param x Wsp�rz�dna X punktu startowego.
     * @param y Wsp�rz�dna Y punktu startowego.
     * @param fillColor Kolor wype�nienia.
     * @param borderColor Kolor granicy.
     */
    void BorderFill(int x, int y, ALLEGRO_COLOR fillColor, ALLEGRO_COLOR borderColor);

    /**
     * @brief Rysuje wype�nienie obszaru metod� Flood Fill.
     * @param x Wsp�rz�dna X punktu startowego.
     * @param y Wsp�rz�dna Y punktu startowego.
     * @param fillColor Kolor wype�nienia.
     */
    void FloodFill(int x, int y, ALLEGRO_COLOR fillColor);

    /**
     * @brief Funkcja testowa do wy�wietlania obrazu.
     * @param filePath �cie�ka do pliku obrazu.
     * @param x Wsp�rz�dna X pozycji.
     * @param y Wsp�rz�dna Y pozycji.
     * @param scaleX Skalowanie w osi X.
     * @param scaleY Skalowanie w osi Y.
     */
    void DisplayImage(const char* filePath, float x, float y, float scaleX, float scaleY);
};
