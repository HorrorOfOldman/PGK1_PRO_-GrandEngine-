#pragma once
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/allegro_image.h>
#include <vector>

using namespace std;

/**
 * @class BitmapHandler
 * @brief Klasa do zarz¹dzania bitmapami w bibliotece Allegro.
 */
class BitmapHandler
{
private:
    /**
     * @brief Wektor przechowuj¹cy wskaŸniki na bitmapy.
     */
    vector<ALLEGRO_BITMAP*> bitmapy;

    /**
     * @brief WskaŸnik na aktualnie u¿ywan¹ bitmapê.
     */
    ALLEGRO_BITMAP* bitmap;

public:
    /**
     * @brief Konstruktor klasy BitmapHandler.
     */
    BitmapHandler() {};

    /**
     * @brief Destruktor klasy BitmapHandler.
     * Usuwa zasoby przypisane do bitmap.
     */
    ~BitmapHandler();

    /**
     * @brief £aduje bitmapê z pliku.
     *
     * @param image Œcie¿ka do pliku obrazu.
     * @return Indeks za³adowanej bitmapy w wektorze, lub -1 w przypadku b³êdu.
     */
    long load(const char* image);

    /**
     * @brief Zapisuje bitmapê do pliku o domyœlnej nazwie.
     *
     * @param index Indeks bitmapy w wektorze.
     */
    void save(long index);

    /**
     * @brief Zapisuje bitmapê do okreœlonej œcie¿ki.
     *
     * @param index Indeks bitmapy w wektorze.
     * @param src Œcie¿ka, do której bitmapa zostanie zapisana.
     */
    void save(long index, const char* src);

    /**
     * @brief Usuwa bitmapê z pamiêci i wektora.
     *
     * @param index Indeks bitmapy w wektorze do usuniêcia.
     */
    void destroy(long index);

    /**
     * @brief Kopiuje wskaŸnik bitmapy z jednego indeksu na inny.
     *
     * @param id1 Indeks bitmapy Ÿród³owej.
     * @param id2 Indeks bitmapy docelowej.
     */
    void copy(long id1, long id2);

    /**
     * @brief Rysuje bitmapê na ekranie.
     *
     * @param id Indeks bitmapy w wektorze.
     * @param x Pozycja X, w której bitmapa zostanie narysowana.
     * @param y Pozycja Y, w której bitmapa zostanie narysowana.
     * @param flags Flagi rysowania (domyœlnie 0).
     */
    void draw(long id, float x, float y, int flags = 0);

    /**
     * @brief Rysuje fragment bitmapy na ekranie.
     *
     * @param index Indeks bitmapy w wektorze.
     * @param x Pozycja X, w której fragment bitmapy zostanie narysowany.
     * @param y Pozycja Y, w której fragment bitmapy zostanie narysowany.
     * @param sx Pozycja X w bitmapie Ÿród³owej, od której zaczyna siê fragment.
     * @param sy Pozycja Y w bitmapie Ÿród³owej, od której zaczyna siê fragment.
     * @param width Szerokoœæ fragmentu bitmapy.
     * @param height Wysokoœæ fragmentu bitmapy.
     * @param flags Flagi rysowania (domyœlnie 0).
     */
    void scrapdraw(long index, float x, float y, float sx, float sy, float width, float height, int flags = 0);

    /**
     * @brief Pobiera wskaŸnik na bitmapê o podanym indeksie.
     *
     * @param index Indeks bitmapy w wektorze.
     * @return WskaŸnik na bitmapê, lub nullptr w przypadku b³êdnego indeksu.
     */
    ALLEGRO_BITMAP* retrieve(long index);

    /**
     * @brief Zwraca wskaŸnik na aktualnie u¿ywan¹ bitmapê.
     *
     * @return WskaŸnik na bitmapê.
     */
    ALLEGRO_BITMAP* getBitmap();
};
