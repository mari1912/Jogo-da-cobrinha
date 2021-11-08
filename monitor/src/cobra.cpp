#include "cobra.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>

using nlohmann::json;
/** @brief Construtor */ 
Cobra::Cobra(int x_atual, float vx, int y_atual, float vy) {
    this->x_atual = x_atual;
    this->vx = vx;
    this->y_atual = y_atual;
    this->vy = vy;
    cobrinha_horizontal.push_back(x_atual);
    cobrinha_vertical.push_back(y_atual);
}

/**
 * @return x atual */ 
int Cobra::get_x_atual() {
    return x_atual;
}

/**
 * @return vx */ 
float Cobra::get_vx() {
    return vx;
}

/**
 * @return y atual */ 
int Cobra::get_y_atual() {
    return y_atual;
}

/**
 * @return vy */ 
float Cobra::get_vy() {
    return vy;
}

std::vector<int> Cobra::get_cobrinha_horizontal() {
    return cobrinha_horizontal;
}

std::vector<int> Cobra::get_cobrinha_vertical() {
    return cobrinha_vertical;
}

/* ! permite atualizar os atributos */ 
void Cobra::set_x_atual(int x_novo) {
    x_atual = x_novo;
}

void Cobra::set_vx(float vx_novo) {
    vx = vx_novo;
}

void Cobra::set_y_atual(int y_novo) {
    y_atual = y_novo;
}

void Cobra::set_vy(float vy_novo) {
    vy = vy_novo;
}

void Cobra::set_cobrinha_vertical(std::vector<int> vect) {
    cobrinha_vertical = vect;
}

void Cobra::set_cobrinha_horizontal(std::vector<int> vect) {
    cobrinha_horizontal = vect;
}