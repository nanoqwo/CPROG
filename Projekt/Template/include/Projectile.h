#pragma once
#include "GameEngine.h"
#include "Sprite.h"

class Projectile : public Sprite{
    public:
    Projectile(int x, int y) : Sprite(cnts::projectile_str, x, y){}

    void tick() override;
    void onCollisionWith(SpritePtr other);

};