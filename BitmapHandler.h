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

	long load(const char* image);//³aduje bitmapê z pliku, image jest œcie¿k¹ do pliku, zapisuje indeks za³adowanej bitmapy w vektorze(tym wy¿ej)
	void save(long index);//zapisuje bitmapê do pliku, której indeks znajduje siê w wektorze
	void save(long index, const char* src);//zapisuje bitmapê, tylko do okreslonej œcie¿ki
	void destroy(long index);//pozbywa siê bitmapy o podanym indeksie w wektorze, oraz ualania pamiêæ któr¹ zajmuje bitmba, usuwa j¹ z wektora
	void copy(long id1, long id2);//kopiuje bitmapê z indeksem id1 do indeksu id2
	ALLEGRO_BITMAP* retrieve(long index);//pobiera wskaŸnik na bitmapê, który mo¿na potrm u¿yæ w innych funkcjach

	ALLEGRO_BITMAP* getBitmap();
	
};