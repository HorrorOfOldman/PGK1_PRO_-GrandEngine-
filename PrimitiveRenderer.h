#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include <cmath>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>

/**
 * @class PrimitiveRenderer
 * @brief Klasa odpowiedzialna za rysowanie podstawowych prymitywów graficznych na ekranie.
 */
class PrimitiveRenderer
{
public:
    /**
     * @brief Konstruktor domyœlny.
     */
    PrimitiveRenderer() {}

    ALLEGRO_COLOR Ucolor = al_map_rgb(255, 255, 255);

public:
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255); /**< Kolor bia³y */
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
     * @param x Wspó³rzêdna X piksela.
     * @param y Wspó³rzêdna Y piksela.
     * @return Kolor piksela.
     */
    ALLEGRO_COLOR GetPixel(int x, int y);

    /**
     * @brief Funkcja pomocnicza do porównywania kolorów.
     * @param c1 Pierwszy kolor.
     * @param c2 Drugi kolor.
     * @return Czy kolory s¹ takie same.
     */
    bool CompareColors(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2);

    /**
     * @brief Rysuje piksel w zadanym miejscu.
     * @param x0 Wspó³rzêdna X.
     * @param y0 Wspó³rzêdna Y.
     */
    void PutPixel(int x0, int y0);

    /**
     * @brief Rysuje liniê pomiêdzy dwoma punktami.
     * @param x0 Wspó³rzêdna X pocz¹tkowego punktu.
     * @param y0 Wspó³rzêdna Y pocz¹tkowego punktu.
     * @param x1 Wspó³rzêdna X koñcowego punktu.
     * @param y1 Wspó³rzêdna Y koñcowego punktu.
     */
    void DrawLine(int x0, int y0, int x1, int y1);

    /**
     * @brief Rysuje okr¹g o zadanym promieniu.
     * @param x0 Wspó³rzêdna X œrodka okrêgu.
     * @param y0 Wspó³rzêdna Y œrodka okrêgu.
     * @param R Promieñ okrêgu.
     */
    void DrawCircle(int x0, int y0, int R);

    /**
     * @brief Rysuje okr¹g za pomoc¹ 8-krotnej symetrii (algorytm Bresenhama).
     * @param x0 Wspó³rzêdna X œrodka okrêgu.
     * @param y0 Wspó³rzêdna Y œrodka okrêgu.
     * @param R Promieñ okrêgu.
     */
    void DrawCircleSymmetry(int x0, int y0, int R);

    /**
     * @brief Rysuje elipsê.
     * @param x0 Wspó³rzêdna X œrodka elipsy.
     * @param y0 Wspó³rzêdna Y œrodka elipsy.
     * @param Rx Promieñ elipsy w osi X.
     * @param Ry Promieñ elipsy w osi Y.
     */
    void DrawEllipse(int x0, int y0, int Rx, int Ry);

    /**
     * @brief Rysuje prostok¹t.
     * @param x0 Wspó³rzêdna X lewego górnego rogu prostok¹ta.
     * @param y0 Wspó³rzêdna Y lewego górnego rogu prostok¹ta.
     * @param x1 Wspó³rzêdna X prawego dolnego rogu prostok¹ta.
     * @param y1 Wspó³rzêdna Y prawego dolnego rogu prostok¹ta.
     */
    void DrawRectangle(int x0, int y0, int x1, int y1);

    /**
     * @brief Rysuje trójk¹t.
     * @param x0 Wspó³rzêdna X pierwszego wierzcho³ka.
     * @param y0 Wspó³rzêdna Y pierwszego wierzcho³ka.
     * @param x1 Wspó³rzêdna X drugiego wierzcho³ka.
     * @param y1 Wspó³rzêdna Y drugiego wierzcho³ka.
     * @param x2 Wspó³rzêdna X trzeciego wierzcho³ka.
     * @param y2 Wspó³rzêdna Y trzeciego wierzcho³ka.
     */
    void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2);

    // Kolorowanie metod¹
    /**
     * @brief Rysuje wype³niony prostok¹t.
     * @param x0 Wspó³rzêdna X lewego górnego rogu.
     * @param y0 Wspó³rzêdna Y lewego górnego rogu.
     * @param x1 Wspó³rzêdna X prawego dolnego rogu.
     * @param y1 Wspó³rzêdna Y prawego dolnego rogu.
     */
    void DrawFilledRectangle(int x0, int y0, int x1, int y1);

    /**
     * @brief Rysuje wype³niony trójk¹t.
     * @param x0 Wspó³rzêdna X pierwszego wierzcho³ka.
     * @param y0 Wspó³rzêdna Y pierwszego wierzcho³ka.
     * @param x1 Wspó³rzêdna X drugiego wierzcho³ka.
     * @param y1 Wspó³rzêdna Y drugiego wierzcho³ka.
     * @param x2 Wspó³rzêdna X trzeciego wierzcho³ka.
     * @param y2 Wspó³rzêdna Y trzeciego wierzcho³ka.
     */
    void DrawFilledTriangle(int x0, int y0, int x1, int y1, int x2, int y2);

    /**
     * @brief Rysuje wype³niony okr¹g.
     * @param x0 Wspó³rzêdna X œrodka okrêgu.
     * @param y0 Wspó³rzêdna Y œrodka okrêgu.
     * @param R Promieñ okrêgu.
     */
    void DrawFilledCircle(int x0, int y0, int R);

    // Inteligentniejsze kolorowanie
    /**
     * @brief Rysuje wype³nienie obszaru metod¹ Border Fill.
     * @param x Wspó³rzêdna X punktu startowego.
     * @param y Wspó³rzêdna Y punktu startowego.
     * @param fillColor Kolor wype³nienia.
     * @param borderColor Kolor granicy.
     */
    void BorderFill(int x, int y, ALLEGRO_COLOR fillColor, ALLEGRO_COLOR borderColor);

    /**
     * @brief Rysuje wype³nienie obszaru metod¹ Flood Fill.
     * @param x Wspó³rzêdna X punktu startowego.
     * @param y Wspó³rzêdna Y punktu startowego.
     * @param fillColor Kolor wype³nienia.
     */
    void FloodFill(int x, int y, ALLEGRO_COLOR fillColor);

    /**
     * @brief Funkcja testowa do wyœwietlania obrazu.
     * @param filePath Œcie¿ka do pliku obrazu.
     * @param x Wspó³rzêdna X pozycji.
     * @param y Wspó³rzêdna Y pozycji.
     * @param scaleX Skalowanie w osi X.
     * @param scaleY Skalowanie w osi Y.
     */
    void DisplayImage(const char* filePath, float x, float y, float scaleX, float scaleY);
};
