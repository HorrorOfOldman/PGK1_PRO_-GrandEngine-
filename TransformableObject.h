#pragma once
#include "GameObject.h"

class TransformableObject : public virtual GameObject {
public:
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float sx, float sy) = 0;
};
