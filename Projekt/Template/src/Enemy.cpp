#include "Enemy.h"
#include "Bullet.h"
#include "Projectile.h"
#include "Player.h"
#include "Constants.h"
#include "GameEngine.h"

using namespace std;

//TODO: Korrigera rörelse, färre bullets
//enemy.png = 150px x 150px

int Enemy::direction = 1;
bool Enemy::drop = false;
vector<Enemy*> Enemy::enemies;

//every certain amount of frames, drop or move enemies
//obs. frames needs to be changed to SDL_GetTciks() to behave according to time passed in-game

Enemy::Enemy(std::string name, float x, float y) : Sprite(name, x, y)
{
    shootTimer = 200 + rand() % 500;
    alive = true;
    enemies.push_back(this);
}

void Enemy::tick() {    
    if (--shootTimer <= 0) {
        float x = getRect().x + getRect().w / 2;
        float y = getRect().y + getRect().h;

        SpritePtr bullet = SpritePtr(new Bullet(x, y));
        eng.add(bullet);

        shootTimer = 200 + rand() % 500;
    }

    //erm
    frames++;
    if (frames >= 30) {
        frames = 0;
        moveAll();
    }
}

void Enemy::moveAll() {
    //player has cleared all enemies
    if (enemies.empty()) { return; }

    for (Enemy* e : enemies) {
        e->move(10 * direction, 0);
    }

    for (Enemy* e : enemies) {
        if (e->getRect().x <= 20 || e->getRect().x + e->getRect().w >= cnts::gScreenWidth - 20) {
            drop = true;
            direction = -direction;
        }
    }

    if (drop) {
        for (Enemy* e : enemies) {
            e->move(0, 75);
            drop = false;
        }
    }
}

void Enemy::onCollisionWith(SpritePtr other) {
    //remove dead enemies
    for (size_t i = 0; i < enemies.size(); ) {
        if (!enemies[i]->alive) {
            enemies.erase(enemies.begin() + i);
        } else {
            ++i;
        }
    }
    
    if (dynamic_pointer_cast<Projectile>(other)) {
        alive = false;
        eng.remove(shared_from_this());
    }
    
    //Enemy "hitbox" hits player "hitbox"
    if (dynamic_pointer_cast<Player>(other)) {
        float enemyHitbox = getRect().y + getRect().h;
        float playerHitbox = other->getRect().y;

        if (enemyHitbox >= playerHitbox) {
            eng.remove(shared_from_this());               
        }
    }
}