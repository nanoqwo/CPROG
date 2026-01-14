#pragma once
#include "Sprite.h"

class Projectile : public Sprite{
    public:
    Projectile(int x, int y) : Sprite("Projectile.png", x, y){}

    void tick() override;
    void onCollisionWith(SpritePtr other);

};