#include "Enemy.h"

using namespace std;

void Enemy::onCollisionWith(SpritePtr other)
{
    if (dynamic_pointer_cast<Bullet>(other) && !dead){
        eng.remove(shared_from_this());
        dead = true;
    }
}

void Enemy::tick() {
    if (waitTime > 0) {
        --waitTime;
        return;
    } 

    if (getRect().x <= 0 || getRect().x + getRect().w >= cnts::gScreenWidth) {
        hitRightEdge = true;
    }

    if (hitRightEdge) {
        direction = -direction;
        move(0, static_cast<int>(getRect().h * 0.5f));
    } else {
        move(5*direction, 0);
    }

    if (bulletTime <= 0) {
        shoot();
        bulletTime = resetBullet;
    }
    --bulletTime;
    
}

void Enemy::shoot()
{
    float posX = getRect().x + getRect().w / 2;
    float posY = getRect().y + getRect().h;

    SpritePtr spr = SpritePtr(new Bullet(posX, posY));
    eng.add(spr);
}
