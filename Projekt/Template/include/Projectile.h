#pragma once
#include "Sprite.h"

class Projectile : public Sprite{
    public:
    Projectile(int x) : Sprite("bullet.png", x, 400){}

    //TODO
    void tick() override{}

};