#pragma once
#include <allegro5/allegro.h>  
#include <vector>
#include <string>

using namespace std;

/**
 * @class AnimatedObject
 * @brief Klasa odpowiedzialna za zarz¹dzanie animacjami obiektów, przechowuj¹ca listê klatek animacji oraz zarz¹dzaj¹ca ich odtwarzaniem.
 */
class AnimatedObject
{
private:
    /**
     * @brief Lista przechowuj¹ca œcie¿ki do obrazów reprezentuj¹cych klatki animacji.
     */
    vector<string> FPS;

    /**
     * @brief Indeks aktualnej klatki animacji.
     */
    size_t ActFps;

public:
    /**
     * @brief Konstruktor domyœlny. Inicjalizuje pust¹ animacjê.
     */
    AnimatedObject();

    /**
     * @brief Konstruktor z inicjalizacj¹ listy klatek animacji.
     * @param fps Lista œcie¿ek do obrazów klatek animacji.
     */
    AnimatedObject(const vector<string>& fps);

    /**
     * @brief Ustawia listê klatek animacji.
     * @param fps Lista œcie¿ek do obrazów klatek animacji.
     */
    void setFPS(const vector<string>& fps);

    /**
     * @brief Zwraca œcie¿kê do aktualnej klatki animacji.
     * @return Œcie¿ka do aktualnej klatki.
     */
    const string& readActualFrame() const;

    /**
     * @brief Przechodzi do nastêpnej klatki animacji.
     * Je¿eli aktualna klatka jest ostatnia, animacja przechodzi do pierwszej klatki.
     */
    void NextFrame();
};
