#pragma once
#include "Point2D.h"

/**
 * @class LineSegment
 * @brief Klasa reprezentuj¹ca odcinek linii definiowany przez dwa punkty.
 */
class LineSegment
{
private:
    /**
     * @brief Punkt pocz¹tkowy odcinka.
     */
    Point2D start;

    /**
     * @brief Punkt koñcowy odcinka.
     */
    Point2D end;

public:
    /**
     * @brief Alternatywne punkty dostêpne publicznie (opcjonalne).
     */
    Point2D p1, p2;

    /**
     * @brief Konstruktor klasy LineSegment.
     *
     * @param start Punkt pocz¹tkowy odcinka.
     * @param end Punkt koñcowy odcinka.
     */
    LineSegment(Point2D start, Point2D end) : start(start), end(end) {}

    /**
     * @brief Pobiera wspó³rzêdne punktów pocz¹tkowego i koñcowego odcinka.
     *
     * @param startX Zmienna do zapisania wspó³rzêdnej X punktu pocz¹tkowego.
     * @param startY Zmienna do zapisania wspó³rzêdnej Y punktu pocz¹tkowego.
     * @param endX Zmienna do zapisania wspó³rzêdnej X punktu koñcowego.
     * @param endY Zmienna do zapisania wspó³rzêdnej Y punktu koñcowego.
     */
    void GetCoordinates(int& startX, int& startY, int& endX, int& endY) const;

    /**
     * @brief Ustawia nowe wspó³rzêdne punktów pocz¹tkowego i koñcowego odcinka.
     *
     * @param newStart Nowy punkt pocz¹tkowy.
     * @param newEnd Nowy punkt koñcowy.
     */
    void SetCoordinates(Point2D newStart, Point2D newEnd);

    /**
     * @brief Rysuje odcinek przy u¿yciu podanego renderera.
     *
     * @param renderer Obiekt klasy PrimitiveRenderer do rysowania odcinka.
     * @param incremental Flaga wskazuj¹ca, czy u¿ywaæ metody przyrostowej do rysowania (domyœlnie `false`).
     */
    void DrawSegment(PrimitiveRenderer& renderer, bool incremental = false);

private:
    /**
     * @brief Rysuje odcinek metod¹ przyrostow¹.
     *
     * @param renderer Obiekt klasy PrimitiveRenderer do rysowania.
     * @param x0 Wspó³rzêdna X punktu pocz¹tkowego.
     * @param y0 Wspó³rzêdna Y punktu pocz¹tkowego.
     * @param x1 Wspó³rzêdna X punktu koñcowego.
     * @param y1 Wspó³rzêdna Y punktu koñcowego.
     */
    void DrawIncremental(PrimitiveRenderer& renderer, int x0, int y0, int x1, int y1);
};
