#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

int main() {

    std::shared_ptr<Model>modelo(new Model(50, 15, 0.1, 1, 5, 2));
    std::shared_ptr<Controller>controle_sistema(new Controller(modelo));
    std::shared_ptr<View>view(new View(modelo, controle_sistema));
    
    for (int i=0; i<1000; i++) {
        view->atualiza();        
    }   
    view->finaliza();
    
    return 0;
}