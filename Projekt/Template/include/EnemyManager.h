#pragma once
#include "Sprite.h"
#include "Enemy.h"

class EnemyManager : public Sprite {
public:
    EnemyManager() : Sprite("Bullet.png", -10, 0) {}

    void tick() override {
        Enemy::toDrop = false;
        Enemy::wallHitThisFrame = false;
    }
};
