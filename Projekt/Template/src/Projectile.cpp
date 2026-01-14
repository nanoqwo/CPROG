#include "Projectile.h"

void Projectile::tick() {
    move(0,-5);
        if (getRect().y < 0){
           eng.remove(shared_from_this());
        }
}