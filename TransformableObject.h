#pragma once
#include "GameObject.h"

/**
 * @class TransformableObject
 * @brief Interfejs do obiektów, które mog¹ byæ przekszta³cane.
 *
 * Klasa `TransformableObject` reprezentuje obiekt, który mo¿e byæ przekszta³cany, czyli przesuwany, obracany i skalowany.
 * Klasa jest abstrakcyjna, wiêc metody musz¹ zostaæ zaimplementowane przez klasy pochodne.
 */
class TransformableObject : public virtual GameObject {
public:

    /**
     * @brief Przesuwa obiekt o zadany wektor (dx, dy).
     *
     * Metoda ta musi zostaæ zaimplementowana przez klasy pochodne, odpowiadaj¹c za zmianê pozycji obiektu na ekranie.
     *
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     */
    virtual void trans(float dx, float dy) = 0;

    /**
     * @brief Obraca obiekt o zadany k¹t.
     *
     * Metoda ta musi zostaæ zaimplementowana przez klasy pochodne, odpowiadaj¹c za obracanie obiektu na ekranie.
     *
     * @param a K¹t obrotu w stopniach.
     */
    virtual void rotate(float a) = 0;

    /**
     * @brief Skaluje obiekt o zadany wspó³czynnik.
     *
     * Metoda ta musi zostaæ zaimplementowana przez klasy pochodne, odpowiadaj¹c za zmianê rozmiaru obiektu na ekranie.
     *
     * @param k Wspó³czynnik skali, gdzie wartoœæ wiêksza ni¿ 1 oznacza powiêkszenie, a mniejsza ni¿ 1 zmniejszenie.
     */
    virtual void scal(float k) = 0;
};
