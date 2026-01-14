#pragma once
#include "Sprite.h"

class Enemy : public Sprite {
    public:
        Enemy(std::string name, float x, float y);        
        void onCollisionWith(SpritePtr other) override;
        void tick() override;
        void shoot();

    private: 
        int shootTimer;

        static bool edgeHit;
        static int direction;

        static constexpr float WALL   = 10.0f;
};