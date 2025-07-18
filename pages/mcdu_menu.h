//mcdu_menu.h
//Wyswietla strone Mcdu Menu
//Zawiera wskazniki do podstron i tworzy te podstrony alokujac do nich pamiec w konstruktorze

#ifndef MCDU_MENU_H
#define MCDU_MENU_H

#include "atsu.h"
#include "fmgc.h"
#include "active_screen.h"
#include "../screen.h"
#include "data_page.h"

class Mcdu_Menu {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        //wskazniki na podstrony
        Atsu* atsu;

        Data_Page data_page_copy;   //kopia obiektu Data_Page

        //deklaracja klasy przyjaciela, żeby screen.cpp mogl wywolywac mcdu_menu->atsu
        friend class Screen;

    public:
        //konstruktor
        explicit Mcdu_Menu(Screen* screen_ptr);

        //destruktor
        ~Mcdu_Menu();

        void input_handler(int button_clicked, Active_Screen& current_page) const;

        void render() const;
};

#endif

