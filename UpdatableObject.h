#pragma once
#include "GameObject.h"

/**
 * @class UpdatableObject
 * @brief Interfejs do obiektów, które mog¹ byæ aktualizowane w czasie.
 *
 * Klasa `UpdatableObject` reprezentuje obiekt, który mo¿e byæ aktualizowany w ka¿dej klatce gry,
 * na przyk³ad do zmiany stanu, pozycji, animacji itp.
 * Klasa ta jest abstrakcyjna i wymaga implementacji metody `Update` przez klasy pochodne.
 */
class UpdatableObject : public virtual GameObject {
public:

    /**
     * @brief Aktualizuje obiekt na podstawie up³ywu czasu.
     *
     * Metoda ta jest wywo³ywana na ka¿dym cyklu gry i pozwala na aktualizacjê stanu obiektu,
     * w tym np. ruchu, animacji czy innych zmian zwi¹zanych z up³ywem czasu.
     *
     * @param DT Czas, który up³yn¹³ od ostatniej klatki (delta time), wykorzystywany do aktualizacji obiektu.
     */
    virtual void Update(float DT) = 0;
};
