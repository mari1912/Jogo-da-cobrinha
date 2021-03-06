#include <memory>
#include <iostream>
#include <vector>
#include <cstdlib> 
#include "controller.hpp"
#include "json.hpp"
#include "receptor.hpp"



/**
 * @brief Construct a new Controller:: Controller object
 * 
 */
Controller::Controller(std::shared_ptr<Tabuleiro>tabuleiro, std::shared_ptr<Fruta>fruta, std::shared_ptr<Teclado>teclado) {
    this->tabuleiro = tabuleiro;
    this->fruta = fruta;
    this->teclado = teclado;
}

/**
 * @brief  faz a mundança de direcao da cobrinha
 * 
 * @param pos 
 * @param indice 
 */
void Controller::muda_posicao(int pos, int indice) {
   
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

/**
 * @brief calcula a posicao horizontal da cobrinha
 * 
 */
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
        if(vetor_cobras[i].get_vida() == 1) {
            if((tabuleiro->get_tabuleiro_vertical()-tabuleiro->get_bloco_vertical()) < vetor_cobras[i].get_y_atual() || 0 > vetor_cobras[i].get_y_atual()){
                    vetor_cobras[i].set_vy(0);    
                    morreu(i);
                }
                if(tabuleiro->get_tabuleiro_horizontal()-tabuleiro->get_bloco_horizontal() < vetor_cobras[i].get_x_atual() || 0 > vetor_cobras[i].get_x_atual()){
                    vetor_cobras[i].set_vx(0);
                    morreu(i);
                }
                for (int j = 1; j < vetor_cobras[i].get_cobrinha_horizontal().size(); j++) {
                    if (vetor_cobras[i].get_x_atual() == vetor_cobras[i].get_cobrinha_horizontal()[j]) {
                        if (vetor_cobras[i].get_y_atual() == vetor_cobras[i].get_cobrinha_vertical()[j]) {
                            morreu(i);
                        }
                    }
                }
                for(int j = i+1; j < vetor_cobras.size(); j++) {
                    for(int k = 0; k < vetor_cobras[i].get_cobrinha_horizontal().size(); k++) {
                        if (vetor_cobras[i].get_x_atual() == vetor_cobras[j].get_cobrinha_horizontal()[k]) {
                        if (vetor_cobras[i].get_y_atual() == vetor_cobras[j].get_cobrinha_vertical()[k]) {
                                morreu(i);
                                morreu(j);
                            }
                        }
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
            cresce(i);
        }
    }
    else {
        anda(i);
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

/**
 * @brief faz a cobrinha crescer
 * 
 * @param index 
 */
void Controller::cresce(int index) {
    int x_ultimo, y_ultimo, fim_x, fim_y;
    fim_x = vetor_cobras[index].get_cobrinha_horizontal().back();
    fim_y = vetor_cobras[index].get_cobrinha_vertical().back(); 
    x_ultimo = vetor_cobras[index].get_cobrinha_horizontal()[fim_x];
    y_ultimo = vetor_cobras[index].get_cobrinha_vertical()[fim_y];
    anda(index);
    vetor_cobras[index].set_cobrinha_aumento(x_ultimo, y_ultimo);
}

/**
 * @brief faz a cobrinha andar
 * 
 * @param index 
 */
void Controller::anda(int index) {
    int tamanho = vetor_cobras[index].get_cobrinha_horizontal().size();
    
    for (int i = tamanho-1; i >= 0; i--) {
        if (i == 0) {
            vetor_cobras[index].set_cobrinha_horizontal(i, vetor_cobras[index].get_x_atual());
            vetor_cobras[index].set_cobrinha_vertical(i, vetor_cobras[index].get_y_atual());
        }
        else {
            vetor_cobras[index].set_cobrinha_horizontal(i, vetor_cobras[index].get_cobrinha_horizontal()[i-1]);
            vetor_cobras[index].set_cobrinha_vertical(i, vetor_cobras[index].get_cobrinha_vertical()[i-1]);
        }
    }
}

/**
 * @brief faz a cobrinha morrer
 * 
 * @param index 
 */
void Controller::morreu(int index) {
    vetor_cobras[index].set_vx(0);
    vetor_cobras[index].set_vy(0);
    vetor_cobras[index].set_vida(0);
    std::cout<<"GAME OVER PLAYER "<<index+1<<std::endl;
    
}
