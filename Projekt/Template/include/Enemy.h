#pragma once
#include "Sprite.h"
#include <vector>

class Enemy : public Sprite {
    public:
        Enemy(std::string name, float x, float y);

        void tick() override;
        void onCollisionWith(SpritePtr other) override;

        void moveAll();
        static void reset();

    private:
        int shootTimer;
        bool alive;

        static int direction;
        static bool drop;
        static Uint32 frame;
        static std::vector<Enemy*> enemies;
};