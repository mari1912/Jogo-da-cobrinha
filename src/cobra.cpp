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
    direcao = 2; //direcao inicial para qual a cobra vai -> nesse caso, para a direita
    cobrinha_horizontal.push_back(x_atual);
    cobrinha_vertical.push_back(y_atual);
    vida = 1;
}

/**
 * @return permite atualizar x atual */ 
int Cobra::get_x_atual() {
    return x_atual;
}

/**
 * @return  permite atualizar vx atual */ 
float Cobra::get_vx() {
    return vx;
}

/**
 * @return permite atualizar  y atual */ 
int Cobra::get_y_atual() {
    return y_atual;
}

/**
 * @return vida
 */
int Cobra::get_vida() {
    return vida;
}

/**
 * @return vy */ 
float Cobra::get_vy() {
    return vy;
}

/**
 * @brief pega a direcao 
 * 
 * @return int 
 */
int Cobra::get_direcao() {
    return direcao;
}

/**
 * @brief  pega a posicao da cobrinha na horizontal
 * 
 * @return std::vector<int> 
 */
std::vector<int> Cobra::get_cobrinha_horizontal() {
    return cobrinha_horizontal;
}

/**
 * @brief pega a posicao da cobrinha na vertical
 * 
 * @return std::vector<int> 
 */
std::vector<int> Cobra::get_cobrinha_vertical() {
    return cobrinha_vertical;
}

/**
 * @brief permite atualilzar a posicao x 
 * 
 * @param x_novo 
 * @return permite 
 */

void Cobra::set_x_atual(int x_novo) {
    x_atual = x_novo;
}

/**
 * @brief permite atualizar a velocidade vx
 * 
 * @param vx_novo 
 */
void Cobra::set_vx(float vx_novo) {
    vx = vx_novo;
}

/**
 * @brief permite atualizar a posicao y
 * 
 * @param y_novo 
 */
void Cobra::set_y_atual(int y_novo) {
    y_atual = y_novo;
}

/**
 * @brief permite atualizar a velocidade vy
 * 
 * @param vy_novo 
 */
void Cobra::set_vy(float vy_novo) {
    vy = vy_novo;
}

/**
 * @brief atualiza a posicao a cobrinha na horizontal
 * 
 * @param i 
 * @param novo 
 */
void Cobra::set_cobrinha_horizontal(int i, int novo) {
    cobrinha_horizontal[i] = novo;
}

/**
 * @brief atualiza a posicao a cobrinha na vertical
 * 
 * @param i 
 * @param novo 
 */
void Cobra::set_cobrinha_vertical(int i, int novo) {
    cobrinha_vertical[i] = novo;
}

/**
 * @brief aumenta o tamanho da cobrinha
 * 
 * @param x 
 * @param y 
 */
void Cobra::set_cobrinha_aumento(int x, int y) {
    cobrinha_horizontal.push_back(x);
    cobrinha_vertical.push_back(y);
}

/**
 * @brief seta a vida atual da cobrinha
 * 
 * @param nova_vida 
 */
void Cobra::set_vida(int nova_vida) {
    vida = nova_vida;
}

/**
 * @brief seta a direção da cobrinha 
 * 
 * @param nova_direcao 
 */
void Cobra::set_direcao(int nova_direcao) {
    direcao = nova_direcao;
}

/**
 * @brief permite salvar o estado atual do jogo
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
 * @brief permite recuperar o estado anterior do jogo
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