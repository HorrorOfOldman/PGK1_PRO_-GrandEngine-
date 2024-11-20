#pragma once
#include "GameObject.h"

class UpdatableObject : public virtual GameObject {
public:
    virtual void update() = 0; // Metoda abstrakcyjna
};
