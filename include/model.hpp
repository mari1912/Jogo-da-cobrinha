#pragma once

class Model {

    private: 
        int x_atual, vx;
        int y_atual, vy;
        int x_fruta, y_fruta;
        const int tabuleiro_horizontal = 860, tabuleiro_vertical = 640;
        const int bloco_horizontal = 20, bloco_vertical = 20;
        
    public:
        Model (int x_atual, int vx, int y_atual, int vy);
        int get_x_atual();
        int get_vx();
        int get_y_atual();
        int get_vy();
        int get_x_fruta();
        int get_y_fruta();
        int get_tabuleiro_horizontal();
        int get_tabuleiro_vertical();
        int get_bloco_horizontal();
        int get_bloco_vertical();
        void set_x_atual(int x_novo);
        void set_vx(int vx_novo);
        void set_y_atual(int y_novo);
        void set_vy(int vy_novo);
        void set_x_fruta(int x_fruta_novo);
        void set_y_fruta(int y_fruta_novo);
};