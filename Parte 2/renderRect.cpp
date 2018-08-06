//exemplo renderRect.cpp
//para compilar: g++ -o renderRect renderRect.cpp -lSDL2
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
  // Inicia o SDL, nesse caso inicia o sistema de vídeo
  //verifica se deu erro
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    //imprime mensagem de erro
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
  
  //agora a janela vai aparecer com um fundo CINZA
  // pinta a janela com a cor CINZA
  //define a cor de fundo da janela como CINZA (128,128,128,255); 255 é o alpha e aqui é opaco
  //SDL_SetDrawRenderColor(renderer, R,G,B,A);
  // R = Red (vermelho)
  // G = Green (verde)
  // B = Blue (azul)
  // A = Alpha (transparencia)
  SDL_SetRenderDrawColor(renderer, 128,128,128,255);
  //desenha toda a tela com a cor CINZA definida acima
  SDL_RenderClear(renderer);
  
  //agora antes de atualizar toda a tela com SDL_RenderPresent precisamos desenhar os retangulos
  //primeiro, definimos um SDL_Rect
  SDL_Rect retangulo;
  //depois posicionamos ele em algum lugar da tela, vou por na posição 32 em X
  //observe que a origem do eixo X é no canto esquerdo superior na horizontal para direita é positivo
  retangulo.x = 32;
  //despois definimos a posição Y
  //Observe que a origem do eixo Y é no canto esquerdo superior na vertical pra baixo é positivo
  retangulo.y = 200;
  //agora definimos as dimensões do retangulo
  retangulo.w = 128;//largura
  retangulo.h = 12;//altura
  //E então definimos uma cor para o retangulo, será vermelho: R=255,G=0,B=0,A=255
  SDL_SetRenderDrawColor(renderer, 255,0,0,255);
  //E finalmente desenha o retangulo com a cor definida acima
  SDL_RenderFillRect(renderer, &retangulo);
  
  //até aqui foi desenhado apenas um retangulo
  //agora desenha outro retangulo na posição X=120 e Y=320, com largura = 64 e altura = 32
  retangulo.x = 120;
  retangulo.y = 320;
  retangulo.w = 64;
  retangulo.h = 32;
  //agoar desenha o retangulo, com a cor vermelha que ainda está definida
  SDL_RenderFillRect(renderer, &retangulo);
 
  //Agoar define a cor amarela
  SDL_SetRenderDrawColor(renderer, 255,255,0,255);
  //muda a poisção do retangulo, preservando a largura e altura
  retangulo.x = 320;
  retangulo.y = 200;
  //agora desenha o retangulo na tela
  SDL_RenderFillRect(renderer, &retangulo);
  
  //esta função faz parecer o resultado do desenho com SDL_RenderClear
  //é só depois de chamar esta função abaixo que veremos o resultado na tela
  SDL_RenderPresent(renderer);
  
  // pausa o programa por 6000 milissegundos, ou 6 segundos
  SDL_Delay(6000);  
  
  //agora tem que destruir o renderer também
  SDL_DestroyRenderer(renderer);
  //lembre-se de liberar a memoria da janela com esta função abaixo
  // ou você terá memory leak
  SDL_DestroyWindow(janela);

  //E por fim, libere o SDL
  SDL_Quit();

  return 0;
}
