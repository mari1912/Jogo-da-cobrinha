#include <vector>
#pragma once

class Cobra {

    private: 
        int x_atual, y_atual, vida, direcao;
        float vx, vy;
        std::vector<int> cobrinha_horizontal;
        std::vector<int> cobrinha_vertical;
        
    public:
        Cobra (int x_atual, float vx, int y_atual, float vy);
        int get_x_atual();
        float get_vx();
        int get_y_atual();
        float get_vy();
        int get_vida();
        int get_direcao();
        std::vector <int> get_cobrinha_horizontal();
        std::vector <int> get_cobrinha_vertical();
        void set_x_atual(int x_novo);
        void set_vx(float vx_novo);
        void set_y_atual(int y_novo);
        void set_vy(float vy_novo);
        void set_cobrinha_horizontal(int i, int novo); 
        void set_cobrinha_vertical(int i, int novo); 
        void set_cobrinha_aumento(int x, int y);
        void set_vida(int nova_vida);
        void set_direcao(int nova_direcao);
        void salvar_jogo();
        void recuperar_jogo();
};