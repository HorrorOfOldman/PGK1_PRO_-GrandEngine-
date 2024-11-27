#pragma once

/**
 * @class GameObject
 * @brief Klasa bazowa reprezentuj¹ca obiekt gry.
 *
 * Jest to klasa abstrakcyjna, która zapewnia interfejs do inicjalizacji, usuwania oraz innych operacji na obiektach gry.
 */
class GameObject
{
public:
    /**
     * @brief Wirtualny destruktor.
     * Zostanie wywo³any podczas usuwania obiektu pochodnego.
     */
    virtual ~GameObject() = default;
};
