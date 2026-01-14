#include "Enemy.h"
#include "Bullet.h"
#include "Projectile.h"
#include "Player.h"
#include "GameEngine.h"

using namespace std;

//TODO: Långsammare bevegelse, färre bullets

int Enemy::direction    = 1;
float Enemy::drop       = 0.5f;
bool Enemy::toDrop = false;
bool Enemy::wallHitThisFrame = false;

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
    //maybe possible to do it 
    move(5 * direction, 0);

    bool hitWall = getRect().x <= WALL || 
        getRect().x + getRect().w >= cnts::gScreenWidth - WALL;

    if (hitWall && !wallHitThisFrame) {
        wallHitThisFrame = true;
        toDrop = true;
        direction = -direction;
    }

    if (toDrop) {
        move(0, getRect().h * drop);
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
