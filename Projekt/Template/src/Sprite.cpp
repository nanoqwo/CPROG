#include "GameEngine.h"
#include "Sprite.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

using namespace std;

Sprite::Sprite(string name, float x, float y)
{
    image = IMG_LoadTexture(eng.getRen(), (cnts::gResPath + "images/" + name).c_str());
    if (!image)
    {
        cerr << "No such file: " << name << endl;
        exit(EXIT_FAILURE);
    }
    rect = {x, y, static_cast<float>(image->w), static_cast<float>(image->h)};
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(image);
    image = nullptr;
}

void Sprite::draw() const
{
    SDL_RenderTexture(eng.getRen(), image, nullptr, &rect);
}

bool Sprite::collidedWith(SpritePtr other) const
{
    return SDL_HasRectIntersectionFloat(&rect, &other->rect);
}