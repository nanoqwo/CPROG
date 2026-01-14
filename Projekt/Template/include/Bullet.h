#pragma once
#include "Sprite.h"

class Bullet : public Sprite {
    public:
        Bullet(float x, float y) : Sprite("Bullet.png", x , y) {}

        void tick() override;
};