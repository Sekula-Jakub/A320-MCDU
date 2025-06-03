#pragma once
#include "screen.h"
#include "flt_init.h"
#include "wx.h"
//class Screen;

class Aoc_menu {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

    //podstrony
    Flt_Init* flt_init;
    Wx* wx;

    friend class Screen;

public:

    //konstruktor
    explicit Aoc_menu(Screen* screen_ptr);

    //destruktor
    ~Aoc_menu();

    //renderowanie
    void render() const;

    void input_handler(int button_clicked, Active_Screen& current_page);
};
