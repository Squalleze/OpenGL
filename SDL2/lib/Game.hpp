#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#define GL3_PROTOTYPES 1
#include <GL/glew.h>

class Game {
  private:
    SDL_Window *window;
    SDL_GLContext context;
    bool isRunning = true;

    void Throw(const char *);
  public:
    bool inline IsRunning() const { return isRunning; };

    Game();
    ~Game();
    bool Init();
    bool Tick();
    bool Render();
    bool HandleEvent(SDL_Event *);
    bool Quit();
};