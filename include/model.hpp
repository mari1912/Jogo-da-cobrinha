#pragma once

class Model {

    private: 
        float x0, v0, dt, massa, k, b;
        float x_atual;
        float v_atual;
        float aceleracao;
    
    public:
        Model(float x0, float v0, float dt, float massa, float k, float b);
        float get_x_atual();
        float get_v_atual();
        float get_aceleracao();
        float get_k();
        float get_b();
        float get_massa();
        float get_dt();
        void set_x_atual(float x_novo);
        void set_v_atual(float v_novo);
        void set_aceleracao(float aceleracao_novo);
};