#include "BitmapHandler.h"
#include <allegro5/bitmap.h>
#include <cstdio>
#include <vector>

BitmapHandler::~BitmapHandler() {}
long BitmapHandler::load(const char* img) {
    ALLEGRO_BITMAP* bmp = al_load_bitmap(img);
    if (bmp != nullptr) {
        bitmapy.push_back(bmp);
        return bitmapy.size() - 1;
    }
    printf("unable to load image \"%s\"\n", img);
    return -1;
}
void BitmapHandler::save(long index) {
    al_save_bitmap("a.png", bitmapy[index]);
}
void BitmapHandler::save(long index, const char* src) {
    al_save_bitmap(src, bitmapy[index]);
}
void BitmapHandler::destroy(long index) { free(bitmapy[index]); }
void BitmapHandler::copy(long index1, long index2) {
    bitmapy[index2] = bitmapy[index1];
}
ALLEGRO_BITMAP* BitmapHandler::retrieve(long index) {
    if (index < 0 || index >= bitmapy.size())
        return nullptr;
    return bitmapy[index];
}