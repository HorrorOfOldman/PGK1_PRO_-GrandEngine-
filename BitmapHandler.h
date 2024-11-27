#pragma once
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/allegro_image.h>
#include <vector>

using namespace std;

/**
 * @class BitmapHandler
 * @brief Klasa do zarz�dzania bitmapami w bibliotece Allegro.
 */
class BitmapHandler
{
private:
    /**
     * @brief Wektor przechowuj�cy wska�niki na bitmapy.
     */
    vector<ALLEGRO_BITMAP*> bitmapy;

    /**
     * @brief Wska�nik na aktualnie u�ywan� bitmap�.
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
     * @brief �aduje bitmap� z pliku.
     *
     * @param image �cie�ka do pliku obrazu.
     * @return Indeks za�adowanej bitmapy w wektorze, lub -1 w przypadku b��du.
     */
    long load(const char* image);

    /**
     * @brief Zapisuje bitmap� do pliku o domy�lnej nazwie.
     *
     * @param index Indeks bitmapy w wektorze.
     */
    void save(long index);

    /**
     * @brief Zapisuje bitmap� do okre�lonej �cie�ki.
     *
     * @param index Indeks bitmapy w wektorze.
     * @param src �cie�ka, do kt�rej bitmapa zostanie zapisana.
     */
    void save(long index, const char* src);

    /**
     * @brief Usuwa bitmap� z pami�ci i wektora.
     *
     * @param index Indeks bitmapy w wektorze do usuni�cia.
     */
    void destroy(long index);

    /**
     * @brief Kopiuje wska�nik bitmapy z jednego indeksu na inny.
     *
     * @param id1 Indeks bitmapy �r�d�owej.
     * @param id2 Indeks bitmapy docelowej.
     */
    void copy(long id1, long id2);

    /**
     * @brief Rysuje bitmap� na ekranie.
     *
     * @param id Indeks bitmapy w wektorze.
     * @param x Pozycja X, w kt�rej bitmapa zostanie narysowana.
     * @param y Pozycja Y, w kt�rej bitmapa zostanie narysowana.
     * @param flags Flagi rysowania (domy�lnie 0).
     */
    void draw(long id, float x, float y, int flags = 0);

    /**
     * @brief Rysuje fragment bitmapy na ekranie.
     *
     * @param index Indeks bitmapy w wektorze.
     * @param x Pozycja X, w kt�rej fragment bitmapy zostanie narysowany.
     * @param y Pozycja Y, w kt�rej fragment bitmapy zostanie narysowany.
     * @param sx Pozycja X w bitmapie �r�d�owej, od kt�rej zaczyna si� fragment.
     * @param sy Pozycja Y w bitmapie �r�d�owej, od kt�rej zaczyna si� fragment.
     * @param width Szeroko�� fragmentu bitmapy.
     * @param height Wysoko�� fragmentu bitmapy.
     * @param flags Flagi rysowania (domy�lnie 0).
     */
    void scrapdraw(long index, float x, float y, float sx, float sy, float width, float height, int flags = 0);

    /**
     * @brief Pobiera wska�nik na bitmap� o podanym indeksie.
     *
     * @param index Indeks bitmapy w wektorze.
     * @return Wska�nik na bitmap�, lub nullptr w przypadku b��dnego indeksu.
     */
    ALLEGRO_BITMAP* retrieve(long index);

    /**
     * @brief Zwraca wska�nik na aktualnie u�ywan� bitmap�.
     *
     * @return Wska�nik na bitmap�.
     */
    ALLEGRO_BITMAP* getBitmap();
};
