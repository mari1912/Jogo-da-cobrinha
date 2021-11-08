#include "tabuleiro.hpp"

/** @brief define construtor */ 
Tabuleiro::Tabuleiro() {
}

/** @return valor tabuleiro na horizontal */ 
int Tabuleiro::get_tabuleiro_horizontal() {
    return tabuleiro_horizontal;
}

/** @return valor tabuleiro na vertical */ 
int Tabuleiro::get_tabuleiro_vertical() {
    return tabuleiro_vertical;
}

/** @return bloco na horizontal */ 
int Tabuleiro::get_bloco_horizontal() {
    return tabuleiro_horizontal/bloco_horizontal;
}

/** @return bloco na vertical */ 
int Tabuleiro::get_bloco_vertical() {
    return tabuleiro_vertical/bloco_vertical;
}
