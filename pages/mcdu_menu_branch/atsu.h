#pragma once
#include "aoc_menu.h"
#include "../active_screen.h"
#include "../../headers/screen.h"
//class Screen;

class Atsu {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

    //podstrony
    Aoc_menu* aoc_menu;

    //deklaracja przyjaciela
    friend class Screen;

public:

    //konstruktor
    explicit Atsu(Screen* screen_ptr);

    //destruktor
    ~Atsu();

    //renderowanie
    void render() const;

    void input_handler(int button_clicked, Active_Screen& current_page);
};

