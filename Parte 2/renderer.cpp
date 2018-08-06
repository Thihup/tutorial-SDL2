//exemplo renderer.cpp
//para compilar: g++ -o renderer renderer.cpp -lSDL2
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
  // Inicia o SDL, nesse caso inicia o sistema de vídeo
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout<<"Erro: "<<SDL_GetError()<<std::endl;
    return 1;
  }
  
  // declara um ponteiro de janela
  SDL_Window *janela;
  // cria uma janela com título "Janela SDL2" na posição X=10 e Y=20, com tamanho 640x480
  janela = SDL_CreateWindow("Janela SDL2",10,20, 640, 480, SDL_WINDOW_SHOWN);
  //poderia criar uma janela com OpenGL:
  //janela = SDL_CreateWindow("Janela SDL2",10,20, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
  //se janela for nula então...
  if (!janela)
  {
    //imprime mensagem de erro
    std::cout<<"Erro: "<<SDL_GetError()<<std::endl;
    return 1;
  }
  
  //Declara o ponteiro para um SDL_Renderer
  SDL_Renderer *renderer;

  // cria um SDL_Renderer
  // SDL_Renderer * SDL_CreateRenderer(SDL_Window * janela, int id, Uint32 flags);
  // parametros: janela (um SDL_Window *), id do renderer escolhido pelo programador, 
  // e as flags, aqui pode ser somente SDL_RENDERER_ACCELERATED
  renderer = SDL_CreateRenderer(janela, 0, SDL_RENDERER_ACCELERATED);
  //se renderer for nulo, então...
  if (!renderer)
  {
    //imprime mensagem de erro
    std::cout<<"Erro: "<<SDL_GetError()<<std::endl;
    //encerrao programa
    return 1;
  }
  
  //agora a janela vai aparecer com um fundo preto
  // pinta a janela com a cor preta
  //define a cor de fundo da janela como preto (0,0,0,255); 255 é o alpha e aqui é opaco
  //SDL_SetDrawRenderColor(renderer, R,G,B,A);
  // R = Red (vermelho)
  // G = Green (verde)
  // B = Blue (azul)
  // A = Alpha (transparencia)
  SDL_SetRenderDrawColor(renderer, 0,0,0,255);
  //desenha toda a tela com a cor preto (0,0,0,255)
  SDL_RenderClear(renderer);
  //esta função faz parecer o resultado do desenho com SDL_RenderClear
  //é só depois de chamar esta função abaixo que veremos o resultado na tela
  SDL_RenderPresent(renderer);
  
  // pausa o programa por 3000 milissegundos, ou 3 segundos
  SDL_Delay(3000);  
  
  //agora tem que destruir o renderer também
  SDL_DestroyRenderer(renderer);
  //lembre-se de liberar a memoria da janela com esta função abaixo
  // ou você terá memory leak
  SDL_DestroyWindow(janela);

  //E por fim, libere o SDL
  SDL_Quit();

  return 0;
}
