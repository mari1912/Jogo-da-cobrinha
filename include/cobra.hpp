#pragma once

class Cobra {

    private: 
        int x_atual, vx;
        int y_atual, vy;
        
    public:
        Cobra (int x_atual, int vx, int y_atual, int vy);
        int get_x_atual();
        int get_vx();
        int get_y_atual();
        int get_vy();
        void set_x_atual(int x_novo);
        void set_vx(int vx_novo);
        void set_y_atual(int y_novo);
        void set_vy(int vy_novo);
};