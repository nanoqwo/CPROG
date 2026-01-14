#pragma once
#include "Sprite.h"

class Enemy : public Sprite {
    public:
        Enemy(std::string name, float x, float y);        
        
        void onCollisionWith(SpritePtr other) override;
        void tick() override;
        void shoot();

        static bool toDrop;
        static bool wallHitThisFrame;
    private: 
    static int direction;
    static float drop;
    
    const float WALL   = 10.0f;
    int shootTimer;
};