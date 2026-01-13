#pragma once
#include "Sprite.h"

class Projectile : public Sprite{
    public:
    Projectile(float x, float y) : Sprite("bullet.png", x, y) {}

    //TODO
    void tick() override{}

};