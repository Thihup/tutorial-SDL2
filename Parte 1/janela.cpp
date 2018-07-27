//exemplo janela.cpp
//para compilar: g++ -o janela janela.cpp -lSDL2
#include <cstdio>
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
  // Inicia o SDL, nesse caso inicia o sistema de vídeo
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Erro: %s\n", SDL_GetError());
    return 1;
  }

  // declara um ponteiro de janela
  SDL_Window *janela;
  // cria uma janela com título "Janela SDL2" na posição X=10 e Y=20, com tamanho 640x480
  janela = SDL_CreateWindow("Janela SDL2",10,20, 640, 480, SDL_WINDOW_SHOWN);
  //poderia criar uma janela com OpenGL:
  //janela = SDL_CreateWindow("Janela SDL2",10,20, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

  //verifica se deu erro na criação da janela
  if (janela == NULL)
  {
    printf("Erro: %s\n", SDL_GetError());
    return 1;
  }

  //nessa parte viria o loop principal e processamento de eventos
  // mas aqui vamos esperar 3000 milissegundos, ou 3 segundos
  // e então a janela vai fechar sozinha
  // pausa o programa por 3000 milissegundos, ou 3 segundos
  SDL_Delay(3000);

  //lembre-se de liberar a memoria da janela com esta função abaixo
  // ou você terá um memory leak
  SDL_DestroyWindow(janela);

  //E por fim, libere o SDL
  SDL_Quit();

  return 0;
}
