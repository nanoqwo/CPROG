#pragma once
#include "Sprite.h"
#include "GameEngine.h"
#include "Projectile.h"
#include <string>
#include <memory>

class Enemy : public Sprite {
    public:
        Enemy(std::string name, float x, float y) : Sprite(name, x, y) {}
        
        bool isDead() const { return dead; }

        void onCollisionWith(SpritePtr other) override;
        void tick() override;
        void shoot();

    private: 
        bool dead = false;
        int direction = 1;

        int reset = 300 + rand() % 120;
        int timer = reset;         // individual timer for when enemy shoots
        //static int globalTimer;  // global timer for enemies to keep track of when last enemy shot


};