#include "Enemy.h"

using namespace std;

void Enemy::onCollisionWith(SpritePtr other)
{
    if (dynamic_pointer_cast<Projectile>(other) && !dead){
        dead = true;
        eng.remove(shared_from_this());
    }
}
