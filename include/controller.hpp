#include "model.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma once

class Controller {

    private:
        std::shared_ptr<Model>model;
        float forca;

    public:
        Controller(std::shared_ptr<Model>model);
        float calcula_posicao();
        void roda_jogo();
};