#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "model.hpp"
#include "controller.hpp"

//Construtor
Controller::Controller(std::shared_ptr<Model>model) {
    this->model = model;
}

//Calcula a proxima posicao
float Controller::calcula_posicao() {

    forca = -(model->get_x_atual())*(model->get_k()) - (model->get_v_atual())*(model->get_b());
    model->set_aceleracao(forca/(model->get_massa()));
    model->set_v_atual(model->get_v_atual()+model->get_aceleracao()*model->get_dt());
    model->set_x_atual(model->get_x_atual()+model->get_v_atual()*model->get_dt());   
    
    return model->get_x_atual();
}
