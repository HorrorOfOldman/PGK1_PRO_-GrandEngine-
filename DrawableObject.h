#pragma once
#include "GameObject.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

/**
 * @class DrawableObject
 * @brief Klasa abstrakcyjna reprezentuj¹ca obiekt, który mo¿e byæ rysowany na ekranie.
 * Klasa dziedziczy po klasie GameObject i wymusza implementacjê metody rysowania w klasach pochodnych.
 */
class DrawableObject : public virtual GameObject
{
public:
    /**
     * @brief Wirtualna metoda rysuj¹ca obiekt na ekranie.
     * Klasa pochodna powinna zaimplementowaæ tê metodê, aby wyœwietliæ obiekt w odpowiedni sposób.
     * @param display WskaŸnik na obiekt wyœwietlacza, na którym rysowany jest obiekt.
     */
    virtual void Draw(ALLEGRO_DISPLAY* display) = 0;
};
