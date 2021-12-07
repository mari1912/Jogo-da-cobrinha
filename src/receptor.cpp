#include "receptor.hpp"
#include <sstream>
#include <boost/asio.hpp>
#include "json.hpp"
#include <iostream>
#include <string>

using boost::asio::ip::udp;
using nlohmann::json;
std::vector<udp::endpoint> vetor_endereco;

/**
 * @brief Construct a new Receptor:: Receptor object
 * 
 */

Receptor::Receptor(std::shared_ptr<Fruta>fruta) {
    this->fruta = fruta;
}

/**
 * @brief conecta os jogadores ( monitores) ao servidor 
 * 
 */
void Receptor::conecta() {
    Cobra cobra1(0,0,0,0);
    Cobra cobra2(43*19,0,0,0);
    Cobra cobra3(0,0,32*19,0);
    Cobra cobra4(43*19,0,32*19,0);
 
    char v[120];

    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                    // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service, // io service
                            local_endpoint); // endpoint

    udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar


    my_socket.receive_from(boost::asio::buffer(v,120), // Local do buffer
                        remote_endpoint); // Confs. do Cliente

    std::cout << v << std::endl;
    std::cout << "Fim de mensagem!" << std::endl;


    // Respondendo a mensagem
    std::string msg("Recebido! Obrigado, cambio e desligo!");
    my_socket.send_to(boost::asio::buffer(msg), remote_endpoint);

    std::cout << "Mensagem de retorno enviada" << std::endl;

    if(vetor_endereco.size() == 0){
        vetor_endereco.push_back(remote_endpoint);
        vetor_cobras.push_back(cobra1);
    }
    else if(vetor_endereco.size() == 1 && remote_endpoint != vetor_endereco[0]){
        vetor_endereco.push_back(remote_endpoint);
        vetor_cobras.push_back(cobra2);
    }
    else if(vetor_endereco.size() == 2 && remote_endpoint != vetor_endereco[0] && remote_endpoint != vetor_endereco[1]){
        vetor_endereco.push_back(remote_endpoint);
        vetor_cobras.push_back(cobra3);
    }
    else if(vetor_endereco.size() == 3 && remote_endpoint != vetor_endereco[0] && remote_endpoint != vetor_endereco[1] && remote_endpoint != vetor_endereco[2]){
        vetor_endereco.push_back(remote_endpoint);
        vetor_cobras.push_back(cobra4);
    }
}

/**
 * @brief faz o primeiro envio iniciando os jogadores com os dados iniciais 
 * 
 */
void Receptor::primeiro_envio() {
    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                        // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service, // io service
                                local_endpoint); // endpoint

    json enviar;
    std::string mensagem_dados;

    for (int indice = 0; indice < vetor_endereco.size(); indice++) {
        enviar["ncobras"] = vetor_cobras.size();
        enviar["indice"] = indice;
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
        mensagem_dados = enviar.dump();
        my_socket.send_to(boost::asio::buffer(mensagem_dados), vetor_endereco[indice]);
    }
}

/**
 * @brief recebe dados do servidor 
 * 
 */
void Receptor::recebe() {
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

        for(int i=0; i<vetor_endereco.size(); i++) {
            if(vetor_endereco[i] == remote_endpoint) {
                indice = i;
            }
        }
        
        vetor_cobras[indice].set_direcao(recebido["tecla"]);
    
        for ( int i =0; i < vetor_cobras.size();i++){
           
            enviar["indice"] = indice;
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
            mensagem_dados = enviar.dump();
            my_socket.send_to(boost::asio::buffer(mensagem_dados), vetor_endereco[i]);
        }
         

    }

}
