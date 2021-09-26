#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "controller.hpp"

//Construtor
Controller::Controller(std::shared_ptr<Tabuleiro>tabuleiro, std::shared_ptr<Cobra>cobra, std::shared_ptr<Fruta>fruta) {
    this->tabuleiro = tabuleiro;
    this->cobra = cobra;
    this->fruta = fruta;
}

//calcula a posicao horizontal da cobrinha
void Controller::calcula_x_cobrinha() {
    int x_cobrinha;
    x_cobrinha = cobra->get_x_atual() + cobra->get_vx();
    cobra->set_x_atual(x_cobrinha);
}

//calcula a posicao vertical da cobrinha
void Controller::calcula_y_cobrinha() {
    int y_cobrinha;
    y_cobrinha = cobra->get_y_atual() + cobra->get_vy();
    cobra->set_y_atual(y_cobrinha);
}

//verifica se a cobrinha está dentro do tabuleiro e se a cobrinha comeu a frutinha
void Controller::verifica_posicao(){
    if((tabuleiro->get_tabuleiro_vertical()-tabuleiro->get_bloco_vertical()) < cobra-> get_y_atual() || 0 > cobra-> get_y_atual()){
        cobra->set_vy(0);    
    }
    if(tabuleiro->get_tabuleiro_horizontal()-tabuleiro->get_bloco_horizontal() < cobra->get_x_atual() || 0 > cobra->get_x_atual()){
        cobra->set_vx(0);
    }
    comeu();

}

void Controller::comeu() {
    int tolerancia = 3; //tolerancia com relação a posição da cobra em relação a frutinha
    
    //se estiver na mesma posição em relação a x 
    if ((fruta->get_x_fruta() <= cobra->get_x_atual() + tolerancia) && (fruta->get_x_fruta() >= cobra->get_x_atual() - tolerancia)) {
        //se estiver na mesma posição em relação a y
        if ((fruta->get_y_fruta() <= cobra->get_y_atual() + tolerancia) && (fruta->get_y_fruta() >= cobra->get_y_atual() - tolerancia)) {
            //calcula uma nova posição para a fruta
            posicao_fruta();
        }
    }
}

void Controller::posicao_fruta() {
    int x, y;
    //gera posições aleatórias dentro do tabuleiro
    x = rand() % tabuleiro->get_tabuleiro_horizontal();
    y = rand() % tabuleiro->get_tabuleiro_vertical();
    //atualiza a posição da frutinha
    fruta->set_x_fruta(x);
    fruta->set_y_fruta(y);
}
