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

using boost::asio::ip::udp;
using nlohmann::json;

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
    std::shared_ptr<Cobra>cobra(new Cobra(0,1,0,0));
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado(cobra, fruta));
    std::shared_ptr<View>view(new View(cobra, fruta, tabuleiro));
    

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

        tec["tecla"] = teclado->le_teclado();

       //Envia mensagem
        dados_enviados = tec.dump();
        meu_socket.send_to(boost::asio::buffer(dados_enviados), remote_endpoint);
 //     std::cout<<"Enviado pelo monitor"<<dados_enviados<<std::endl;

        meu_socket.receive_from(boost::asio::buffer(dados_recebidos,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente
     
        std::stringstream(dados_recebidos) >> j;
 //       std::cout<<"Recebido pelo monitor"<<j<<std::endl;

        cobra->set_vx(j["cobra"]["vx"]);
        cobra->set_vy(j["cobra"]["vy"]);
        cobra->set_x_atual(j["cobra"]["x_atual"]);
        cobra->set_y_atual(j["cobra"]["y_atual"]);

        for (int i=0; i<j["cobra"]["tamanho"]; i++) {
            cobra->set_cobrinha_vertical(j["cobra"]["vertical"]);
            cobra->set_cobrinha_horizontal(j["cobra"]["horizontal"]);        
        }
    
        rodando = j["rodando"];

        fruta->set_x_fruta(j["fruta"]["x_fruta"]);
        fruta->set_y_fruta(j["fruta"]["y_fruta"]);
        
        view->render();
    }   

    view->finaliza();

    return 0;
}