#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma once

class Teclado {
    private:
        const Uint8* state; //estado do teclado
        int seta;
        const int cima = 1;
        const int baixo = -1;
        const int direita = 2;
        const int esquerda = -2;
    public:
        Teclado();
        int le_teclado();
};