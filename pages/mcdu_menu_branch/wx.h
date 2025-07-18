//wx.h
//Renderuje ekran Aoc Menu
//Zawiera wskznik do podstrony i tworzy podstrone alokujac do nich pamiec

#ifndef WX_H
#define WX_H

#include "../screen.h"
#include "weather_req.h"

class Wx {
    private:
        Screen* screen;

    public:
        //podstrony
        Weather_req* weather_req;

        //konstruktor
        Wx(Screen* screen);

        //destruktor
        ~Wx();

        //renderowanie
        void render() const;

        void input_handler(int button_clicked, Active_Screen& current_page) const;
};

#endif