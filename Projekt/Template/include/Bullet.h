#pragma once
#include "GameEngine.h"
#include "Sprite.h"

class Bullet : public Sprite {
    public:
        Bullet(float x, float y) : Sprite(cnts::bullet_str, x , y) {}

        void tick() override;
        void onCollisionWith(SpritePtr other) override;
};