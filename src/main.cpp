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
#include <thread>
#include "receptor.hpp"
#include <vector>

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
    std::string mensagem_dados;
    json recebido;
    json enviar;
    char tecla[1000];
    //std::vector<udp::endpoint> vetor_endereco;
    int pos = 0;
    std::ifstream f;
    std::shared_ptr<Cobra>cobra(new Cobra(0,0,0,0));
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado(fruta));
    std::shared_ptr<Controller>controller(new Controller(tabuleiro, fruta, teclado));
    std::shared_ptr<View>view(new View(fruta, tabuleiro));
    std::shared_ptr<Receptor>r(new Receptor(fruta));
    
    Cobra cobra1(0,0,0,0);
    Cobra cobra2(43,0,0,0);
    Cobra cobra3(0,0,32,0);
    Cobra cobra4(43,0,32,0);
    
    vetor_cobras.push_back(cobra1);

    std::thread t1(&Receptor::recebe, r);

    /*
    while(vetor_endereco.size() <4){
        if(teclado -> get_iniciar() ==1){
            break;
        }

        vetor_endereco.push_back(udp::endpoint());
        if(vetor_endereco.size() == 0){
            cobra1.set_vx(1);           
        }

        else if(vetor_endereco.size() ==1 ){
            cobra1.set_vx(-1);
            cobra1.set_x_atual(43);
            cobra1.set_y_atual(0);
        }
        else if(vetor_endereco.size() ==2 ){
            cobra1.set_vx(1);
            cobra1.set_x_atual(0);
            cobra1.set_y_atual(32);
           
        }
        else {
            cobra1.set_vx(-1);
            cobra1.set_x_atual(43);
            cobra1.set_y_atual(32);
           
        }
        vetor_cobras.push_back(cobra1);
    }   
    */

    while(rodando) {

        //espera que a tecla espaco seja apertada antes de iniciar o jogo
        teclado->inicia_jogo();
/*
        if(teclado->get_iniciar() == 0) {
            /*
            if (vetor_endereco.size() == 1) {
                vetor_cobras.push_back(cobra1);
            }
            /
            if(vetor_endereco.size() == 2) {
                vetor_cobras.push_back(cobra2);
            }
            else if(vetor_endereco.size() == 3) {
                vetor_cobras.push_back(cobra3);
            }
            else if(vetor_endereco.size() == 4) {
                vetor_cobras.push_back(cobra4);
            }
        }
  */      
        //caso o usuario feche a janela do jogo
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
        

        //se o jogo estiver iniciado, o controller o executa
        if(teclado->get_iniciar() == 1) {
            //std::cout<<vetor_cobras[0].get_direcao() << std::endl;
            //precisa mudar isso depois 
            controller->muda_posicao(vetor_cobras[0].get_direcao(),0);
           // std::cout<< vetor_cobras[0].get_vx() << std::endl;
            //std::cout<< vetor_cobras[0].get_vy() << std::endl;
            controller->calcula_x_cobrinha();
            controller->calcula_y_cobrinha();
            controller->verifica_posicao();
        }

        //coloca a imagem na tela
        view->render();

        //delay do jogo
        SDL_Delay(150);
    }    

    //finaliza 
    view->finaliza();
    
    //destroi a thread
    t1.join();  

    return 0;
}
