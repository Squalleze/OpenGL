#include "main.hpp"

using namespace std;

int main(void) {
  // setup
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    cerr << SDL_GetError() << endl;
    return 1;
  }

  // version check
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  #ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
  #endif

  SDL_GL_SetSwapInterval(1);
  // end setup

  Game *game = new Game();
  
  game->Init();
  // main loop
  SDL_Event event;

  while (game->IsRunning()) {
    if (SDL_PollEvent(&event))
      game->HandleEvent(&event);

    game->Tick();
    game->Render();
  }

  game->Quit();
  SDL_Quit();

  return 0;
}