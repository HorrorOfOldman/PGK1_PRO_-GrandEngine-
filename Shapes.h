#include "GameObject.h"
#include "PrimitiveRenderer.h"

class ShapePoint2D : public ShapeObject {
private:
    int x, y;                  // Wspó³rzêdne punktu
    ALLEGRO_COLOR color;       // Kolor punktu
    PrimitiveRenderer* renderer;

public:
    ShapePoint2D(int x, int y, ALLEGRO_COLOR color, PrimitiveRenderer* renderer)
        : x(x), y(y), color(color), renderer(renderer) {}

    void draw() override {
        renderer->PutPixel(x, y, color);
    }

    void translate(float dx, float dy) override {
        x += dx;
        y += dy;
    }

    void rotate(float angle) override {
        // Brak sensu dla punktu (obrót nie zmienia pozycji wzglêdem siebie)
    }

    void scale(float factor) override {
        // Brak sensu dla punktu (mo¿na opcjonalnie zmieniaæ promieñ rysowania)
    }
};
