#include "model.hpp"
#include "controller.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma once

class View {
  
  private:
    std::shared_ptr<Model>model;
    std::shared_ptr<Controller>controller;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;    
    SDL_Window* window = nullptr;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Texture *texture2;
    SDL_Rect target;
    bool rodando;
    SDL_Event evento; // eventos discretos
    const Uint8* state; // estado do teclado
    
  public:
    View(std::shared_ptr<Model>model, std::shared_ptr<Controller>controller);
    void atualiza();
    void finaliza();
    /*
    SDL_Rect get_target();
    SDL_Renderer* get_renderer();
    SDL_Texture* get_texture();
    SDL_Texture* get_texture2();
    SDL_Window* get_window();
    void set_target(SDL_Rect new_target);
    */
};