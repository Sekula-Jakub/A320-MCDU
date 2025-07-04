#pragma once
#include "../headers/screen.h"
#include <string>
#include "init_page.h"

class Flight_Plan {
private:
    Screen* screen;     //wskaźnik do obiektu klasy Screen

    //Wskaźnik do InitPage do
    Init_Page* init_page;

public:
    //konstruktor
    Flight_Plan(Screen* screen, Init_Page* init_page);

    //destruktor
    ~Flight_Plan();

    void render();
};