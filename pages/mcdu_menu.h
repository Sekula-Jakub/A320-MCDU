#ifndef MCDU_MENU_H
#define MCDU_MENU_H

#include "atsu.h"
#include "fmgc.h"
#include "active_screen.h"
#include "../screen.h"

class Mcdu_Menu {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        //wskazniki na podstrony
        Atsu* atsu;
        Fmgc* fmgc;

        //deklaracja klasy przyjaciela, żeby screen.cpp mogl wywolywac mcdu_menu->atsu
        friend class Screen;

    public:
        //konstruktor
        explicit Mcdu_Menu(Screen* screen_ptr);

        //destruktor
        ~Mcdu_Menu();

        void input_handler(int button_clicked, Active_Screen& current_page) const;

        void render();
};

#endif

