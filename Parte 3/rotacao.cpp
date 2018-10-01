//para compilar: g++ -o rotacao rotacao.cpp -lSDL2
//NOTA: é preciso ter a imagem.bmp na mesma pasta quando for executar
#include <SDL2/SDL.h>
#include <iostream>

int main ( int argc, char ** argv )
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout<<"Error: "<<SDL_GetError()<<std::endl;
		return 1;
	}

	SDL_Window * window = SDL_CreateWindow("Rotacionando uma imagem", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (!window)
	{
		std::cout<<"Error: "<<SDL_GetError()<<std::endl;
		return 1;
	}

	SDL_Renderer * renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cout<<"Error: "<<SDL_GetError()<<std::endl;
		return 1;
	}

	//carrega uma imagem BMP
	SDL_Surface * surface = SDL_LoadBMP("imagem.bmp");
	//verifica se carregou direito
	if (!surface)
	{
		std::cout<<"Error: "<<SDL_GetError()<<std::endl;
		return 1;
	}

	//cria a textura a partir da surface carregada
	SDL_Texture * imagem = SDL_CreateTextureFromSurface(renderer, surface);
	//verifica se criou a textura
	if (!imagem)
	{
		std::cout<<"Error: "<<SDL_GetError()<<std::endl;
		return 1;
	}

	int largura, altura;
	//pega a largura e altura da imagem
	SDL_QueryTexture(imagem, NULL, NULL, &largura, &altura);
	//define o ponto da imagem que será o centro da rotação
	SDL_Point centro = {largura/2, altura/2};
	//cria um destino para a imagem
	SDL_Rect destino = {(800-largura)/2, (600-altura)/2, largura, altura};

	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	SDL_RenderClear(renderer);
	//desenha na tela a image na posição e tamanho de destino
	//com 45 graus de inclinação no sentido anti-horário
	SDL_RenderCopyEx(renderer, imagem, NULL, &destino, 45, &centro, SDL_FLIP_NONE);
	//mostra o que foi desenhado na tela
	SDL_RenderPresent(renderer);
	//epsera 5 segundos (5000 milissegundos)
	SDL_Delay(5000);

	//destrói a imagem carregada (libera memória)
	SDL_DestroyTexture(imagem);
	//por fim fecha o sdl
	SDL_Quit();

	return 0;
}