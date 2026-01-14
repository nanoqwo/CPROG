#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "projectile.h"
#include <memory>

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
    //dynamic pointer to either the enemy (instant gameover) or the bullet (--lives)
    if (std::dynamic_pointer_cast<Bullet>(other) && !gameOver){
        takeDamage();
        if(gameOver) {
            eng.remove(shared_from_this());
            eng.showPopUp("Game Over", "You died!");
        }
    } // if
    else if(std::dynamic_pointer_cast<Enemy>(other) && !gameOver){
        eng.remove(shared_from_this());
        eng.showPopUp("Game Over", "You died!");
    }
    
}

void Player::takeDamage() {
    --lives;
    if(lives == 0){
        gameOver = true;
    }
}
