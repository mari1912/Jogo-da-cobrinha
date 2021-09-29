#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "cobra.hpp"
#include "fruta.hpp"
#include "tabuleiro.hpp"
#include "view.hpp"
#include "controller.hpp"


int main() {

    std::shared_ptr<Cobra>cobra(new Cobra(0,0.1,0,0));
    std::shared_ptr<Fruta>fruta(new Fruta());
    std::shared_ptr<Tabuleiro>tabuleiro(new Tabuleiro());
    std::shared_ptr<Controller>controle_sistema(new Controller(tabuleiro, cobra, fruta));
    std::shared_ptr<View>view(new View(cobra, fruta, tabuleiro, controle_sistema));
    
    //for (int i=0; i<1000; i++) {
        view->atualiza_desenho();        
    //}   
    view->finaliza();
    
    return 0;
}