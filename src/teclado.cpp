#include "teclado.hpp"
#include "receptor.hpp"

/**
 * @brief  funcao que recebe os comandos do teclado
 */ 

Teclado::Teclado(std::shared_ptr<Fruta>fruta) {
    state = SDL_GetKeyboardState(nullptr);
    seta = 0;
    iniciar = 0;
    this->fruta = fruta;
    
}


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

    //Se clicar na tecla s, o jogo e salvo
    if(state[SDL_SCANCODE_S]){
        for(int i = 0; i < vetor_cobras.size();i++){
            vetor_cobras[i].salvar_jogo();
        }
        
        fruta -> salvar_jogo_fruta();
    }

    //se clicar na tecla r, o jogo e recuperado
    if(state[SDL_SCANCODE_R]){
        for(int i = 0; i < vetor_cobras.size();i++){
            vetor_cobras[i].recuperar_jogo();
        }

        fruta -> recuperar_jogo_fruta();
    }

    return seta; 
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