#include <memory>
#include "cobra.hpp"
#include "fruta.hpp"

#pragma once

class Receptor {
    private:
        int i;
        std::shared_ptr<Cobra>cobra;
        std::shared_ptr<Fruta>fruta;
        
    public:
        Receptor(std::shared_ptr<Cobra>cobra,std::shared_ptr<Fruta>fruta);
        int get_i();
        void recebe();
        void set_i(int novo_i);
};