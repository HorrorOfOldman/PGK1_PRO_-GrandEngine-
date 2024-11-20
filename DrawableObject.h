#pragma once
#include "GameObject.h"

class DrawableObject : public virtual GameObject {
public:
    virtual void draw() = 0; // Metoda abstrakcyjna
};
