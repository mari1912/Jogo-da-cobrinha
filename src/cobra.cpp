#include "cobra.hpp"
#include "json.hpp"
#include <fstream>

using nlohmann::json;
/** @brief Construtor */ 
Cobra::Cobra(int x_atual, float vx, int y_atual, float vy) {
    this->x_atual = x_atual;
    this->vx = vx;
    this->y_atual = y_atual;
    this->vy = vy;
    cobrinha_horizontal.push_back(x_atual);
    cobrinha_vertical.push_back(y_atual);
}

/**
 * @return x atual */ 
int Cobra::get_x_atual() {
    return x_atual;
}

/**
 * @return vx */ 
float Cobra::get_vx() {
    return vx;
}

/**
 * @return y atual */ 
int Cobra::get_y_atual() {
    return y_atual;
}

/**
 * @return vy */ 
float Cobra::get_vy() {
    return vy;
}

std::vector<int> Cobra::get_cobrinha_horizontal() {
    return cobrinha_horizontal;
}

std::vector<int> Cobra::get_cobrinha_vertical() {
    return cobrinha_vertical;
}

/* ! permite atualizar os atributos */ 
void Cobra::set_x_atual(int x_novo) {
    x_atual = x_novo;
}

void Cobra::set_vx(float vx_novo) {
    vx = vx_novo;
}

void Cobra::set_y_atual(int y_novo) {
    y_atual = y_novo;
}

void Cobra::set_vy(float vy_novo) {
    vy = vy_novo;
}

void Cobra::set_cobrinha_horizontal(int i, int novo) {
    cobrinha_horizontal[i] = novo;
}

void Cobra::set_cobrinha_vertical(int i, int novo) {
    cobrinha_vertical[i] = novo;
}

void Cobra::set_cobrinha_aumento(int x, int y) {
    cobrinha_horizontal.push_back(x);
    cobrinha_vertical.push_back(y);
}

void Cobra::salvar_jogo(){
    // copiando 
    json j;
    j["cobra"]["vx"] =  get_vx();
    j["cobra"]["vy"] = get_vy();
    j["cobra"]["x_atual"] = get_x_atual();
    j["cobra"]["y_atual"] =  get_y_atual();
    j["cobra"]["horizontal"] =  get_cobrinha_horizontal();
    j["cobra"]["vertical"] =  get_cobrinha_vertical();
   
    std::ofstream f2;
    f2.open("dados.json");
    f2 << j;
    f2.close(); 


    }

void Cobra:: recuperar_jogo(){
    json j2;
    std::vector <int>vetor;
    std::vector <int>vetor2;
    std::ifstream f2;
    f2.open("teste.json");
    f2 >> j2;
    f2.close();
    set_vx(j2["cobra"]["vx"]);
    set_vy(j2["cobra"]["vy"]);
    set_x_atual(j2["cobra"]["x_atual"]);
    set_y_atual(j2["cobra"]["y_atual"]);
    
    //vetor = (j2["cobra"]["horizontal"]);
   // vetor2 = j2["cobra"]["vertical"];

/*
    for(int i = 0; i < vetor.size(); i++){
        set_cobrinha_horizontal(i,j2["cobra"]["horizontal"][i]);
        set_cobrinha_vertical(i,j2["cobra"]["vertical"][i]);
        }
*/
}