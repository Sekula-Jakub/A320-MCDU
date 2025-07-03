#pragma once
#include "mcdu_menu_branch/atsu.h"
#include "mcdu_menu_branch/fmgc.h"
#include "active_screen.h"
#include "../headers/screen.h"

class Mcdu_Menu {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

    //podstrony
    Atsu* atsu;
    Fmgc* fmgc;

    //deklaracja klasy przyjaciela, żeby screen mogl wywolywac mcdu_menu->atsu
    friend class Screen;

public:

    //konstruktor
    explicit Mcdu_Menu(Screen* screen_ptr);

    //destruktor
    ~Mcdu_Menu();

    void input_handler(int button_clicked, Active_Screen& current_page);

    void render();

};

