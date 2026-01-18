#include "Enemy.h"
#include "Bullet.h"
#include "Projectile.h"
#include "Player.h"
#include "GameEngine.h"

using namespace std;

//TODO: Korrigera rörelse, färre bullets
//enemy.png = 150px x 150px

int Enemy::direction = 1;
bool Enemy::drop = false;
Uint32  Enemy::frame = 0;
vector<Enemy*> Enemy::enemies;

//every certain amount of frames, drop or move enemies
//obs. frames needs to be changed to SDL_GetTciks() to behave according to time passed in-game

Enemy::Enemy(string name, float x, float y) : Sprite(name, x, y)
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

    Uint32 currentFrame = SDL_GetTicks();


    if (currentFrame - frame >= 30) {
        moveAll();
        frame = currentFrame;
    }
}

void Enemy::moveAll() {
    //player has won
    if (enemies.empty()) { 
        return; 
    }

    for (Enemy* e : enemies) {
        e->move(2 * direction, 0);
    }

    for (Enemy* e : enemies) {
        if (e->getRect().x <= 20 || e->getRect().x + e->getRect().w >= cnts::gScreenWidth - 20) {
            drop = true;
            direction = -direction;
            break;
        }
    }

    if (drop) {
        for (Enemy* e : enemies) {
            e->move(0, 75);
            drop = false;
        }
    }
}

void Enemy::reset()
{
    Enemy::enemies.clear();
    Enemy::direction = 1;
    Enemy::drop = false;
    Enemy::frame = 0;

}

void Enemy::onCollisionWith(SpritePtr other) {

    if (dynamic_pointer_cast<Projectile>(other)) {
        alive = false;
        if(enemies.size() == 0){
            eng.remove(shared_from_this());
            Enemy::reset();    
            eng.endScreen("Game Over", "You WON");
        }
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

    //remove dead enemies
    for (size_t i = 0; i < enemies.size(); ) {
        if (!enemies[i]->alive) {
            enemies.erase(enemies.begin() + i);
        } else {
            ++i;
        }
    }
}