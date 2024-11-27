#pragma once
#include "GameObject.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

/**
 * @class DrawableObject
 * @brief Klasa abstrakcyjna reprezentuj�ca obiekt, kt�ry mo�e by� rysowany na ekranie.
 * Klasa dziedziczy po klasie GameObject i wymusza implementacj� metody rysowania w klasach pochodnych.
 */
class DrawableObject : public virtual GameObject
{
public:
    /**
     * @brief Wirtualna metoda rysuj�ca obiekt na ekranie.
     * Klasa pochodna powinna zaimplementowa� t� metod�, aby wy�wietli� obiekt w odpowiedni spos�b.
     * @param display Wska�nik na obiekt wy�wietlacza, na kt�rym rysowany jest obiekt.
     */
    virtual void Draw(ALLEGRO_DISPLAY* display) = 0;
};
