#pragma once
#include "Point2D.h"

/**
 * @class LineSegment
 * @brief Klasa reprezentuj�ca odcinek linii definiowany przez dwa punkty.
 */
class LineSegment
{
private:
    /**
     * @brief Punkt pocz�tkowy odcinka.
     */
    Point2D start;

    /**
     * @brief Punkt ko�cowy odcinka.
     */
    Point2D end;

public:
    /**
     * @brief Alternatywne punkty dost�pne publicznie (opcjonalne).
     */
    Point2D p1, p2;

    /**
     * @brief Konstruktor klasy LineSegment.
     *
     * @param start Punkt pocz�tkowy odcinka.
     * @param end Punkt ko�cowy odcinka.
     */
    LineSegment(Point2D start, Point2D end) : start(start), end(end) {}

    /**
     * @brief Pobiera wsp�rz�dne punkt�w pocz�tkowego i ko�cowego odcinka.
     *
     * @param startX Zmienna do zapisania wsp�rz�dnej X punktu pocz�tkowego.
     * @param startY Zmienna do zapisania wsp�rz�dnej Y punktu pocz�tkowego.
     * @param endX Zmienna do zapisania wsp�rz�dnej X punktu ko�cowego.
     * @param endY Zmienna do zapisania wsp�rz�dnej Y punktu ko�cowego.
     */
    void GetCoordinates(int& startX, int& startY, int& endX, int& endY) const;

    /**
     * @brief Ustawia nowe wsp�rz�dne punkt�w pocz�tkowego i ko�cowego odcinka.
     *
     * @param newStart Nowy punkt pocz�tkowy.
     * @param newEnd Nowy punkt ko�cowy.
     */
    void SetCoordinates(Point2D newStart, Point2D newEnd);

    /**
     * @brief Rysuje odcinek przy u�yciu podanego renderera.
     *
     * @param renderer Obiekt klasy PrimitiveRenderer do rysowania odcinka.
     * @param incremental Flaga wskazuj�ca, czy u�ywa� metody przyrostowej do rysowania (domy�lnie `false`).
     */
    void DrawSegment(PrimitiveRenderer& renderer, bool incremental = false);

private:
    /**
     * @brief Rysuje odcinek metod� przyrostow�.
     *
     * @param renderer Obiekt klasy PrimitiveRenderer do rysowania.
     * @param x0 Wsp�rz�dna X punktu pocz�tkowego.
     * @param y0 Wsp�rz�dna Y punktu pocz�tkowego.
     * @param x1 Wsp�rz�dna X punktu ko�cowego.
     * @param y1 Wsp�rz�dna Y punktu ko�cowego.
     */
    void DrawIncremental(PrimitiveRenderer& renderer, int x0, int y0, int x1, int y1);
};
