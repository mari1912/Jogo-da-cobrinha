#include "model.hpp"

/**
 * @brief arquivo model, onde são definidas as funções a serem utilizadas */ 

Model::Model(int x_atual, int vx, int y_atual, int vy) {
    this->x_atual = x_atual;
    this->vx = vx;
    this->y_atual = y_atual;
    this->vy = vy;
    x_fruta = 50;
    y_fruta = 0;
}

/** @brief permite passar os atributos */

/** @return valor de x atual */ 
int Model::get_x_atual() {
    return x_atual;
}

/** @return valor de  vx */ 
int Model::get_vx() {
    return vx;
}

/** @return valor de y atual */ 
int Model::get_y_atual() {
    return y_atual;
}

/** @return valor de vy */ 
int Model::get_vy() {
    return vy;
}

/** @return valor de x da fruta */ 
int Model::get_x_fruta() {
    return x_fruta;
}

/** @return valor de y atual */ 

int Model::get_y_fruta() {
    return y_fruta;
}

/** @return posição horizontal no tabuleiro  */ 
int Model::get_tabuleiro_horizontal() {
    return tabuleiro_horizontal;
}

/** @return posição vertical no tabuleiro  */ 
int Model::get_tabuleiro_vertical() {
    return tabuleiro_vertical;
}

/** @return bloco horizontal */ 
int Model::get_bloco_horizontal() {
    return tabuleiro_horizontal/bloco_horizontal;
}

/** @return bloco vertical  */ 
int Model::get_bloco_vertical() {
    return tabuleiro_vertical/bloco_vertical;
}

/** @param x_novo novo valor de x  */ 
void Model::set_x_atual(int x_novo) {
    x_atual = x_novo;
}

/** @param vx_novo novo valor de vx  */ 
void Model::set_vx(int vx_novo) {
    vx = vx_novo;
}

/** @param y_novo novo valor de y  */ 
void Model::set_y_atual(int y_novo) {
    y_atual = y_novo;
}

/** @param vy_novo novo valor de vy  */ 
void Model::set_vy(int vy_novo) {
    vy = vy_novo;
}

/** @param x_fruta_novo novo valor de x da fruta  */ 
void Model::set_x_fruta(int x_fruta_novo) {
    x_fruta = x_fruta_novo;
}

/** @param y_fruta_novo novo valor de y da fruta  */ 
void Model::set_y_fruta(int y_fruta_novo) {
    y_fruta = y_fruta_novo;
}