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
    // personagem: em aspas esta o endereco da figura na pasta, no caso vai carregar a capivara
    texture = IMG_LoadTexture(renderer, "../assets/capi.png");
    // fundo: em aspas esta o endereco da figura na pasta, vai carregar o parque
    texture2 = IMG_LoadTexture(renderer, "../assets/park.jpeg");

    // Quadrado onde a textura sera desenhada
    //Especifica onde a imagem da capivara deve ser desenhada
    target.x = model->get_x_atual();
    target.y = model->get_y_atual();
    SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);
    rodando = true;
    state = SDL_GetKeyboardState(nullptr);
}

void View::atualiza_desenho() {

    // Laco principal do jogo
    while(rodando) {

        // Polling de eventos
        SDL_PumpEvents(); // atualiza estado do teclado
        
        //Se clicar na seta para cima
        if (state[SDL_SCANCODE_UP]) {
            model->set_vy(-1);
            model->set_vx(0);
            controller->calcula_y_cobrinha();  
        } 

        //Se clicar na seta para baixo
        if (state[SDL_SCANCODE_DOWN]) {
            model->set_vy(1);
            model->set_vx(0);
            controller->calcula_y_cobrinha();
        } 

        //Se clicar na seta esquerda
        if (state[SDL_SCANCODE_LEFT]) {
            model->set_vx(-1);
            model->set_vy(0);
            controller->calcula_x_cobrinha();
        } 

        //Se clicar na seta direita
        if (state[SDL_SCANCODE_RIGHT]) {
            model->set_vx(1);
            model->set_vy(0);
            controller->calcula_x_cobrinha();
        } 

        //atualiza o local do personagem
        target.x += model->get_vx();
        target.y += model->get_vy();
        
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = false;
            }
        }

        // Desenhar a cena
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture2, nullptr, nullptr);   //desenha o parque, que e fixo
        SDL_RenderCopy(renderer, texture, nullptr, &target);    //desenha a capivara, que e movel
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

