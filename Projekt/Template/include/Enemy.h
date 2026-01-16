#pragma once
#include "Sprite.h"
#include <vector>

class Enemy : public Sprite {
    public:
        Enemy(std::string name, float x, float y);        

        void tick() override;
        void onCollisionWith(SpritePtr other) override;

        void moveAll();

    private:
        int shootTimer;
        bool alive;

        static int direction;
        static bool drop;
        int frames;
        static std::vector<Enemy*> enemies;
};