#include "cobra.hpp"
#include "fruta.hpp"
#include "tabuleiro.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma once

class View {
  
  private:
    std::shared_ptr<Cobra>cobra;
    std::shared_ptr<Fruta>fruta;
    std::shared_ptr<Tabuleiro>tabuleiro;
    const int SCREEN_WIDTH = 860;
    const int SCREEN_HEIGHT = 640;
    const int BLOCK_WIDTH = 20;
    const int BLOCK_HEIGHT = 20;    
    SDL_Window* window = nullptr;
    SDL_Renderer *renderer;

  public:
    View(std::shared_ptr<Cobra>cobra, std::shared_ptr<Fruta>fruta, std::shared_ptr<Tabuleiro>tabuleiro); //construtor
    void finaliza();                                                                                     //finaliza o jogo (as imagens do jogo fecham)
    void render();                                                                                       //monstra as imagens na tela
};