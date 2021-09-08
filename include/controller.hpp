#include "model.hpp"
#include "view.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma once

class Controller {

    private:
        std::shared_ptr<Model>model;
        std::shared_ptr<View>view;
        float forca;
        bool rodando;
        // Variaveis para verificar eventos
        SDL_Event evento; // eventos discretos
        const Uint8* state = SDL_GetKeyboardState(nullptr); // estado do teclado

    public:
        Controller(std::shared_ptr<Model>model, std::shared_ptr<View>view);
        float calcula_posicao();
        void roda_jogo();
        void finaliza();
};