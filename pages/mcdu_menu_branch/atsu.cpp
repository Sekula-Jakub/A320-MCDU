#include "atsu.h"
#include <screen.h>
#include <SFML/Graphics.hpp>

Atsu::Atsu(Screen* screen_ptr) {
    screen = screen_ptr;

}

Atsu::~Atsu() {

}


void Atsu::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("ATSU DATALINK", sf::Color::White);

    screen -> draw_text(0, "<ATC MENU", sf::Color::White);
    screen -> draw_text(24, "     AOC MENU>", sf::Color::White);
    screen -> draw_text(29, "  COMM MENU>", sf::Color::White);
}