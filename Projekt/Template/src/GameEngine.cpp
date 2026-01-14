#include "GameEngine.h"
#include "Sprite.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

GameEngine::GameEngine() : win(nullptr), ren(nullptr), running(false)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL Init failed: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    win = SDL_CreateWindow("GameEngine", cnts::gScreenWidth, cnts::gScreenHeight, 0);
    if (!win)
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    ren = SDL_CreateRenderer(win, nullptr);
    if (!ren)
    {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}

GameEngine::~GameEngine()
{
    sprites.clear();
    added.clear();
    removed.clear();

    if(ren)
    {
        SDL_DestroyRenderer(ren);
    }

    if(win)
    {
        SDL_DestroyWindow(win);
    }
    SDL_Quit();
}


SDL_Texture* GameEngine::loadTexture(const std::string& filename) 
{
    SDL_Texture* texture = IMG_LoadTexture(ren, filename.c_str());
    
    if (!texture) {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        std::cerr << "SDL_image Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void GameEngine::setBackground(SDL_Texture* texture) {
    background = texture;
}


void GameEngine::add(SpritePtr spr) {
    added.push_back(spr);
}

void GameEngine::remove(SpritePtr spr) {
    removed.push_back(spr);
}

void GameEngine::handleEvents()
{
    /*while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_EVENT_QUIT:
                running = false; 
                break;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                for(SpritePtr spr : sprites)
                    spr->onMouseDown(event);
                break;
            case SDL_EVENT_KEY_DOWN:
                for (SpritePtr spr : sprites)
                    spr->onKeyDown(event);
                break;
            case SDL_EVENT_KEY_UP:
                for (SpritePtr spr : sprites)
                    spr->onKeyUp(event);
                break;
        // Fler händelser utelämnade för minska kodmängden i exemplet
        } // switch
    } // while event */

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            running = false;
            break;

        case SDL_EVENT_KEY_DOWN:
            if (event.key.key == SDLK_LEFT)
            {
                for (SpritePtr spr : sprites)
                {
                    spr->onKeyLeft(event);
                }
            }
            else if (event.key.key == SDLK_RIGHT)
            {
                for (SpritePtr spr : sprites)
                {
                    spr->onKeyRight(event);
                }
            }

            for (SpritePtr spr : sprites)
            {
                spr->onKeyDown(event);
            }
            break;

        case SDL_EVENT_KEY_UP:
            for (SpritePtr spr : sprites)
            {
                spr->onKeyUp(event);
            }
            break;

        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            for (SpritePtr spr : sprites)
            {
                spr->onMouseDown(event);
            }
            break;

        case SDL_EVENT_MOUSE_BUTTON_UP:
            for (SpritePtr spr : sprites)
            {
                spr->onMouseUp(event);
            }
            break;

        case SDL_EVENT_MOUSE_MOTION:
            for (SpritePtr spr : sprites)
                spr->onMouseMove(event);
            break;
        }
    }
}

void GameEngine::render()
{
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_RenderClear(ren);

    if(background){
        SDL_RenderTexture(ren, background, NULL, NULL);
    }

    for (SpritePtr spr : sprites)
    {
        spr->draw();
    }
    SDL_RenderPresent(ren);
}

void GameEngine::run() {
    const int FPS = 60;
    const int TICKINTERVAL = 1000 / FPS;

    running = true;

    while (running) {
        Uint64 nextTick = SDL_GetTicks() + TICKINTERVAL; 
        
        handleEvents();

        for (SpritePtr spr : sprites)
        {
            spr->tick();
        }

        // Grov kollisionsmekanism, skulle kunna ändras möjligen
        for (SpritePtr spr1 : sprites)
        {
            for (SpritePtr spr2 : sprites)
            {
                if (spr1 != spr2 && spr1->collidedWith(spr2))
                {
                    spr1->onCollisionWith(spr2);
                    spr2->onCollisionWith(spr1);
                }
            }
        }

        for (SpritePtr spr : added) {
            sprites.push_back(spr);
        }
        added.clear();

        for (SpritePtr spr : removed) {
            for (size_t pos = 0; pos < sprites.size(); pos++) {
                auto iter = sprites.begin() + pos;
                if (spr == *iter) {
                    sprites.erase(iter);
                    break;
                }
            }
        }
        removed.clear();

        render();

        Sint64 delay = nextTick - SDL_GetTicks();
        if (delay > 0) {
            SDL_Delay(delay);
        }
    }  
}
GameEngine eng;