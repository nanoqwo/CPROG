#include <SDL3/SDL.h>
#include <iostream>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

SDL_Window* win = nullptr;
SDL_Surface* screenSurface = nullptr;
SDL_Surface* HelloWorld = nullptr;

bool init();
bool loadMedia();
void close();

bool init()
{
    bool success{true};

    if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
        SDL_Log("SDL could not initialize! SDL error: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    else
    {
        win = SDL_CreateWindow("SDL3 Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if (win == nullptr)
        {
            SDL_Log("SDL_CreateWindow error, Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(win);
        }
    }
    return success;
}

bool loadMedia()
{
    bool success{true};

    std::string imagePath{"./resources/images/bg.jpg"};
    if (HelloWorld = SDL_LoadBMP(imagePath.c_str()))
    {
        if (HelloWorld == nullptr)
        {
            SDL_Log("Couldn't load image");
            success = false;
        }
    }
    return success;
}

void close()
{
    SDL_DestroySurface(HelloWorld);
    HelloWorld = nullptr;

    SDL_DestroyWindow(win);
    win = nullptr;
    screenSurface = nullptr;

    SDL_Quit();
}

int main(int argc, char* args []) 
{

    int exitCode{0};

    if (init() == false) 
    {
        SDL_Log("Couldn't initialize program");
        exitCode = 1;
    }
    else 
    {
        if(loadMedia() == false) 
        {
            SDL_Log("Couldn't load media");
            exitCode = 2;
        }
        else //initialization and image loading success
        {
            bool quit{false};

            SDL_Event e;
            SDL_zero(e);

            while (quit == false)
            {
                while(SDL_PollEvent(&e) == true)
                {
                    if (e.type == SDL_EVENT_QUIT)
                    {
                        quit = true;
                    }
                }

                SDL_FillSurfaceRect(screenSurface, nullptr, SDL_MapSurfaceRGB(screenSurface, 0xFF, 0xFF, 0xFF));
                SDL_BlitSurface(HelloWorld, nullptr, screenSurface, nullptr);
                SDL_UpdateWindowSurface(win);

            }
        }
    }
    close();
    return exitCode;
}