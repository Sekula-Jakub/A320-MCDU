#pragma once
#include "mcdu_menu_branch/atsu.h"
#include "mcdu_menu_branch/fmgc.h"
#include "active_screen.h"

class Mcdu_Menu {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen
    Atsu* atsu;
    Fmgc* fmgc;


public:

    //konstruktor
    Mcdu_Menu(Screen* screen_ptr);

    //destruktor
    ~Mcdu_Menu();

    void input_handler(int button_clicked, Active_Screen& current_page);

    void render();

};

