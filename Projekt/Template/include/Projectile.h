#pragma once
#include "Sprite.h"
#include "GameEngine.h"

class Projectile : public Sprite{
    public:
    Projectile(int x, int y) : Sprite("Projectile.png", x, y){}

    //TODO
    void tick() override;

};