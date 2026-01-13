#include "Enemy.h"
#include "Projectile.h"

using namespace std;

class Enemy : public Sprite {


    void Enemy::onCollisionWith(SpritePtr other) {
        if (dynamic_pointer_cast<Projectile>(other) && !dead){
            dead = true;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Grattis!", "Mål!", eng.getWin());
            eng.remove(shared_from_this());
        } // if
    }
};