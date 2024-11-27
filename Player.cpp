#include "Player.h"
#include <iostream>


Player::Player(float SX, float SY)
    : x(SX), y(SY), speed(10), currentFrame(0), frameCounter(0) {
    up = down = left = right = false;

    // £adowanie bitmap
    bitmapIDs.push_back(bit.load("Sp/a0.png")); // Klatka 0
    bitmapIDs.push_back(bit.load("Sp/a1.png")); // Klatka 1
    bitmapIDs.push_back(bit.load("Sp/a2.png")); // Klatka 2
    bitmapIDs.push_back(bit.load("Sp/a3.png")); // Klatka 3
    bitmapIDs.push_back(bit.load("Sp/a4.png")); // Klatka 4
    bitmapIDs.push_back(bit.load("Sp/a5.png")); // Klatka 5
    bitmapIDs.push_back(bit.load("Sp/a6.png")); // Klatka 6
    bitmapIDs.push_back(bit.load("Sp/a7.png")); // Klatka 7

    // Sprawdzenie poprawnoœci za³adowanych bitmap
    for (const auto& id : bitmapIDs) {
        if (id == -1) {
            std::cerr << "B³¹d ³adowania jednej z bitmap gracza!" << std::endl;
        }
    }
}

void Player::update() 
{
    if (up) y -= speed;
    if (down) y += speed;
    if (left) x -= speed;
    if (right) x += speed;

    // Aktualizacja klatki animacji w zale¿noœci od kierunku ruchu
    frameCounter++;
    if (frameCounter >= 10) { // Tempo zmiany klatek
        frameCounter = 0;

        if (up) currentFrame = (currentFrame == 0) ? 1 : 0;        // Góra
        else if (down) currentFrame = (currentFrame == 2) ? 4 : 5; // Dó³
        else if (left) currentFrame = (currentFrame == 4) ? 6 : 7; // Lewo
        else if (right) currentFrame = (currentFrame == 6) ? 2 : 3; // Prawo
    }
}


void Player::draw() 
{
    bit.draw(bitmapIDs[currentFrame], x, y); // Rysowanie aktualnej klatki animacji
}

void Player::keyevent(ALLEGRO_EVENT& ev) {
    if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (ev.keyboard.keycode) {
        case ALLEGRO_KEY_UP: up = true; break;
        case ALLEGRO_KEY_DOWN: down = true; break;
        case ALLEGRO_KEY_LEFT: left = true; break;
        case ALLEGRO_KEY_RIGHT: right = true; break;
        }
    }
    else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
        switch (ev.keyboard.keycode) {
        case ALLEGRO_KEY_UP: up = false; break;
        case ALLEGRO_KEY_DOWN: down = false; break;
        case ALLEGRO_KEY_LEFT: left = false; break;
        case ALLEGRO_KEY_RIGHT: right = false; break;
        }
    }
}

void Player::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}
