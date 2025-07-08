#pragma once
#include "screen.h"
#include "data_base_manager.h"

class Departure_Page_A {
private:
    Screen* screen;     //wskaźnik do obiektu klasy Screen

    //Wskaźnik do InitPage do
    Init_Page* init_page;

public:
    //konstruktor
    Departure_Page_A(Screen* screen);

    //destruktor
    ~Departure_Page_A();

    void render();

};
