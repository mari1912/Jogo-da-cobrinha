#include <memory>
#include "cobra.hpp"
#include "fruta.hpp"
#include "teclado.hpp"
#include <vector>
#include <fstream>
#include <boost/asio.hpp>
#pragma once

using boost::asio::ip::udp;
extern std::vector<udp::endpoint> vetor_endereco;
extern std::vector<Cobra> vetor_cobras;
class Receptor {
    private:
        std::shared_ptr<Fruta>fruta;
        
    public:
        Receptor(std::shared_ptr<Fruta>fruta);
        void recebe();
        void conecta();
        void primeiro_envio();

};