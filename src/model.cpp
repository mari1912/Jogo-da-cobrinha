#include "model.hpp"

//Construtor
Model::Model(float x_atual, float vx, float y_atual, float vy) {
    this->x_atual = x_atual;
    this->vx = vx;
    this->y_atual = y_atual;
    this->vy = vy;
    dt = 0.1;
}

//permite passar os atributos
float Model::get_x_atual() {
    return x_atual;
}

float Model::get_vx() {
    return vx;
}

float Model::get_y_atual() {
    return y_atual;
}

float Model::get_vy() {
    return vy;
}

float Model::get_dt() {
    return dt;
}

float Model::get_tabuleiro_largura(){
    return tabuleiro_largura;
}

float Model::get_tabuleiro_altura(){
    return tabuleiro_altura;
}


//permite atualizar os atributos
void Model::set_x_atual(float x_novo) {
    x_atual = x_novo;
}

void Model::set_vx(float vx_novo) {
    vx = vx_novo;
}

void Model::set_y_atual(float y_novo) {
    y_atual = y_novo;
}

void Model::set_vy(float vy_novo) {
    vy = vy_novo;
}