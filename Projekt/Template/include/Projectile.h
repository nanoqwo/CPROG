#pragma once
#include "Sprite.h"

class Projectile : public Sprite{
    public:
    Projectile(int x, int y) : Sprite("football.png", x, y){}

    //TODO
    void tick() override{}

};