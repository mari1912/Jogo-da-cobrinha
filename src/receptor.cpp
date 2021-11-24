#include "receptor.hpp"
#include <fstream>
#include <sstream>
#include <boost/asio.hpp>
#include "json.hpp"
#include <iostream>
#include <string>

using boost::asio::ip::udp;
using nlohmann::json;

Receptor::Receptor(std::shared_ptr<Cobra>cobra,std::shared_ptr<Fruta>fruta) {
    i = 0;
    this->cobra = cobra;
    this->fruta = fruta;
}

void Receptor::recebe() {
    char tecla[1000];
    bool rodando = 1;
    json recebido;
    json enviar;
    std::string mensagem_dados;
    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                        // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service, // io service
                                local_endpoint); // endpoint

    udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

    while (rodando) {
        my_socket.receive_from(boost::asio::buffer(tecla,1000), // Local do buffer
                        remote_endpoint); // Confs. do Cliente
        
        std::stringstream(tecla) >> recebido;
        //std::cout<<recebido["tecla"]<<std::endl;
        
        cobra->set_direcao(recebido["tecla"]);
    
        enviar["cobra"]["vx"] = cobra->get_vx();
        enviar["cobra"]["vy"] = cobra->get_vy();
        enviar["cobra"]["x_atual"] = cobra->get_x_atual();
        enviar["cobra"]["y_atual"] = cobra->get_y_atual();
        enviar["cobra"]["horizontal"] = cobra->get_cobrinha_horizontal();
        enviar["cobra"]["vertical"] = cobra->get_cobrinha_vertical();
        enviar["cobra"]["tamanho"] = (cobra->get_cobrinha_vertical()).size(); 
        enviar["cobra"]["vida"] = cobra->get_vida();

        enviar["fruta"]["x_fruta"] = fruta->get_x_fruta();
        enviar["fruta"]["y_fruta"] = fruta->get_y_fruta();
        enviar["rodando"] = rodando;

        mensagem_dados = enviar.dump();
        my_socket.send_to(boost::asio::buffer(mensagem_dados), remote_endpoint);

    }
    i = 1;

}

int Receptor::get_i() {
    return i;
}

void Receptor::set_i(int novo_i) {
    i = novo_i;
}