#include "Projectile.h"
#include "Enemy.h"
#include "GameEngine.h"

void Projectile::tick() {
    move(0,-5);
        if (getRect().y < 0){
           eng.remove(shared_from_this());
        }
}

void Projectile::onCollisionWith(SpritePtr other) {
    if(std::dynamic_pointer_cast<Enemy>(other)){
        eng.remove(shared_from_this());
    }
}
