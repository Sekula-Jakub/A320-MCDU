#include <SFML/Graphics.hpp>
#include "pages_headers/mcdu_menu.h"

#include <screen.h>

Mcdu_Menu::Mcdu_Menu(Screen* screen_ptr) {
    screen = screen_ptr;
}

void Mcdu_Menu::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("MCDU MENU", sf::Color::White);
    //tresc strony
    screen -> draw_text(0, "<FMGC", sf::Color::Green);
    screen -> draw_text(1, "<ATSU", sf::Color::White);
    screen -> draw_text(2, "<ACMS", sf::Color::White);
    screen -> draw_text(4, "<SAT", sf::Color::White);
    screen -> draw_text(29, "    RETURN>", sf::Color::White);
}
