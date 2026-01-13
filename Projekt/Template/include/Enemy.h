#pragma once
#include "Sprite.h"
#include <string>
#include <memory>

class Enemy : public Sprite {
    public:
        Enemy();
        Enemy(std::string name, float x, float y) : Sprite(name, x, y) {}
        
        void onCollisionWith(SpritePtr other) override;

        bool getHit() const { return hitRightEnd; }
        bool isDead() const { return dead; }

    private: 
        bool hitRightEnd = false;
        bool dead = false;
};