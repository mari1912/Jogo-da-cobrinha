#include "cobra.hpp"
#include "fruta.hpp"
#include "tabuleiro.hpp"
#include "teclado.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#pragma once

class Controller {

    private:
    
        std::shared_ptr<Fruta>fruta;
        std::shared_ptr<Tabuleiro>tabuleiro;
        std::shared_ptr<Teclado>teclado;

    public:
        Controller(std::shared_ptr<Tabuleiro>tabuleiro,  std::shared_ptr<Fruta>fruta, std::shared_ptr<Teclado>teclado);    //construtor
        void muda_posicao(int pos,int indice);                        //ve para onde tem que ir a partir do teclado
        void calcula_x_cobrinha();                  //calcula posicao horinzontal da cobrinha
        void calcula_y_cobrinha();                  //calcula posicao vertical da cobrinha
        void verifica_posicao();                    //Não deixa a cobrinha sair do tabuleiro
        void comeu();                               //vê se a cobrinha comeu a fruta
        void posicao_fruta();                       //calcula a nova posição da fruta
        void cresce(Cobra cobra);                              //a cobrinha cresce
        void anda(Cobra cobra);
        void morreu(Cobra cobra);
};