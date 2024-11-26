#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <allegro5/allegro.h>

class ShapeObject : public DrawableObject, public TransformableObject
{
public:
    virtual void Draw(ALLEGRO_DISPLAY* display) override = 0;
    virtual void trans(float dx, float dy) override = 0;
    virtual void rotate(float a) override = 0;
    virtual void scal(float k) override = 0;
};