#pragma once
#include <iostream>

// --------------------- Klasa GameObject --------------------- //
class GameObject {
public:
    virtual ~GameObject() = default;

    // Metody czysto wirtualne
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float factor) = 0;

    // Przyk³adowa metoda z cia³em, dziedziczona przez wszystkie obiekty
    virtual void log() const {
        std::cout << "GameObject: log called" << std::endl;
    }
};

// ------------------ Klasa UpdatableObject ------------------ //
class UpdatableObject : public virtual GameObject {
public:
    virtual void update() override = 0;
};

// ------------------- Klasa DrawableObject ------------------ //
class DrawableObject : public virtual GameObject {
public:
    virtual void draw() override = 0;
};

// ---------------- Klasa TransformableObject ---------------- //
class TransformableObject : public virtual GameObject {
public:
    virtual void translate(float dx, float dy) override = 0;
    virtual void rotate(float angle) override = 0;
    virtual void scale(float factor) override = 0;
};

// ------------------- Klasa ShapeObject --------------------- //
class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual void draw() override = 0;
    virtual void translate(float dx, float dy) override = 0;
    virtual void rotate(float angle) override = 0;
    virtual void scale(float factor) override = 0;
};
