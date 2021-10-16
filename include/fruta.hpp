#include "tabuleiro.hpp"
#include <memory>

#pragma once

class Fruta {

    private: 
        int x_fruta, y_fruta;
        std::shared_ptr<Tabuleiro>tabuleiro;
        
    public:
        Fruta (std::shared_ptr<Tabuleiro>tabuleiro);
        int get_x_fruta();
        int get_y_fruta();
        void set_x_fruta(int x_fruta_novo);
        void set_y_fruta(int y_fruta_novo);
        void salvar_jogo_fruta();
        void recuperar_jogo_fruta();
};