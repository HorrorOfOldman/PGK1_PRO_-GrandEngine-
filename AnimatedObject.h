#pragma once
#include <allegro5/allegro.h>  
#include <vector>
#include <string>

using namespace std;

/**
 * @class AnimatedObject
 * @brief Klasa odpowiedzialna za zarz�dzanie animacjami obiekt�w, przechowuj�ca list� klatek animacji oraz zarz�dzaj�ca ich odtwarzaniem.
 */
class AnimatedObject
{
private:
    /**
     * @brief Lista przechowuj�ca �cie�ki do obraz�w reprezentuj�cych klatki animacji.
     */
    vector<string> FPS;

    /**
     * @brief Indeks aktualnej klatki animacji.
     */
    size_t ActFps;

public:
    /**
     * @brief Konstruktor domy�lny. Inicjalizuje pust� animacj�.
     */
    AnimatedObject();

    /**
     * @brief Konstruktor z inicjalizacj� listy klatek animacji.
     * @param fps Lista �cie�ek do obraz�w klatek animacji.
     */
    AnimatedObject(const vector<string>& fps);

    /**
     * @brief Ustawia list� klatek animacji.
     * @param fps Lista �cie�ek do obraz�w klatek animacji.
     */
    void setFPS(const vector<string>& fps);

    /**
     * @brief Zwraca �cie�k� do aktualnej klatki animacji.
     * @return �cie�ka do aktualnej klatki.
     */
    const string& readActualFrame() const;

    /**
     * @brief Przechodzi do nast�pnej klatki animacji.
     * Je�eli aktualna klatka jest ostatnia, animacja przechodzi do pierwszej klatki.
     */
    void NextFrame();
};
