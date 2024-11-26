#pragma once
#include "GameObject.h"

class TransformableObject : public virtual GameObject {
public:

    virtual void trans(float dx, float dy) = 0;
    virtual void rotate(float kat) = 0;
    virtual void scal(float parametr) = 0;
};