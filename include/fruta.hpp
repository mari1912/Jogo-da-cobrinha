#pragma once

class Fruta {

    private: 
        int x_fruta, y_fruta;
        
    public:
        Fruta ();
        int get_x_fruta();
        int get_y_fruta();
        void set_x_fruta(int x_fruta_novo);
        void set_y_fruta(int y_fruta_novo);
};