#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "projectile.h"
#include <memory>

void Player::tick() {
    if(coolDown>0) --coolDown;
}

void Player::onKeyDown(const SDL_Event &event)
{
    if(event.key.key == SDLK_SPACE && coolDown == 0){

        int bulletX = getRect().x + getRect().w / 2;
        int bulletY = getRect().y;
        SpritePtr bullet = SpritePtr(new Projectile(bulletX, bulletY));
        eng.add(bullet);

        coolDown = coolDownTimer;
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
    } // if
    else if(std::dynamic_pointer_cast<Enemy>(other) && !gameOver){
        takeDamage(lives);
    }
    
}

void Player::takeDamage(int damage) {
    lives-=damage;
    if(lives == 0){
        eng.remove(shared_from_this());
        eng.clearScreen();
        eng.showPopUp("Game Over", "You died!");
        gameOver = true;
    }
}
