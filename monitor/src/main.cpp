#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include "cobra.hpp"
#include "fruta.hpp"
#include "tabuleiro.hpp"
#include "view.hpp"
#include "json.hpp"
#include "teclado.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using boost::asio::ip::udp;
using nlohmann::json;
std::vector<Cobra> vetor_cobras;

/**
 * @brief Jogo da Cobrinha desenvolvido para a disciplina EA872
 * @author Mariana Sartorato Jorge
 * @author Daniele Souza Gonçalves 
 * @date 06/12/2021
 * @version 2.0 
 */

/**
 * @return 0 
 */ 
int main() {

    bool rodando = true;
    SDL_Event evento; /* ! eventos discretos */ 
    char mensagem_conexao[1000];
    char dados_recebidos[1000];
    json tec;
    json j;
    int indice;
    int numero_cobras;
    std::string dados_enviados;
    std::ifstream f;
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado(fruta));
    std::shared_ptr<View>view(new View(fruta, tabuleiro));

    boost::asio::io_service io_service;

    udp::endpoint local_endpoint(udp::v4(), 0);
    udp::socket meu_socket(io_service, local_endpoint);

    // Encontrando IP remoto
    boost::asio::ip::address ip_remoto =
    boost::asio::ip::address::from_string("127.0.0.1");

    udp::endpoint remote_endpoint(ip_remoto, 9001);
    
    std::string v("Conectando ao servidor");

    meu_socket.send_to(boost::asio::buffer(v), remote_endpoint);

    Cobra cobra1(0,0,0,0);
    Cobra cobra2(43*19,0,0,0);
    Cobra cobra3(0,0,32*19,0);
    Cobra cobra4(43*19,0,32*19,0);
    vetor_cobras.push_back(cobra1);
    vetor_cobras.push_back(cobra2);
    vetor_cobras.push_back(cobra3);
    vetor_cobras.push_back(cobra4);

    meu_socket.receive_from(boost::asio::buffer(mensagem_conexao,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente

    std::cout<<mensagem_conexao<<std::endl;

    meu_socket.receive_from(boost::asio::buffer(dados_recebidos,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente

    

    std::stringstream(dados_recebidos) >> j;
    
    for (int i = 0; i < j["indice"]; i++) {
        vetor_cobras[i].set_vx(j["cobra"][i]["vx"]);
        vetor_cobras[i].set_vy(j["cobra"][i]["vy"]);
        vetor_cobras[i].set_x_atual(j["cobra"][i]["x_atual"]);
        vetor_cobras[i].set_y_atual(j["cobra"][i]["y_atual"]);
        vetor_cobras[i].set_vida(j["cobra"][i]["vida"]);
        vetor_cobras[i].set_cobrinha_vertical(j["cobra"][i]["vertical"]);
        vetor_cobras[i].set_cobrinha_horizontal(j["cobra"][i]["horizontal"]);        
    }

    fruta->set_x_fruta(j["fruta"]["x_fruta"]);
    fruta->set_y_fruta(j["fruta"]["y_fruta"]);
    numero_cobras = j["ncobras"];
  

    std::cout << "Conectado" << std::endl;
    while(rodando) {

        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = false;
            }
        }

        //se a cobra morrer
        int cobras_vivas = 0;
        for (int i = 0; i < vetor_cobras.size();i++){
            if(vetor_cobras[i].get_vida() == 1){
                 cobras_vivas = cobras_vivas +1 ;
            }
        }

        if(cobras_vivas == 0){
            rodando = false;
        }
        
        tec["tecla"] = teclado->le_teclado();
 
       //Envia mensagem
        dados_enviados = tec.dump();
        meu_socket.send_to(boost::asio::buffer(dados_enviados), remote_endpoint);


        meu_socket.receive_from(boost::asio::buffer(dados_recebidos,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente
   
        std::stringstream(dados_recebidos) >> j;

        indice = j["indice"];

        vetor_cobras[indice].set_vx(j["cobra"][indice]["vx"]);
        vetor_cobras[indice].set_vy(j["cobra"][indice]["vy"]);
        vetor_cobras[indice].set_x_atual(j["cobra"][indice]["x_atual"]);
        vetor_cobras[indice].set_y_atual(j["cobra"][indice]["y_atual"]);
        vetor_cobras[indice].set_vida(j["cobra"][indice]["vida"]);
        vetor_cobras[indice].set_cobrinha_vertical(j["cobra"][indice]["vertical"]);
        vetor_cobras[indice].set_cobrinha_horizontal(j["cobra"][indice]["horizontal"]);        
        
        fruta->set_x_fruta(j["fruta"]["x_fruta"]);
        fruta->set_y_fruta(j["fruta"]["y_fruta"]);
        
        view->render(numero_cobras);
        
    }   

    view->finaliza();

    return 0;
}