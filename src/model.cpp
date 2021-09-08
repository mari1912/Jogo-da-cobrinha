#include "model.hpp"

//Construtor
Model::Model(float x0, float v0, float dt, float massa, float k, float b) {
    this->x0 = x0;
    this->v0 = v0;
    this->dt = dt;
    this->massa = massa;
    this->k = k;
    this->b = b;
    x_atual = x0;
    v_atual = v0;
    aceleracao = 0;
}

//Permite acesso aos dados
float Model::get_x_atual(){
    return x_atual;
}

float Model::get_v_atual(){
    return v_atual;
}

float Model::get_aceleracao(){
    return aceleracao;
}

float Model::get_k(){
    return k;
}

float Model::get_b(){
    return b;
}

float Model::get_massa() {
    return massa;
}

float Model::get_dt(){
    return dt;
}

//Permite alterar os dados
void Model::set_x_atual(float x_novo){
    x_atual = x_novo;
}

void Model::set_v_atual(float v_novo){
    v_atual = v_novo;
}

void Model::set_aceleracao(float aceleracao_novo){
    aceleracao = aceleracao_novo;
}