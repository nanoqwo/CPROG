#include "Bullet.h"
#include "Player.h"
#include "GameEngine.h"

void Bullet::tick() {
    move(0,5);
        if (getRect().y > cnts::gScreenHeight){
           eng.remove(shared_from_this());
        }
}

void Bullet::onCollisionWith(SpritePtr other) {
    if(std::dynamic_pointer_cast<Player>(other)){
        eng.remove(shared_from_this());
    }
}