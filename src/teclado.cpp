#include "teclado.hpp"

/**
 * @brief  funcao que recebe os comandos do teclado
 */ 

Teclado::Teclado() {
    state = SDL_GetKeyboardState(nullptr);
    iniciar = 0;  
}

//Verifica se a tecla espaco foi apertada
void Teclado::inicia_jogo() {
    if(state[SDL_SCANCODE_SPACE]) {
        iniciar = 1;
    }
}

//Retorna a variavel iniciar, para indicar se o jogo ja foi iniciado
int Teclado::get_iniciar() {
    return iniciar;
}