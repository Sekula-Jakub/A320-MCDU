#include "fmgc.h"
#include <screen.h>
#include <SFML/Graphics.hpp>

Fmgc::Fmgc(Screen* screen_ptr) {
    screen = screen_ptr;

}

Fmgc::~Fmgc() {

}


void Fmgc::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("A320 - 200", sf::Color::White);

    screen -> draw_text(6, "ENG", sf::Color::White);
    screen -> draw_text(0, "V2527-A5", sf::Color::Green);

    screen -> draw_text(7, "    ACTIVE NAV DATA BASE", sf::Color::White);
    screen -> draw_text(1, "    15MAY25 - 12JUN25", sf::Color::Cyan);

    screen -> draw_text(8, "    SECOND NAV DATA BASE", sf::Color::White);
    screen -> draw_text(2, "   <- 15MAY25 - 12JUN25", sf::Color::Cyan);
}
