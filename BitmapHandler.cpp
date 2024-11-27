#include "BitmapHandler.h"
#include <allegro5/bitmap.h>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

BitmapHandler::~BitmapHandler() {}
long BitmapHandler::load(const char* img) {
    printf("Pr�ba za�adowania obrazu: %s\n", img);

    ALLEGRO_BITMAP* bmp = al_load_bitmap(img);
    if (bmp != nullptr) {
        printf("Obraz za�adowany pomy�lnie: %s\n", img);
        bitmapy.push_back(bmp);
        return bitmapy.size() - 1;
    }

    // Wy�wietlenie komunikatu b��du
    printf("B��d: nie uda�o si� za�adowa� obrazu \"%s\"\n", img);
    return -1;
}
void BitmapHandler::save(long index) 
{
    al_save_bitmap("a.png", bitmapy[index]);
}
void BitmapHandler::save(long index, const char* src) 
{
    al_save_bitmap(src, bitmapy[index]);
}
void BitmapHandler::destroy(long index)
{
    al_destroy_bitmap(bitmapy[index]); 
    bitmapy[index] = nullptr;
}
void BitmapHandler::copy(long index1, long index2) 
{
    bitmapy[index2] = bitmapy[index1];
}
void BitmapHandler::draw(long index, float x, float y, int flags)
{
    if (index < 0 || index >= bitmapy.size() || !bitmapy[index])
    {
        cerr << "Invalid bitmap index: " << index << endl;
        return;
    }

        al_draw_bitmap(bitmapy[index], x, y, 0);
}
void BitmapHandler::scrapdraw(long index, float x, float y, float sx, float sy, float width, float height, int flags) {
    if (index < 0 || index >= bitmapy.size() || !bitmapy[index]) {
        std::cerr << "Invalid bitmap index: " << index << std::endl;
        return;
    }

    // Rysowanie fragmentu bitmapy
    al_draw_bitmap_region(
        bitmapy[index], // Bitmapa �r�d�owa
        sx, sy,         // G�rny lewy r�g fragmentu w bitmapie
        width, height,  // Szeroko�� i wysoko�� fragmentu
        x, y,           // Pozycja, w kt�rej fragment zostanie narysowany
        flags           // Flagi
    );
}

ALLEGRO_BITMAP* BitmapHandler::retrieve(long index)
{
    if (index < 0 || index >= bitmapy.size())
        return nullptr;
    return bitmapy[index];
}

ALLEGRO_BITMAP* BitmapHandler::getBitmap() 
{
    return bitmap;
}