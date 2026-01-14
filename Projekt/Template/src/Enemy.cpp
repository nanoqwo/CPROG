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
    shootTimer = 100 + (rand() % 300 - 100 + 1);
}

void Enemy::onCollisionWith(SpritePtr other) {
    //Enemy "hitbox" hits player "hitbox"
    if (dynamic_pointer_cast<Player>(other)) {
        float enemyHitbox = getRect().y + getRect().h;
        float playerHitbox   = other->getRect().y;

        if (enemyHitbox >= playerHitbox) {
            eng.remove(shared_from_this());               
        }
    }
    
    if (dynamic_pointer_cast<Projectile>(other)) {
        eng.remove(shared_from_this());
    }
}

void Enemy::tick() {
    move(5 * direction, 0);

    if (getRect().x <= WALL || getRect().x + getRect().w >= cnts::gScreenWidth - WALL) {
        edgeHit = true;
    }

    if (edgeHit){
        move(0, getRect().h * 0.5f);
        direction = -direction;
        edgeHit = false;
    }
    
    if (--shootTimer <= 0) {
        shoot();
        shootTimer = 100 + (rand() % 300 - 100 + 1);
    }
}

void Enemy::shoot()
{
    float x = getRect().x + getRect().w / 2;
    float y = getRect().y + getRect().h;

    SpritePtr spr = SpritePtr(new Bullet(x, y));
    eng.add(spr);
}
