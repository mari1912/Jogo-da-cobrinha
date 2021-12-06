#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "cobra.hpp"
#include <memory>
#include "fruta.hpp"
#include <vector>

#pragma once

class Teclado {
    private:
        const Uint8* state; //estado do teclado
        int seta;
        const int cima = 1;
        const int baixo = -1;
        const int direita = 2;
        const int esquerda = -2;
        std::shared_ptr<Fruta>fruta;
        int iniciar;
    public:
        Teclado(std::shared_ptr<Fruta>fruta);
        int le_teclado();
        int get_iniciar();
        void inicia_jogo();
};