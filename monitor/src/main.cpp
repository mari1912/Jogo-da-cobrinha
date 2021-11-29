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
 * @date 05/10/2021
 * @version 1.0 
 */

/**
 * @return 0 
 */ 
int main() {

    bool rodando = true;
    SDL_Event evento; /* ! eventos discretos */ 
    char dados_recebidos[1000];
    json tec;
    json j;
    std::string dados_enviados;
    std::ifstream f;
    //std::shared_ptr<Cobra>cobra(new Cobra(0,1,0,0));
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado(fruta));
    std::shared_ptr<View>view(new View(fruta, tabuleiro));
    
    Cobra cobra1(0,0,0,0);
    vetor_cobras.push_back(cobra1);

    boost::asio::io_service io_service;

    udp::endpoint local_endpoint(udp::v4(), 0);
    udp::socket meu_socket(io_service, local_endpoint);

    // Encontrando IP remoto
    boost::asio::ip::address ip_remoto =
    boost::asio::ip::address::from_string("127.0.0.1");

    udp::endpoint remote_endpoint(ip_remoto, 9001);
    
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
 //       std::cout<<tec["tecla"]<<std::endl;

       //Envia mensagem
        dados_enviados = tec.dump();
        meu_socket.send_to(boost::asio::buffer(dados_enviados), remote_endpoint);
   //     std::cout<<"Enviado pelo monitor"<<dados_enviados<<std::endl;

        meu_socket.receive_from(boost::asio::buffer(dados_recebidos,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente
    
        std::stringstream(dados_recebidos) >> j;
 //       std::cout<<"Recebido pelo monitor"<<j<<std::endl;

        for ( int i =0; i < vetor_cobras.size(); i++){
            vetor_cobras[0].set_vx(j["cobra"][0]["vx"]);
            vetor_cobras[0].set_vy(j["cobra"][0]["vy"]);
            vetor_cobras[0].set_x_atual(j["cobra"][0]["x_atual"]);
            vetor_cobras[0].set_y_atual(j["cobra"][0]["y_atual"]);
            vetor_cobras[0].set_vida(j["cobra"][0]["vida"]);
            vetor_cobras[0].set_cobrinha_vertical(j["cobra"][0]["vertical"]);
            vetor_cobras[0].set_cobrinha_horizontal(j["cobra"][0]["horizontal"]);        
        
        }
       
        rodando = j["rodando"];

        fruta->set_x_fruta(j["fruta"]["x_fruta"]);
        fruta->set_y_fruta(j["fruta"]["y_fruta"]);
        
        view->render();
        
    }   

    view->finaliza();

    return 0;
}