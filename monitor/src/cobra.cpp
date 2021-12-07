#include "cobra.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>

using nlohmann::json;

/**
 * @brief Construct a new Cobra:: Cobra object
 * 
 * @param x_atual 
 * @param vx 
 * @param y_atual 
 * @param vy 
 */
Cobra::Cobra(int x_atual, float vx, int y_atual, float vy) {
    this->x_atual = x_atual;
    this->vx = vx;
    this->y_atual = y_atual;
    this->vy = vy;
    vida = 1;
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

int Cobra::get_vida() {
    return vida;
}

/**
 * @brief permite atualizar valores da cobrinha na horizontal
 * 
 * @return std::vector<int> 
 */
std::vector<int> Cobra::get_cobrinha_horizontal() {
    return cobrinha_horizontal;
}

/**
 * @brief permite atualizar valores da cobrinha na vertical
 * 
 * @return std::vector<int> 
 */
std::vector<int> Cobra::get_cobrinha_vertical() {
    return cobrinha_vertical;
}

/**
 * @brief  atualiza valores de x 
 * 
 * @param x_novo 
 */
void Cobra::set_x_atual(int x_novo) {
    x_atual = x_novo;
}

/**
 * @brief atualiza valores de vx
 * 
 * @param vx_novo 
 */

void Cobra::set_vx(float vx_novo) {
    vx = vx_novo;
}

/**
 * @brief atualiza valores de y
 * 
 * @param y_novo 
 */
void Cobra::set_y_atual(int y_novo) {
    y_atual = y_novo;
}

/**
 * @brief atualiza valores de vy
 * 
 * @param vy_novo 
 */
void Cobra::set_vy(float vy_novo) {
    vy = vy_novo;
}

/**
 * @brief atualiza valores da cobrinha na vertical
 * 
 * @param vect 
 */
void Cobra::set_cobrinha_vertical(std::vector<int> vect) {
    cobrinha_vertical = vect;
}

/**
 * @brief atualiza valores da cobrinha na horizontal 
 * 
 * @param vect 
 */
void Cobra::set_cobrinha_horizontal(std::vector<int> vect) {
    cobrinha_horizontal = vect;
}

/**
 * @brief atualiza valor da vida 
 * 
 * @param vida_nova 
 */
void Cobra::set_vida(int vida_nova) {
    vida = vida_nova;
}

/**
 * @brief permite salvar o estado do jogo
 * 
 */
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

/**
 * @brief permite recuperar o estado do jogo
 * 
 */
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