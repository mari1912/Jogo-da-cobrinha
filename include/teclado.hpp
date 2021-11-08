#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "cobra.hpp"
#include <memory>
#include "fruta.hpp"

#pragma once

class Teclado {
    private:
        const Uint8* state; //estado do teclado
        int seta;
        const int cima = 1;
        const int baixo = -1;
        const int direita = 2;
        const int esquerda = -2;
        std::shared_ptr<Cobra>cobra;
        std::shared_ptr<Fruta>fruta;
    public:
        Teclado(std::shared_ptr<Cobra>cobra,std::shared_ptr<Fruta>fruta);
        int le_teclado();
};