#include "model.hpp"

//Construtor
Model::Model(int x_atual, int vx, int y_atual, int vy) {
    this->x_atual = x_atual;
    this->vx = vx;
    this->y_atual = y_atual;
    this->vy = vy;
    x_fruta = 50;
    y_fruta = 0;
}

//permite passar os atributos
int Model::get_x_atual() {
    return x_atual;
}

int Model::get_vx() {
    return vx;
}

int Model::get_y_atual() {
    return y_atual;
}

int Model::get_vy() {
    return vy;
}

int Model::get_x_fruta() {
    return x_fruta;
}

int Model::get_y_fruta() {
    return y_fruta;
}

int Model::get_tabuleiro_horizontal() {
    return tabuleiro_horizontal;
}

int Model::get_tabuleiro_vertical() {
    return tabuleiro_vertical;
}

int Model::get_bloco_horizontal() {
    return tabuleiro_horizontal/bloco_horizontal;
}

int Model::get_bloco_vertical() {
    return tabuleiro_vertical/bloco_vertical;
}

//permite atualizar os atributos
void Model::set_x_atual(int x_novo) {
    x_atual = x_novo;
}

void Model::set_vx(int vx_novo) {
    vx = vx_novo;
}

void Model::set_y_atual(int y_novo) {
    y_atual = y_novo;
}

void Model::set_vy(int vy_novo) {
    vy = vy_novo;
}

void Model::set_x_fruta(int x_fruta_novo) {
    x_fruta = x_fruta_novo;
}

void Model::set_y_fruta(int y_fruta_novo) {
    y_fruta = y_fruta_novo;
}