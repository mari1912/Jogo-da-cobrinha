#include "fruta.hpp"

/**
* @brief define construtor   */
Fruta::Fruta(std::shared_ptr<Tabuleiro>tabuleiro) {
    /* ! Posição inicial da frutinha */ 
    this->tabuleiro = tabuleiro;
    x_fruta = 10*tabuleiro->get_bloco_horizontal();
    y_fruta = 0;
}

/**
* @return x da fruta */
int Fruta::get_x_fruta() {
    return x_fruta;
}

/**
* @return y da fruta */
int Fruta::get_y_fruta() {
    return y_fruta;
}

/**
* @brief permite atualizar os atributos x */
void Fruta::set_x_fruta(int x_fruta_novo) {
    x_fruta = x_fruta_novo;
}

/**
* @brief permite atualizar os atributos y */
void Fruta::set_y_fruta(int y_fruta_novo) {
    y_fruta = y_fruta_novo;
}