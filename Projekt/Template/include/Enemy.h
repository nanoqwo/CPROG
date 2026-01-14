#pragma once
#include "Sprite.h"
#include "GameEngine.h"
#include "Bullet.h"
#include <string>
#include <memory>

class Enemy : public Sprite {
    public:
        Enemy(float x, float y) : Sprite("football.png", x, y) {}
        
        bool isDead() const { return dead; }
        bool hitEdge() const { return hitRightEdge; }

        void onCollisionWith(SpritePtr other) override;
        void tick() override;
        void shoot();

    private: 
        static bool hitRightEdge;
        bool dead = false;
        int direction = 1;

        int waitTime = resetWait;
        int bulletTime = resetBullet;

        int resetWait = 10;
        int resetBullet = 1200 + rand() % 120;

};