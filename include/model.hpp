#pragma once

class Model {

    private: 
        float x_atual, vx;
        float y_atual, vy;
        float dt;
        
    public:
        Model (float x_atual, float vx, float y_atual, float vy);
        float get_x_atual();
        float get_vx();
        float get_y_atual();
        float get_vy();
        float get_dt();
        void set_x_atual(float x_novo);
        void set_vx(float vx_novo);
        void set_y_atual(float y_novo);
        void set_vy(float vy_novo);
};