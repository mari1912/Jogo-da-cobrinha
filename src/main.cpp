#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include <boost/asio.hpp>
#include <fstream>
#include <iostream>
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
    std::string mensagem_dados;
    json recebido;
    json enviar;
    char tecla[100];
    int pos = 0;
    std::ifstream f;
    std::shared_ptr<Cobra>cobra(new Cobra(0,1,0,0));
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado(cobra,fruta));
    std::shared_ptr<Controller>controller(new Controller(tabuleiro, cobra, fruta, teclado));
    std::shared_ptr<View>view(new View(cobra, fruta, tabuleiro));

    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                        // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service, // io service
                                local_endpoint); // endpoint

    udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

    while(rodando) {

        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = false;
            }
        }

        if(cobra->get_vida() == 0) {
            rodando = false;
        }

        controller->muda_posicao(pos);
        controller->calcula_x_cobrinha();
        controller->calcula_y_cobrinha();
        controller->verifica_posicao();


        my_socket.receive_from(boost::asio::buffer(tecla,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente
//        std::cout<<"aqui"<<std::endl;

        std::stringstream(tecla) >> recebido;
 //       std::cout<<recebido<<std::endl;
        pos = recebido["tecla"];

        
        enviar["cobra"]["vx"] = cobra->get_vx();
        enviar["cobra"]["vy"] = cobra->get_vy();
        enviar["cobra"]["x_atual"] = cobra->get_x_atual();
        enviar["cobra"]["y_atual"] = cobra->get_y_atual();
        enviar["cobra"]["horizontal"] = cobra->get_cobrinha_horizontal();
        enviar["cobra"]["vertical"] = cobra->get_cobrinha_vertical();
        enviar["cobra"]["tamanho"] = (cobra->get_cobrinha_vertical()).size(); 

        enviar["fruta"]["x_fruta"] = fruta->get_x_fruta();
        enviar["fruta"]["y_fruta"] = fruta->get_y_fruta();

        enviar["rodando"] = rodando;

        mensagem_dados = enviar.dump();
        my_socket.send_to(boost::asio::buffer(mensagem_dados), remote_endpoint);
//        std::cout<<"Enviado pelo server"<<mensagem_dados<<std::endl;

        view->render();

        SDL_Delay(150);
    }    

    view->finaliza();
    
    return 0;
}
