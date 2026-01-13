#include "Enemy.h"

using namespace std;

void Enemy::onCollisionWith(SpritePtr other)
{
    if (dynamic_pointer_cast<Projectile>(other) && !dead){
        eng.remove(shared_from_this());
        dead = true;
    }
}

void Enemy::tick() {
    if (getRect().x >= cnts::gScreenWidth - getRect().w || getRect().x <= 0) {
        direction = -direction;
        move(0, static_cast<int>(getRect().h * 0.5f)); //moves half a sprite down
    }
    move(5 * direction, 0);
    
    if (timer == 0) {
        shoot();
        timer = reset;
    }

}

void Enemy::shoot()
{
    float posX = getRect().x + getRect().w / 2;
    float posY = getRect().y + getRect().h;

    SpritePtr spr = SpritePtr(new Projectile(posX, posY));
}
