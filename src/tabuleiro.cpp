#include "tabuleiro.hpp"

//Construtor
Tabuleiro::Tabuleiro() {
    placar = 0;
}

//permite passar os atributos
int Tabuleiro::get_tabuleiro_horizontal() {
    return tabuleiro_horizontal;
}

int Tabuleiro::get_tabuleiro_vertical() {
    return tabuleiro_vertical;
}

int Tabuleiro::get_bloco_horizontal() {
    return tabuleiro_horizontal/bloco_horizontal;
}

int Tabuleiro::get_bloco_vertical() {
    return tabuleiro_vertical/bloco_vertical;
}

int Tabuleiro::get_placar() {
    return placar;
}

void Tabuleiro::aumenta_placar() {
    placar++;
}
