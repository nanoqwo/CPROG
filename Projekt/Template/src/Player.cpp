#include "Player.h"

/*void Player::tick() {

}*/

void Player::onKeyDown(const SDL_Event &event)
{
    if(event.key.key == SDLK_SPACE){
        SpritePtr bullet = SpritePtr(new Projectile(getRect().x + (getRect().w/2), getRect().y));
        eng.add(bullet);
    }
}

void Player::onKeyLeft(const SDL_Event &event) {
    if(getRect().x > 0){
    move(-10, 0);
    }
}

void Player::onKeyRight(const SDL_Event &event) {
    if(getRect().x < cnts::gScreenWidth - getRect().w){
        move(10, 0);
    }
}

void Player::onCollisionWith(SpritePtr other) {
    takeDamage();
    if(gameOver){
        
    }
}

void Player::takeDamage() {
    --lives;
    if(lives == 0){
        gameOver == true;
    }
}
