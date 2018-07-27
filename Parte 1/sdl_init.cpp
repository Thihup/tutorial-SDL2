// compile o exemplo com: g++ -o sdl_init sdl_init.cpp -lSDL2
#include <cstdio>
#include <SDL2/SDL.h>

int main (int argc, char **argv)
{
  // inicia o subsistema de video (para criar janelas)
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Erro: %s\n", SDL_GetError());
    return 1;
  }
    
  // fecha todo o SDL
  // NOTA: sempre chame esta função no final do código
  SDL_Quit();
  return 0;
}
