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
    vida = 1;
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

int Cobra::get_vida() {
    return vida;
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

void Cobra::set_vida(int nova_vida) {
    vida = nova_vida;
}

void Cobra::salvar_jogo(){
    // copiando 
    json j;
    j["cobra"]["vx"] = vx;
    j["cobra"]["vy"] = vy;
    j["cobra"]["x_atual"] = x_atual;
    j["cobra"]["y_atual"] = y_atual;
    j["cobra"]["horizontal"] = cobrinha_horizontal;
    j["cobra"]["vertical"] = cobrinha_vertical;
    j["cobra"]["tamanho"] = cobrinha_vertical.size();
   
    std::ofstream f2;
    f2.open("dados.json");
    f2 << j;
    f2.close(); 
}

void Cobra:: recuperar_jogo(){
    json j2;
    int tam;

    std::ifstream f2;
    f2.open("dados.json");
    f2 >> j2;
    f2.close();
    vx = j2["cobra"]["vx"];
    vy = j2["cobra"]["vy"];
    x_atual = j2["cobra"]["x_atual"];
    y_atual = j2["cobra"]["y_atual"];
    tam = j2["cobra"]["tamanho"];

    cobrinha_vertical.resize(tam);
    cobrinha_horizontal.resize(tam);

    for (int i=0; i < tam; i++) {
        cobrinha_vertical[i] = j2["cobra"]["vertical"][i];
        cobrinha_horizontal[i] = j2["cobra"]["horizontal"][i];
    }
}