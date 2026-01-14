#include "Enemy.h"
#include "Bullet.h"
#include "Projectile.h"
#include "Player.h"
#include "GameEngine.h"

using namespace std;

bool Enemy::edgeHit     = false;
int Enemy::direction    = 1;

Enemy::Enemy(std::string name, float x, float y) : Sprite(name, x, y)
{
    shootTimer = 100 + (rand() % (rand() % 300 - 100 + 1));
}

void Enemy::onCollisionWith(SpritePtr other) {
    if (dynamic_pointer_cast<Projectile>(other)) {
        float enemyBottom = getRect().y + getRect().h;
        float playerTop   = other->getRect().y;

        if (enemyBottom >= playerTop) {
            eng.remove(shared_from_this());               
        }
    }
}

void Enemy::tick() {
    move(5 * direction, 0);

    if (getRect().x <= WALL || getRect().x + getRect().w >= cnts::gScreenWidth - WALL) {
        edgeHit = true;
    }

    if (edgeHit) {
        move(0, getRect().h * 0.5f);
    }

    if (edgeHit){
        direction = -direction;
        edgeHit = false;
    }
    
    if (shootTimer <= 0) {
        shoot();
        shootTimer = 100 + (rand() % 300 - 100 + 1);
    }
    --shootTimer;
}

void Enemy::shoot()
{
    float x = getRect().x + getRect().w / 2;
    float y = getRect().y + getRect().h;

    SpritePtr spr = SpritePtr(new Bullet(x, y));
    eng.add(spr);
}
