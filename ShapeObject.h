#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <allegro5/allegro.h>

/**
 * @class ShapeObject
 * @brief Klasa abstrakcyjna reprezentuj¹ca obiekt kszta³tu, który mo¿na rysowaæ, przekszta³caæ i skalowaæ.
 *
 * Klasa `ShapeObject` dziedziczy po `DrawableObject` i `TransformableObject`, umo¿liwiaj¹c obiektowi rysowanie, translacjê, rotacjê oraz skalowanie.
 * Jest to klasa abstrakcyjna, wiêc metody musz¹ zostaæ zaimplementowane przez klasy pochodne.
 */
class ShapeObject : public DrawableObject, public TransformableObject
{
public:
    /**
     * @brief Wirtualna metoda rysuj¹ca obiekt na wyœwietlaczu.
     *
     * Metoda ta musi zostaæ zaimplementowana przez klasy pochodne i odpowiada za rysowanie obiektu na ekranie.
     *
     * @param display WskaŸnik do obiektu wyœwietlacza, na którym ma zostaæ narysowany obiekt.
     */
    virtual void Draw(ALLEGRO_DISPLAY* display) override = 0;

    /**
     * @brief Wirtualna metoda przesuwaj¹ca obiekt o zadany wektor (dx, dy).
     *
     * Metoda ta musi zostaæ zaimplementowana przez klasy pochodne i odpowiada za zmianê pozycji obiektu na ekranie.
     *
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     */
    virtual void trans(float dx, float dy) override = 0;

    /**
     * @brief Wirtualna metoda obracaj¹ca obiekt o zadany k¹t.
     *
     * Metoda ta musi zostaæ zaimplementowana przez klasy pochodne i odpowiada za obracanie obiektu na ekranie.
     *
     * @param a K¹t obrotu w stopniach.
     */
    virtual void rotate(float a) override = 0;

    /**
     * @brief Wirtualna metoda skaluj¹ca obiekt o zadany wspó³czynnik.
     *
     * Metoda ta musi zostaæ zaimplementowana przez klasy pochodne i odpowiada za zmianê rozmiaru obiektu na ekranie.
     *
     * @param k Wspó³czynnik skali, gdzie wartoœæ wiêksza ni¿ 1 oznacza powiêkszenie, a mniejsza ni¿ 1 zmniejszenie.
     */
    virtual void scal(float k) override = 0;
};
