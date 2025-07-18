//aoc_menu.h
//Renderuje ekran Aoc Menu
//Zawiera wskzniki do podstron i tworzy te podstrony alokujac do nich pamiec

#ifndef AOC_MENU_H
#define AOC_MENU_H

#include "../screen.h"
#include "flt_init.h"
#include "wx.h"

class Aoc_menu {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        //wskaźniki na podstrony
        Flt_Init* flt_init;
        Wx* wx;

        //deklaracja klasy przyjaciela, żeby screen.cpp mogl wywolywac aoc_menu -> (wskaznika na podstrone)
        friend class Screen;

    public:
        //konstruktor
        explicit Aoc_menu(Screen* screen_ptr);

        //destruktor
        ~Aoc_menu();

        //renderowanie
        void render() const;

        void input_handler(int button_clicked, Active_Screen& current_page) const;
};

#endif