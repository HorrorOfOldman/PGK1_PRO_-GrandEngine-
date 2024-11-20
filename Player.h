#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include "Point2D.h"

class Player : public ShapeObject, public UpdatableObject {
    Point2D position;

public:
    Player(float x, float y) : position(x, y) {}

    void update() override;
    void draw() override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
};
