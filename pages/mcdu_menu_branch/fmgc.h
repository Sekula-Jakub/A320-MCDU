#pragma once
#include "../../headers/screen.h"
//class Screen;

class Fmgc {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

public:

    bool active = false;

    //konstruktor
    explicit Fmgc(Screen* screen_ptr);

    //destruktor
    ~Fmgc();

    //renderowanie
    void render() const;
};
