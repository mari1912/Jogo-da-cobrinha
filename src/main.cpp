#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include <boost/asio.hpp>
#include <fstream>
#include "cobra.hpp"
#include "fruta.hpp"
#include "tabuleiro.hpp"
#include "teclado.hpp"
#include "view.hpp"
#include "controller.hpp"
#include "json.hpp"

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
    std::string v;
    json j;
    std::ifstream f;
    std::shared_ptr<Cobra>cobra(new Cobra(0,1,0,0));
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado(cobra,fruta));
    std::shared_ptr<Controller>controller(new Controller(tabuleiro, cobra, fruta, teclado));
    std::shared_ptr<View>view(new View(cobra, fruta, tabuleiro));
    
    while(rodando) {

        controller->muda_posicao();
        controller->calcula_x_cobrinha();
        controller->calcula_y_cobrinha();
        controller->verifica_posicao();

        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = false;
            }
        }

        j["cobra"]["vx"] = cobra->get_vx();
        j["cobra"]["vy"] = cobra->get_vy();
        j["cobra"]["x_atual"] = cobra->get_x_atual();
        j["cobra"]["y_atual"] = cobra->get_y_atual();
        j["cobra"]["horizontal"] = cobra->get_cobrinha_horizontal();
        j["cobra"]["vertical"] = cobra->get_cobrinha_vertical();
        j["cobra"]["tamanho"] = cobra->get_cobrinha_vertical().size(); 

        j["fruta"]["x_fruta"] = fruta->get_x_fruta();
        j["fruta"]["y_fruta"] = fruta->get_y_fruta();

        j["rodando"] = rodando;

        boost::asio::io_service io_service;

        udp::endpoint local_endpoint(udp::v4(), 0);
        udp::socket meu_socket(io_service, local_endpoint);

        // Encontrando IP remoto
        boost::asio::ip::address ip_remoto =
        boost::asio::ip::address::from_string("127.0.0.1");

        udp::endpoint remote_endpoint(ip_remoto, 9001);
       
        v = j.dump();
        meu_socket.send_to(boost::asio::buffer(v), remote_endpoint);


        /* !coloca imagem na tela */ 
        view->render();

        /* ! Delay para diminuir o framerate */ 
        SDL_Delay(150);
    }
         
    view->finaliza();
    
    return 0;
}