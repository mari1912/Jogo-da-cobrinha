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
    char tecla[1000];
    int pos = 0;
    std::ifstream f;
    std::shared_ptr<Cobra>cobra(new Cobra(0,0,0,0));
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Fruta>fruta(new Fruta(tabuleiro));
    std::shared_ptr<Teclado>teclado(new Teclado(cobra,fruta));
    std::shared_ptr<Controller>controller(new Controller(tabuleiro, cobra, fruta, teclado));
    std::shared_ptr<View>view(new View(cobra, fruta, tabuleiro));
    std::shared_ptr<Receptor>r(new Receptor(cobra, fruta));
    std::thread t1(&Receptor::recebe, r);

    while(rodando) {

        //espera que a tecla espaco seja apertada antes de iniciar o jogo
        teclado->inicia_jogo();
        
        //caso o usuario feche a janela do jogo
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = false;
            }
        }

        //se a cobra morrer
        if(cobra->get_vida() == 0) {
            rodando = false;
        }

        //se o jogo estiver iniciado, o controller o executa
        if(teclado->get_iniciar() == 1) {
        
            controller->muda_posicao(cobra->get_direcao());
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
