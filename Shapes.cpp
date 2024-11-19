#include "PrimitiveRenderer.h"
#include "Shapes.h"
class ShapeLineSegment : public ShapeObject {
private:
    int x1, y1, x2, y2;        // Wspó³rzêdne koñców odcinka
    ALLEGRO_COLOR color;       // Kolor odcinka
    PrimitiveRenderer* renderer;

public:
    ShapeLineSegment(int x1, int y1, int x2, int y2, ALLEGRO_COLOR color, PrimitiveRenderer* renderer)
        : x1(x1), y1(y1), x2(x2), y2(y2), color(color), renderer(renderer) {}

    void draw() override {
        renderer->DrawLine(x1, y1, x2, y2, color);
    }

    void translate(float dx, float dy) override {
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }

    void rotate(float angle) override {
        // Implementacja obracania koñców odcinka
    }

    void scale(float factor) override {
        // Implementacja skalowania wzglêdem œrodka
    }
};
