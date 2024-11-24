#include "GameObject.h"
#include "PrimitiveRenderer.h"
#include "Shapes.h"
#include <cmath>
#include <cstdio>

void TransformableObject::translate(int x, int y) {}
void TransformableObject::rotate(float a) {}
void TransformableObject::rotate(float a, int x, int y) {}
void TransformableObject::scale(float scale) {}
void TransformableObject::scale(float scale, int x, int y) {}
void DrawableObject::Draw() {}
void UpdatableObject::update() {}
void AnimatedObject::animate() {}
void Sprite::translate(int x, int y) {}
void Sprite::rotate(float a) {}
void Sprite::rotate(float a, int x, int y) {}
void Sprite::scale(float scale) {}
void Sprite::scale(float scale, int x, int y) {}
void Sprite::afterAnimation() {}
void BitmapObject::rotate(float a) {}
void BitmapObject::rotate(float a, int x, int y) {}
void BitmapObject::scale(float scale) {}
void BitmapObject::scale(float scale, int x, int y) {}


void TransformableObject::_translate(Point2D* p, int x, int y) {
    p->x += x;
    p->y += y;
}

void TransformableObject::_rotate(Point2D* p, float a, int x, int y) {
    a = a * (M_PI / 180);
    const float _sin = sin(a);
    const float _cos = cos(a);

    int holder = x + ((p->x - x) * _cos) - ((p->y - y) * _sin);
    p->y = y + ((p->x - x) * _sin) + ((p->y - y) * _cos);
    p->x = holder;
}
void TransformableObject::_rotate(Point2D* p, float a) {

    a = a * (M_PI / 180);
    const float _sin = sin(a);
    const float _cos = cos(a);
    int holder = (p->x * _cos) - (p->y * _sin);
    ;

    printf("a: %f sin: %f, cos: %f\n", a, _sin, _cos);
    printf("P: %d,%d\n", p->x, p->y);
    p->y = (p->x * _sin) + (p->y * _cos);
    p->x = holder;
    printf("A: %d,%d\n", p->x, p->y);
}
void TransformableObject::_scale(Point2D* p, float scale) {
    p->x = p->x * scale;
    p->y = p->y * scale;
}
void TransformableObject::_scale(Point2D* p, float scale, int x, int y) {
    p->x = (p->x - x) * scale;
    p->y = (p->y - y) * scale;
}
// Line segment
LineSegmentP::LineSegmentP(PrimitiveRenderer* prdr, Point2D* p1, Point2D* p2) {
    this->p1 = p1;
    this->p2 = p2;
    this->prender = prdr;
}
void LineSegmentP::translate(int x, int y) {
    _translate(p1, x, y);
    _translate(p2, x, y);
}
void LineSegmentP::rotate(float a) {
    _rotate(p1, a);
    _rotate(p2, a);
}
void LineSegmentP::rotate(float a, int x, int y) {
    _rotate(p1, a, x, y);
    _rotate(p2, a, x, y);
}
void LineSegmentP::scale(float scale) {
    _scale(p1, scale);
    _scale(p2, scale);
}
void LineSegmentP::scale(float scale, int x, int y) {
    _scale(p1, scale, x, y);
    _scale(p2, scale, x, y);
}
void LineSegmentP::Draw() {
    this->prender->DrawLine(p1->x, p1->y, p2->x, p2->y);
}

void BitmapObject::draw() {
    ALLEGRO_BITMAP* bmp = bh.retrieve(usedBitmap);
    if (!bmp)
        return;
    al_draw_bitmap(bmp, PosX, PosY, 0);
}
void BitmapObject::translate(int x, int y) {}
void BitmapObject::_translate(int x, int y) {
    PosX += x;
    PosY += y;
}
void BitmapObject::setBitmap(long index) { usedBitmap = index; }
void BitmapObject::addBitmap(const char* src) { bh.load(src); }
Sprite::Sprite(unsigned MaxRange, unsigned MaxTypes) {
    this->MaxTypes = MaxTypes;
    this->MaxRange = MaxRange;
    animationIndex = new long[MaxRange * MaxTypes];
    for (long x = 0; x < (MaxRange * MaxTypes); x++) {
        animationIndex[x] = -1;
    }
}
void Sprite::draw() {
    ALLEGRO_BITMAP* bmp =
        bh.retrieve(animationIndex[(uType * MaxRange) + uRange]);
    if (!bmp)
        return;
    al_draw_bitmap(bmp, PosX, PosY, 0);
}
void Sprite::animate() {
    static unsigned localFpa = fpa;
    draw();
    if (!localFpa) {
        next();
        localFpa = fpa;
    }
    else
        localFpa--;
}
void Sprite::next() {
    if (uRange < MaxRange &&
        animationIndex[(uType * MaxRange) + uRange + 1] != -1) {
        uRange++;
    }
    else {
        uRange = 0;
        afterAnimation();
    }
}
void Sprite::nextSector() {
    uType++;
    if (uType >= MaxTypes || animationIndex[(uType * MaxRange) + uRange] == -1)
        uType = 0;
}
void Sprite::setFPA(unsigned amm) { this->fpa = amm; }
void Sprite::newBmp(const char* src, unsigned range, unsigned type) {
    animationIndex[(type * MaxRange) + range] = bh.load(src);
}
void Sprite::setSector(unsigned sector) {
    if (sector < MaxTypes)
        uType = sector;
}