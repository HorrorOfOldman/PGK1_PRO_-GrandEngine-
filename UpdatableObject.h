#pragma once
#include "GameObject.h"

/**
 * @class UpdatableObject
 * @brief Interfejs do obiekt�w, kt�re mog� by� aktualizowane w czasie.
 *
 * Klasa `UpdatableObject` reprezentuje obiekt, kt�ry mo�e by� aktualizowany w ka�dej klatce gry,
 * na przyk�ad do zmiany stanu, pozycji, animacji itp.
 * Klasa ta jest abstrakcyjna i wymaga implementacji metody `Update` przez klasy pochodne.
 */
class UpdatableObject : public virtual GameObject {
public:

    /**
     * @brief Aktualizuje obiekt na podstawie up�ywu czasu.
     *
     * Metoda ta jest wywo�ywana na ka�dym cyklu gry i pozwala na aktualizacj� stanu obiektu,
     * w tym np. ruchu, animacji czy innych zmian zwi�zanych z up�ywem czasu.
     *
     * @param DT Czas, kt�ry up�yn�� od ostatniej klatki (delta time), wykorzystywany do aktualizacji obiektu.
     */
    virtual void Update(float DT) = 0;
};
