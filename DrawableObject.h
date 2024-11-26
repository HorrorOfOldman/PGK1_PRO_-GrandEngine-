#pragma once
#include "GameObject.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class DrawableObject : public virtual GameObject 
{
public:
    virtual void Draw(ALLEGRO_DISPLAY* display) = 0;
};
