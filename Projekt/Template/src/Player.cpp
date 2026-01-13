#include "Player.h"

/*void Player::tick() {

}*/

void Player::onKeyDown(const SDL_Event &event) {
    if(event.key.key == SDLK_SPACE){
        SpritePtr bullet = SpritePtr(new Projectile(event.button.x));
        eng.add(bullet);
    }
}

void Player::onKeyLeft(const SDL_Event &event) {

}

void Player::onKeyRight(const SDL_Event &event) {

}

void Player::onCollisionWith(SpritePtr other) {

}
