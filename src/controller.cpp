#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

//Construtor
Controller::Controller(std::shared_ptr<Model>model, std::shared_ptr<View>view) {
    this->model = model;
    this->view = view;
    rodando = true;
}

//Calcula a proxima posicao
float Controller::calcula_posicao() {

    forca = -(model->get_x_atual())*(model->get_k()) - (model->get_v_atual())*(model->get_b());
    model->set_aceleracao(forca/(model->get_massa()));
    model->set_v_atual(model->get_v_atual()+model->get_aceleracao()*model->get_dt());
    model->set_x_atual(model->get_x_atual()+model->get_v_atual()*model->get_dt());   
    
    return model->get_x_atual();
}

void Controller::roda_jogo() {

    float x;
    SDL_Rect target = view->get_target();
    SDL_Renderer* renderer = view->get_renderer();
    SDL_Texture* texture = view->get_texture();
    SDL_Texture* texture2 = view->get_texture2();

    // Laco principal do jogo
    while(rodando) {
        // Polling de eventos

        x = calcula_posicao();
        target.x += x;

        SDL_PumpEvents(); // atualiza estado do teclado
        if (state[SDL_SCANCODE_UP]) target.y -= 1;
        if (state[SDL_SCANCODE_DOWN]) target.y += 1;

        view->set_target(target);

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

void Controller::finaliza() {
    SDL_Window* window = view->get_window();
    SDL_Renderer* renderer = view->get_renderer();
    SDL_Texture* texture = view->get_texture();
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
