#pragma once
#include "Sprite.h"
#include "GameEngine.h"
#include "projectile.h"

class Player: public Sprite {
    public:
    Player(std::string fileName) : Sprite(fileName,600, 500){}
    void tick() override{};

    void onKeyDown(const SDL_Event &event) override;
    void onKeyLeft(const SDL_Event &event) override;
    void onKeyRight(const SDL_Event &event) override;

    void onCollisionWith(SpritePtr other) override;
    
    private:
};