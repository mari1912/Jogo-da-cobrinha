#include "teclado.hpp"

/**
 * @brief Construct a new Teclado:: Teclado object
 * 
 */

Teclado::Teclado(std::shared_ptr<Fruta>fruta) {
    state = SDL_GetKeyboardState(nullptr);
    seta = 0;
    this->fruta = fruta;
    
}


/**
 * @brief recebe os dados do teclado 
 * 
 * @return int 
 */
int Teclado::le_teclado() {
    /*! Polling de eventos */ 
    SDL_PumpEvents(); /*! atualiza estado do teclado */ 
        
    /* !Se clicar na seta para cima */ 
    if (state[SDL_SCANCODE_UP]) {
        seta = cima;  
    } 

    /* ! Se clicar na seta para baixo */ 
    if (state[SDL_SCANCODE_DOWN]) {
        seta = baixo;
    } 

    /* !Se clicar na seta esquerda */ 
    if (state[SDL_SCANCODE_LEFT]) {
        seta = esquerda;
    } 

    /* ! Se clicar na seta direita  */
    if (state[SDL_SCANCODE_RIGHT]) {
        seta = direita;
    }
/*
    if(state[SDL_SCANCODE_S]){
        cobra-> salvar_jogo();
        fruta -> salvar_jogo_fruta();
        seta = 3;
    }

    if(state[SDL_SCANCODE_R]){
        cobra-> recuperar_jogo();
        fruta -> recuperar_jogo_fruta();
        seta = -3;
    }
*/
    return seta; 
}