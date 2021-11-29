#include "receptor.hpp"
#include <fstream>
#include <sstream>
#include <boost/asio.hpp>
#include "json.hpp"
#include <iostream>
#include <string>


using boost::asio::ip::udp;
using nlohmann::json;
std::vector<udp::endpoint> vetor_endereco;

Receptor::Receptor(std::shared_ptr<Fruta>fruta) {
    i = 0;
    this->fruta = fruta;
}

void Receptor::recebe( ) {
    char tecla[1000];
    bool rodando = 1;
    int indice = 0;
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
        //std::cout<< recebido << std::endl;
        if(vetor_endereco.size() == 0){
            vetor_endereco.push_back(remote_endpoint);
        }
        /*
        std::cout<< "vetor" <<vetor_endereco.size() << std::endl;
        //std::cout<<recebido["tecla"]<<std::endl;
        for (int i = 0; i < vetor_endereco.size();i++){
            if(vetor_endereco[i]== remote_endpoint){
                indice = i;
                break;
            }

            
            else if(vetor_endereco.size() -1  == i){
                vetor_endereco.push_back(remote_endpoint);
                std::cout<< "dentro do laco" << std::endl;
            }

        }
        */
        
        vetor_cobras[indice].set_direcao(recebido["tecla"]);
        //std::cout<<vetor_cobras[indice].get_direcao() << std::endl;
        for ( int i =0; i < vetor_cobras.size();i++){
            //remote_endpoint = vetor_endereco[i];
           
            enviar["indice"][indice] = indice;
            enviar["cobra"][indice]["vx"] = vetor_cobras[indice].get_vx();
            enviar["cobra"][indice]["vy"] = vetor_cobras[indice].get_vy();
            enviar["cobra"][indice]["x_atual"] = vetor_cobras[indice].get_x_atual();
            enviar["cobra"][indice]["y_atual"] = vetor_cobras[indice].get_y_atual();
            enviar["cobra"][indice]["horizontal"] = vetor_cobras[indice].get_cobrinha_horizontal();
            enviar["cobra"][indice]["vertical"] = vetor_cobras[indice].get_cobrinha_vertical();
            enviar["cobra"][indice]["tamanho"] = (vetor_cobras[indice].get_cobrinha_vertical()).size(); 
            enviar["cobra"][indice]["vida"] = vetor_cobras[indice].get_vida();

            enviar["fruta"]["x_fruta"] = fruta->get_x_fruta();
            enviar["fruta"]["y_fruta"] = fruta->get_y_fruta();
            enviar["rodando"] = rodando;

            mensagem_dados = enviar.dump();
            my_socket.send_to(boost::asio::buffer(mensagem_dados), vetor_endereco[i]);
        }
         

    }
    i = 1;

}

int Receptor::get_i() {
    return i;
}

void Receptor::set_i(int novo_i) {
    i = novo_i;
}