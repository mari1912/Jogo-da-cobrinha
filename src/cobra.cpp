#include "cobra.hpp"

//Construtor
Cobra::Cobra(int x_atual, int vx, int y_atual, int vy) {
    this->x_atual = x_atual;
    this->vx = vx;
    this->y_atual = y_atual;
    this->vy = vy;
}

//permite passar os atributos
int Cobra::get_x_atual() {
    return x_atual;
}

int Cobra::get_vx() {
    return vx;
}

int Cobra::get_y_atual() {
    return y_atual;
}

int Cobra::get_vy() {
    return vy;
}

//permite atualizar os atributos
void Cobra::set_x_atual(int x_novo) {
    x_atual = x_novo;
}

void Cobra::set_vx(int vx_novo) {
    vx = vx_novo;
}

void Cobra::set_y_atual(int y_novo) {
    y_atual = y_novo;
}

void Cobra::set_vy(int vy_novo) {
    vy = vy_novo;
}