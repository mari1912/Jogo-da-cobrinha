#include <memory>
#include <iostream>
#include <vector>
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
    x_cobrinha = cobra->get_x_atual() + cobra->get_vx() * tabuleiro->get_bloco_horizontal();
    cobra->set_x_atual(x_cobrinha);
}

//calcula a posicao vertical da cobrinha
void Controller::calcula_y_cobrinha() {
    int y_cobrinha;
    y_cobrinha = cobra->get_y_atual() + cobra->get_vy() * tabuleiro->get_bloco_vertical();
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
    int tolerancia = 5; //tolerancia com relação a posição da cobra em relação a frutinha
    
    //se estiver na mesma posição em relação a x 
    if ((fruta->get_x_fruta() <= cobra->get_x_atual() + tolerancia) && (fruta->get_x_fruta() >= cobra->get_x_atual() - tolerancia)) {
        //se estiver na mesma posição em relação a y
        if ((fruta->get_y_fruta() <= cobra->get_y_atual() + tolerancia) && (fruta->get_y_fruta() >= cobra->get_y_atual() - tolerancia)) {
            //calcula uma nova posição para a fruta
            posicao_fruta();
            cresce();
            tabuleiro->aumenta_placar();
        }
    }
    else {
        anda();
    }
}

void Controller::posicao_fruta() {
    int x, y;
    int tolerancia = 5;
    //gera posições aleatórias dentro do tabuleiro
    x = rand() % tabuleiro->get_tabuleiro_horizontal()-tabuleiro->get_bloco_horizontal();
    y = rand() % tabuleiro->get_tabuleiro_vertical()-tabuleiro->get_bloco_vertical();
    //se o local escolhido for o mesmo da cobra tem que achar outro
    if (x <= cobra->get_x_atual()+tolerancia && x >= cobra->get_x_atual()-tolerancia) {
        if (y <= cobra->get_y_atual()+tolerancia && y >= cobra->get_y_atual()-tolerancia) {
            posicao_fruta();            
        }
    }
    if (x < tabuleiro->get_bloco_horizontal() || y < tabuleiro->get_bloco_vertical()) {
        posicao_fruta();
    } 
    //atualiza a posição da frutinha
    fruta->set_x_fruta(x);
    fruta->set_y_fruta(y);
}


void Controller::cresce() {
    int x_ultimo, y_ultimo, fim_x, fim_y;
    fim_x = cobra->get_cobrinha_horizontal().back();
    fim_y = cobra->get_cobrinha_vertical().back(); 
    x_ultimo = cobra->get_cobrinha_horizontal()[fim_x];
    y_ultimo = cobra->get_cobrinha_vertical()[fim_y];
    anda();
    cobra->set_cobrinha_aumento(x_ultimo, y_ultimo);
}

void Controller::anda() {
    int tamanho = cobra->get_cobrinha_horizontal().size();
    
    for (int i = tamanho-1; i >= 0; i--) {
        if (i == 0) {
            cobra->set_cobrinha_horizontal(i, cobra->get_x_atual());
            cobra->set_cobrinha_vertical(i, cobra->get_y_atual());
        }
        else {
            cobra->set_cobrinha_horizontal(i, cobra->get_cobrinha_horizontal()[i-1]);
            cobra->set_cobrinha_vertical(i, cobra->get_cobrinha_vertical()[i-1]);
        }
    }
}
