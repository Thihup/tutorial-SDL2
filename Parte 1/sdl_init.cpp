// compile o exemplo com: g++ -o sdl_init sdl_init.cpp -lSDL2
#include <SDL2/SDL.h>

int main (int argc, char **argv)
{
  // inicia o subsistema de video (para criar janelas)
  SDL_Init(SDL_INIT_VIDEO);
  
  // fecha todo o SDL
  // NOTA: sempre chame esta função no final do código
  SDL_Quit();
  return 0;
}
