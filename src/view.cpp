#include <memory>
#include <iostream>
#include "view.hpp"

/** @brief Construtor */ 
View::View(std::shared_ptr<Cobra>cobra, std::shared_ptr<Fruta>fruta, std::shared_ptr<Tabuleiro>tabuleiro){ 
    this->cobra = cobra;
    this->fruta = fruta;
    this->tabuleiro = tabuleiro;

    /* ! Inicializando o subsistema de video do SDL */ 
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
    }

    /* ! Criando janela */ 
    window = SDL_CreateWindow("Demonstracao do SDL2",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
    if (window==nullptr) { /* Em caso de erro... */
        std::cout << SDL_GetError();
        SDL_Quit();
        exit;
    }

    /* ! Inicializando renderizador */
    renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer==nullptr) { // Em caso de erro...
        SDL_DestroyWindow(window);
        std::cout << SDL_GetError();
        SDL_Quit();
        exit;
    }
}

void View::render() {
    SDL_Rect bloco;
    bloco.w = SCREEN_WIDTH / BLOCK_WIDTH;
    bloco.h = SCREEN_HEIGHT / BLOCK_HEIGHT;

    /*! Desenha o tabuleiro em preto
    *parametros: renderer, cores em rgb(2,3,4), opacidade */ 
    SDL_SetRenderDrawColor(renderer, 0x0A, 0x0A, 0x0A, 0xFF);
    SDL_RenderClear (renderer);

    /* !std::cout<<cobra->get_cobrinha_horizontal().size()<<std::endl; */ 
    SDL_SetRenderDrawColor (renderer, 0x22, 0x8b, 0x22, 0xFF);
    for (int i = 0; i < cobra->get_cobrinha_horizontal().size(); i++) {
    /* !    std::cout<<i<<std::endl; */ 
        bloco.x = cobra->get_cobrinha_horizontal()[i];
        bloco.y = cobra->get_cobrinha_vertical()[i];
        SDL_RenderFillRect(renderer, &bloco);
    }

    /* ! Desenha a fruta */ 
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x2F, 0x4E, 0xFF);
    bloco.x = fruta->get_x_fruta();
    bloco.y = fruta->get_y_fruta();
    SDL_RenderFillRect(renderer, &bloco);

    SDL_RenderPresent(renderer); 
} 

void View::finaliza() {
    //SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}