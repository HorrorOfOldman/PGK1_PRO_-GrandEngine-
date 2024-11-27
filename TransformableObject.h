#pragma once
#include "GameObject.h"

/**
 * @class TransformableObject
 * @brief Interfejs do obiekt�w, kt�re mog� by� przekszta�cane.
 *
 * Klasa `TransformableObject` reprezentuje obiekt, kt�ry mo�e by� przekszta�cany, czyli przesuwany, obracany i skalowany.
 * Klasa jest abstrakcyjna, wi�c metody musz� zosta� zaimplementowane przez klasy pochodne.
 */
class TransformableObject : public virtual GameObject {
public:

    /**
     * @brief Przesuwa obiekt o zadany wektor (dx, dy).
     *
     * Metoda ta musi zosta� zaimplementowana przez klasy pochodne, odpowiadaj�c za zmian� pozycji obiektu na ekranie.
     *
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     */
    virtual void trans(float dx, float dy) = 0;

    /**
     * @brief Obraca obiekt o zadany k�t.
     *
     * Metoda ta musi zosta� zaimplementowana przez klasy pochodne, odpowiadaj�c za obracanie obiektu na ekranie.
     *
     * @param a K�t obrotu w stopniach.
     */
    virtual void rotate(float a) = 0;

    /**
     * @brief Skaluje obiekt o zadany wsp�czynnik.
     *
     * Metoda ta musi zosta� zaimplementowana przez klasy pochodne, odpowiadaj�c za zmian� rozmiaru obiektu na ekranie.
     *
     * @param k Wsp�czynnik skali, gdzie warto�� wi�ksza ni� 1 oznacza powi�kszenie, a mniejsza ni� 1 zmniejszenie.
     */
    virtual void scal(float k) = 0;
};
