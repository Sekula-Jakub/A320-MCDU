//wx.cpp
//Implementacja klasy Wx

#include <SFML/Graphics.hpp>
#include "wx.h"

//konstruktor
Wx::Wx(Screen* screen_ptr) {
    screen = screen_ptr;

    //zaalokowanie pamieci na podstrone
    weather_req = new Weather_req(screen);
}

//destruktor
Wx::~Wx() {
    delete weather_req;
    weather_req = nullptr;
}

void Wx::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytul
    screen -> draw_title("                     AOC REQUESTS", sf::Color::White);
    //<WEATHER REQ
    screen -> draw_text(0, "<WEATHER REQ", sf::Color::White);
}

void Wx::input_handler(int button_clicked, Active_Screen& current_page) const {
      if(button_clicked == 0) {
           weather_req -> render();
           current_page = Active_Screen::weather_request_page;
      }
}
