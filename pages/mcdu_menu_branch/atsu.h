#ifndef ATSU_H
#define ATSU_H

#include "aoc_menu.h"
#include "../active_screen.h"
#include "../screen.h"

class Atsu {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        //wskaźnik do podstrony
        Aoc_menu* aoc_menu;

        //deklaracja przyjaciela, żeby screen.cpp mógł wywoływać atsu -> aoc_menu
        friend class Screen;

    public:
        //konstruktor
        Atsu(Screen* screen_ptr);

        //destruktor
        ~Atsu();

        //renderowanie
        void render() const;

        void input_handler(int button_clicked, Active_Screen& current_page);
};

#endif

