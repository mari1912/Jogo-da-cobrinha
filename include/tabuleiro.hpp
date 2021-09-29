#pragma once

class Tabuleiro {

    private: 
        const int tabuleiro_horizontal = 860, tabuleiro_vertical = 640;
        const int bloco_horizontal = 20, bloco_vertical = 20;
        int placar;
        
    public:
        Tabuleiro();
        int get_tabuleiro_horizontal();
        int get_tabuleiro_vertical();
        int get_bloco_horizontal();
        int get_bloco_vertical();
        int get_placar();
        void aumenta_placar();
};