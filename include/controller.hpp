#include "model.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma once

class Controller {

    private:
        std::shared_ptr<Model>model;

    public:
        Controller(std::shared_ptr<Model>model);    //construtor
        void calcula_x_cobrinha();                  //calcula posicao horinzontal da cobrinha
        void calcula_y_cobrinha();                  //calcula posicao vertical da cobrinha
};