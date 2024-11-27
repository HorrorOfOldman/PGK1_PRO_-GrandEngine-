#pragma once

/**
 * @class GameObject
 * @brief Klasa bazowa reprezentuj�ca obiekt gry.
 *
 * Jest to klasa abstrakcyjna, kt�ra zapewnia interfejs do inicjalizacji, usuwania oraz innych operacji na obiektach gry.
 */
class GameObject
{
public:
    /**
     * @brief Wirtualny destruktor.
     * Zostanie wywo�any podczas usuwania obiektu pochodnego.
     */
    virtual ~GameObject() = default;
};
