//data_pahe.cpp
//Implementacja klasy Data_Page

#include "data_page.h"

//konstruktor
Data_Page::Data_Page(Screen* screen_ptr) {
    screen = screen_ptr;
}

//konstruktor kopiujacy
Data_Page::Data_Page(const Data_Page &other) {
    screen = other.screen;  // prosta kopia wskaźnika
}

//domyślny destruktor
Data_Page::~Data_Page() = default;

void Data_Page::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("                          A320 - 200", sf::Color::White);

    screen -> draw_text(6, "ENG", sf::Color::White);
    screen -> draw_text(0, "V2527-A5", sf::Color::Green);

    screen -> draw_text(7, "    ACTIVE NAV DATA BASE", sf::Color::White);
    screen -> draw_text(1, "    15MAY25 - 12JUN25", sf::Color::Cyan);

    screen -> draw_text(8, "    SECOND NAV DATA BASE", sf::Color::White);
    screen -> draw_text(2, "   <- 15MAY25 - 12JUN25", sf::Color::Cyan);
}
