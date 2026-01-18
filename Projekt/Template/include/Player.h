#pragma once
#include "Sprite.h"
#include "GameEngine.h"

class Player: public Sprite {
    public:
    Player() : Sprite(cnts::rocketcolor_str, cnts::gScreenWidth/2, cnts::gScreenHeight - 150 ){}
    void tick() override;

    void onKeyDown(const SDL_Event &event) override;
    void onKeyLeft(const SDL_Event &event) override;
    void onKeyRight(const SDL_Event &event) override;

    void onCollisionWith(SpritePtr other) override;
    
    private:
    int lives = 5;
    bool gameOver = false;
    bool damaged = false;

    int coolDown = 0;
    const int coolDownTimer = 30; 

    int hurtTimer = 0;
    const int hurtDuration = 11;

    void takeDamage(int = 1);

};