#include <vector>
#pragma once


class Cobra {

    private: 
        int x_atual, y_atual, vida;
        float vx, vy;
        std::vector<int> cobrinha_horizontal;
        std::vector<int> cobrinha_vertical;
        
    public:
        Cobra (int x_atual, float vx, int y_atual, float vy);
        int get_x_atual();
        float get_vx();
        int get_y_atual();
        int get_vida();
        float get_vy();
        std::vector <int> get_cobrinha_horizontal();
        std::vector <int> get_cobrinha_vertical();
        void set_x_atual(int x_novo);
        void set_vx(float vx_novo);
        void set_y_atual(int y_novo);
        void set_vy(float vy_novo);
        void set_vida(int vida_nova);
        void set_cobrinha_vertical(std::vector<int> vect);
        void set_cobrinha_horizontal(std::vector<int> vect);
        void salvar_jogo();
        void recuperar_jogo();
};

extern std::vector<Cobra> vetor_cobras;