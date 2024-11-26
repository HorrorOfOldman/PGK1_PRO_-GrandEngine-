#pragma once
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>
#include <vector>

using namespace std;

class BitmapHandler
{
private:
	vector<ALLEGRO_BITMAP*> bitmapy;
	ALLEGRO_BITMAP* bitmap;
public:
	BitmapHandler();
	~BitmapHandler();//destruktor bitmap

	long load(const char* image);//�aduje bitmap� z pliku, image jest �cie�k� do pliku, zapisuje indeks za�adowanej bitmapy w vektorze(tym wy�ej)
	void save(long index);//zapisuje bitmap� do pliku, kt�rej indeks znajduje si� w wektorze
	void save(long index, const char* src);//zapisuje bitmap�, tylko do okreslonej �cie�ki
	void destroy(long index);//pozbywa si� bitmapy o podanym indeksie w wektorze, oraz ualania pami�� kt�r� zajmuje bitmba, usuwa j� z wektora
	void copy(long id1, long id2);//kopiuje bitmap� z indeksem id1 do indeksu id2
	ALLEGRO_BITMAP* retrieve(long index);//pobiera wska�nik na bitmap�, kt�ry mo�na potrm u�y� w innych funkcjach

	ALLEGRO_BITMAP* getBitmap();
	
};