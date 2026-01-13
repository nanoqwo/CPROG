#pragma once
#include "Sprite.h"

class Projectile : public Sprite{
    public:
    Projectile(float x, float y) : Sprite("bullet.png", x, y) {}
=======
    Projectile(int x, int y) : Sprite("football.png", x, y){}
>>>>>>> Stashed changes

    //TODO
    void tick() override{}

};