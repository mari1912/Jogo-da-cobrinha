#include <memory>
#include <iostream>
#include <vector>
#include <cstdlib> 
#include "controller.hpp"
#include "json.hpp"
#include "receptor.hpp"


/**
* @brief define o construtor */ 
Controller::Controller(std::shared_ptr<Tabuleiro>tabuleiro, std::shared_ptr<Fruta>fruta, std::shared_ptr<Teclado>teclado) {
    this->tabuleiro = tabuleiro;
    this->fruta = fruta;
    this->teclado = teclado;
}

/** @brief faz a mundança de direcao da cobrinha */ 
void Controller::muda_posicao(int pos, int indice) {
    //int pos = teclado->le_teclado();
    
        if (pos == 1) {
        vetor_cobras[indice].set_vy(-1);
        vetor_cobras[indice].set_vx(0);
    }
    else if (pos == -1) {
        vetor_cobras[indice].set_vy(1);
        vetor_cobras[indice].set_vx(0);
    }
    else if (pos == 2) {
        vetor_cobras[indice].set_vx(1);
        vetor_cobras[indice].set_vy(0);
    }
    else if (pos == -2) {
        vetor_cobras[indice].set_vx(-1);
        vetor_cobras[indice].set_vy(0);
    }
    
    
}

/** @brief calcula a posicao horizontal da cobrinha */ 
void Controller::calcula_x_cobrinha() {
    for(int i = 0; i < vetor_cobras.size();i++){
        int x_cobrinha;
        x_cobrinha = vetor_cobras[i].get_x_atual() + vetor_cobras[i].get_vx() * tabuleiro->get_bloco_horizontal();
        vetor_cobras[i].set_x_atual(x_cobrinha);}
}

/** @brief  calcula a posicao vertical da cobrinha  */ 
void Controller::calcula_y_cobrinha() {
    for(int i = 0; i < vetor_cobras.size();i++){
        int y_cobrinha;
        y_cobrinha = vetor_cobras[i].get_y_atual() + vetor_cobras[i].get_vy() * tabuleiro->get_bloco_vertical();
        vetor_cobras[i].set_y_atual(y_cobrinha);
    }
    
}

/** @brief verifica se a cobrinha está dentro do tabuleiro, se trombou e se a cobrinha comeu a frutinha */ 
void Controller::verifica_posicao(){
    for( int i = 0; i < vetor_cobras.size();i++){
        if((tabuleiro->get_tabuleiro_vertical()-tabuleiro->get_bloco_vertical()) < vetor_cobras[i].get_y_atual() || 0 > vetor_cobras[i].get_y_atual()){
                vetor_cobras[i].set_vy(0);    
                morreu(vetor_cobras[i]);
            }
            if(tabuleiro->get_tabuleiro_horizontal()-tabuleiro->get_bloco_horizontal() < vetor_cobras[i].get_x_atual() || 0 > vetor_cobras[i].get_x_atual()){
                vetor_cobras[i].set_vx(0);
                morreu(vetor_cobras[i]);
            }
            for (int j = 1; j < vetor_cobras[i].get_cobrinha_horizontal().size(); j++) {
                if (vetor_cobras[i].get_x_atual() == vetor_cobras[i].get_cobrinha_horizontal()[j]) {
                    if (vetor_cobras[i].get_y_atual() == vetor_cobras[i].get_cobrinha_vertical()[j]) {
                        morreu(vetor_cobras[i]);
                    }
                }
            }
            comeu();
    }
    

}

/** @brief verifica se a cobrinha comeu a fruta */ 
void Controller::comeu() {
    
    for(int i=0; i < vetor_cobras.size(); i++){
        //se estiver na mesma posição em relação a x 
    if ((fruta->get_x_fruta() <= vetor_cobras[i].get_x_atual()) && (fruta->get_x_fruta() >= vetor_cobras[i].get_x_atual())) {
        //se estiver na mesma posição em relação a y
        if ((fruta->get_y_fruta() <= vetor_cobras[i].get_y_atual()) && (fruta->get_y_fruta() >= vetor_cobras[i].get_y_atual())) {
            //calcula uma nova posição para a fruta
            posicao_fruta();
            std::cout<<"comi a fruta" <<std::endl;
            cresce(vetor_cobras[i]);
        }
    }
    else {
        anda(vetor_cobras[i]);
    }
    }
    
}

/** @brief gera a  posicao da fruta */ 
void Controller::posicao_fruta() {
    int x, y;
    
    //gera posições aleatórias dentro do tabuleiro
    x = (rand() % 20) * tabuleiro->get_bloco_horizontal(); 
    y = (rand() % 20) * tabuleiro->get_bloco_vertical();  

    //atualiza a posição da frutinha
    fruta->set_x_fruta(x);
    fruta->set_y_fruta(y);
}


/** @brief faz a cobrinha crescer */ 
void Controller::cresce(Cobra cobra) {
    int x_ultimo, y_ultimo, fim_x, fim_y;
    fim_x = cobra.get_cobrinha_horizontal().back();
    fim_y = cobra.get_cobrinha_vertical().back(); 
    x_ultimo = cobra.get_cobrinha_horizontal()[fim_x];
    y_ultimo = cobra.get_cobrinha_vertical()[fim_y];
    anda(cobra);
    cobra.set_cobrinha_aumento(x_ultimo, y_ultimo);
}

/** @brief faz a cobrinha andar */ 
void Controller::anda(Cobra cobra) {
    int tamanho = cobra.get_cobrinha_horizontal().size();
    
    for (int i = tamanho-1; i >= 0; i--) {
        if (i == 0) {
            cobra.set_cobrinha_horizontal(i, cobra.get_x_atual());
            cobra.set_cobrinha_vertical(i, cobra.get_y_atual());
        }
        else {
            cobra.set_cobrinha_horizontal(i, cobra.get_cobrinha_horizontal()[i-1]);
            cobra.set_cobrinha_vertical(i, cobra.get_cobrinha_vertical()[i-1]);
        }
    }
}

/** @brief faz a cobrinha morrer */ 
void Controller::morreu(Cobra cobra) {
    cobra.set_vx(0);
    cobra.set_vy(0);
    cobra.set_vida(0);
    std::cout<<"GAME OVER"<<std::endl;
    //exit(0);
}
