#pragma once
#include <SFML/Graphics.hpp>

class Screen;

class Mcdu_Menu {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

    public:
        //konstruktor
        Mcdu_Menu(Screen* screen_ptr);

        void render() const;

};

