#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <allegro5/allegro.h>

/**
 * @class ShapeObject
 * @brief Klasa abstrakcyjna reprezentuj�ca obiekt kszta�tu, kt�ry mo�na rysowa�, przekszta�ca� i skalowa�.
 *
 * Klasa `ShapeObject` dziedziczy po `DrawableObject` i `TransformableObject`, umo�liwiaj�c obiektowi rysowanie, translacj�, rotacj� oraz skalowanie.
 * Jest to klasa abstrakcyjna, wi�c metody musz� zosta� zaimplementowane przez klasy pochodne.
 */
class ShapeObject : public DrawableObject, public TransformableObject
{
public:
    /**
     * @brief Wirtualna metoda rysuj�ca obiekt na wy�wietlaczu.
     *
     * Metoda ta musi zosta� zaimplementowana przez klasy pochodne i odpowiada za rysowanie obiektu na ekranie.
     *
     * @param display Wska�nik do obiektu wy�wietlacza, na kt�rym ma zosta� narysowany obiekt.
     */
    virtual void Draw(ALLEGRO_DISPLAY* display) override = 0;

    /**
     * @brief Wirtualna metoda przesuwaj�ca obiekt o zadany wektor (dx, dy).
     *
     * Metoda ta musi zosta� zaimplementowana przez klasy pochodne i odpowiada za zmian� pozycji obiektu na ekranie.
     *
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     */
    virtual void trans(float dx, float dy) override = 0;

    /**
     * @brief Wirtualna metoda obracaj�ca obiekt o zadany k�t.
     *
     * Metoda ta musi zosta� zaimplementowana przez klasy pochodne i odpowiada za obracanie obiektu na ekranie.
     *
     * @param a K�t obrotu w stopniach.
     */
    virtual void rotate(float a) override = 0;

    /**
     * @brief Wirtualna metoda skaluj�ca obiekt o zadany wsp�czynnik.
     *
     * Metoda ta musi zosta� zaimplementowana przez klasy pochodne i odpowiada za zmian� rozmiaru obiektu na ekranie.
     *
     * @param k Wsp�czynnik skali, gdzie warto�� wi�ksza ni� 1 oznacza powi�kszenie, a mniejsza ni� 1 zmniejszenie.
     */
    virtual void scal(float k) override = 0;
};
