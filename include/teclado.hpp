#include <SDL2/SDL.h>

#pragma once

class Teclado {
    private:
        const Uint8* state; //estado do teclado
        int iniciar;
    public:
        Teclado();
        int get_iniciar();
        void inicia_jogo();
};