#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "cobra.hpp"
#include "fruta.hpp"
#include "tabuleiro.hpp"
#include "view.hpp"
#include "controller.hpp"

/**
 * @brief Jogo da Cobrinha desenvolvido para a disciplina EA872
 * @author Mariana Sartorato Jorge
 * @author Daniele Souza Gonçalves 
 * @date 05/10/2021
 * @version 1.0 
 */

/**
 * @return 0 
 */ 
int main() {

    bool rodando = true;
    SDL_Event evento; /* ! eventos discretos */ 
    std::shared_ptr<Cobra>cobra(new Cobra(0,1,0,0));
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado());
    std::shared_ptr<Controller>controller(new Controller(tabuleiro, cobra, fruta, teclado));
    std::shared_ptr<View>view(new View(cobra, fruta, tabuleiro));
    
    while(rodando) {

        controller->muda_posicao();
        controller->calcula_x_cobrinha();
        controller->calcula_y_cobrinha();
        controller->verifica_posicao();

        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = false;
            }
        }
        /* !coloca imagem na tela */ 
        view->render();

        /* ! Delay para diminuir o framerate */ 
        SDL_Delay(150);
    }
         
    view->finaliza();
    
    return 0;
}