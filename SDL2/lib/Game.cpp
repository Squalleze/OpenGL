#include "Game.hpp"


Game::Game() {}


Game::~Game() {}


bool Game::Init() {
  window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 427, SDL_WINDOW_OPENGL);
  if (window == nullptr) return false;
  
  context = SDL_GL_CreateContext(window);

  glClearColor(0.0, 0.0, 0.0, 1.0);

  return true;
}


bool Game::Tick() {
  return true;
}


bool Game::Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  glRotatef(0.4f,0.0f,1.0f,0.0f);    // Rotate The cube around the Y axis
  glRotatef(0.2f,1.0f,1.0f,1.0f);
  glColor3f(0.0f,1.0f,0.0f); 

  glBegin( GL_QUADS );
  glVertex3f(-0.5f, 0.0, 0.0);
  glVertex3f(0.0, -0.5f, 0.0);
  glVertex3f(0.0, 0.0, -0.5f);
  // glVertex3f(-0.5f, 0.0, 0.0);
  glEnd();

  SDL_GL_SwapWindow(window);
  return true;
}


bool Game::HandleEvent(SDL_Event *event) {
  if (event->type == SDL_QUIT) {
    isRunning = false;
  }
  return true;
}


bool Game::Quit() {
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  return true;
}


void Game::Throw(const char *err) {
  isRunning = false;
  std::cerr << err << std::endl;
}