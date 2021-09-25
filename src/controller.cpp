#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "model.hpp"
#include "controller.hpp"

//Construtor
Controller::Controller(std::shared_ptr<Model>model) {
    this->model = model;
}

//calcula a posicao horizontal da cobrinha
void Controller::calcula_x_cobrinha() {
    float x_cobrinha;
    x_cobrinha = model->get_x_atual() + model->get_vx();
    model->set_x_atual(x_cobrinha);
}

//calcula a posicao vertical da cobrinha
void Controller::calcula_y_cobrinha() {
    float y_cobrinha;
    y_cobrinha = model->get_y_atual() + model->get_vy();
    model->set_y_atual(y_cobrinha);
}

void Controller::calcula_posicao(){
    if(585 < model -> get_y_atual() || 0 > model-> get_y_atual()){
        model->set_vy(0);
        
    }
    if(770 < model -> get_x_atual() || 0 > model-> get_x_atual()){
        model->set_vx(0);
        
    }
}