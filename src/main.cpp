#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

int main() {

    std::shared_ptr<Model>modelo(new Model(0,1,0,0));
    std::shared_ptr<Controller>controle_sistema(new Controller(modelo));
    std::shared_ptr<View>view(new View(modelo, controle_sistema));
    
    for (int i=0; i<1000; i++) {
        view->atualiza_desenho();        
    }   
    view->finaliza();
    
    return 0;
}