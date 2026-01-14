#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include <memory>
#include "Constants.h"

namespace cnts = constants;

class Sprite;
typedef std::shared_ptr<Sprite> SpritePtr;

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();

    void add(SpritePtr spr);
    void remove(SpritePtr spr);

    void run();

    SDL_Renderer *getRen() const { return ren; }
    SDL_Window *getWin() const { return win; }

    SDL_Texture* loadTexture(const std::string& filename);
    void setBackground(SDL_Texture* texture);

private:
    SDL_Window *win;
    SDL_Renderer *ren;
    SDL_Texture *background = nullptr;
    std::vector<SpritePtr> sprites, added, removed;

    bool running{ false };

    void handleEvents();
    void render();
};

extern GameEngine eng;