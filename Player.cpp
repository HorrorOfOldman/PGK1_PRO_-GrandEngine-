#include "Player.h"
#include <allegro5/allegro_primitives.h>

void Player::update() {
    // Implementacja sterowania (np. klawiatura)
}

void Player::draw() {
    al_draw_filled_circle(position.getX(), position.getY(), 10, al_map_rgb(255, 0, 0));
}

void Player::translate(float dx, float dy) {
    position.translate(dx, dy);
}

void Player::rotate(float angle) {
    position.rotate(angle);
}

void Player::scale(float sx, float sy) {
    position.scale(sx, sy);
}
