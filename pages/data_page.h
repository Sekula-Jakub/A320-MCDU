#pragma once
#include "../headers/screen.h"

class Data_Page {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

    friend class Screen;

public:
    //konstruktor
    Data_Page(Screen* screen_ptr);

    //destruktor
    ~Data_Page();

    void render();
};
