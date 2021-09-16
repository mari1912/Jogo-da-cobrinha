#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <iostream>
#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

//Construtor
View::View(std::shared_ptr<Model>model, std::shared_ptr<Controller>controller){ 
    this->model = model;
    this->controller = controller;

    // Inicializando o subsistema de video do SDL
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
    }

    //Criando janela
    window = SDL_CreateWindow("Demonstracao do SDL2",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
    if (window==nullptr) { // Em caso de erro...
        std::cout << SDL_GetError();
        SDL_Quit();
        exit;
    }

    //Inicializando renderizador
    renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer==nullptr) { // Em caso de erro...
        SDL_DestroyWindow(window);
        std::cout << SDL_GetError();
        SDL_Quit();
        exit;
    }

    // Carregando texturas
    // personagem
    texture = IMG_LoadTexture(renderer, "../assets/capi.png");
    // fundo
    texture2 = IMG_LoadTexture(renderer, "../assets/park.jpeg");

    // Quadrado onde a textura sera desenhada
    target.x = 0;
    target.y = 0;
    SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);
    rodando = true;
    state = SDL_GetKeyboardState(nullptr);
}

void View::atualiza() {

    float x;

    // Laco principal do jogo
    while(rodando) {
        // Polling de eventos

        x = controller->calcula_posicao();
        target.x += x;

        SDL_PumpEvents(); // atualiza estado do teclado
        if (state[SDL_SCANCODE_UP]) target.y -= 1;
        if (state[SDL_SCANCODE_DOWN]) target.y += 1;

        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = false;
            }
            // Exemplos de outros eventos.
            // Que outros eventos poderiamos ter e que sao uteis?
            //if (evento.type == SDL_KEYDOWN) {
            //}
            //if (evento.type == SDL_MOUSEBUTTONDOWN) {
            //}
        }

        // Desenhar a cena
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture2, nullptr, nullptr);
        SDL_RenderCopy(renderer, texture, nullptr, &target);
        SDL_RenderPresent(renderer);

        // Delay para diminuir o framerate
        SDL_Delay(10);
  }

}

void View::finaliza() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


/*
//Permite acessar dados
SDL_Rect View::get_target() {
    return target;
}

SDL_Renderer* View::get_renderer() { 
    return renderer;
}

SDL_Texture* View::get_texture() {
    return texture;
}

SDL_Texture* View::get_texture2() {
    return texture2;
}

SDL_Window* View::get_window() {
    return window;
}

//Permite alterar dado
void View::set_target(SDL_Rect new_target) {
    target = new_target;
}
*/