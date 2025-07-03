#pragma once
#include "../headers/screen.h"

class Init_Page {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

    //friend class Screen;
    //zaprzyjazniona klasa Flt_Init, żeby mieć dostęp do parametrów wprowadzonych wcześniej
    friend class Flt_Init;

public:
    //konstruktor
    Init_Page(Screen* screen_ptr);

    //destruktor
    ~Init_Page();

    void render();
};
