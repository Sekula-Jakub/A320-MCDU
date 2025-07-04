#include "flight_plan.h"
#include <iostream>
#include "init_page.h"

//konstruktor
Flight_Plan::Flight_Plan(Screen* screen_ptr, Init_Page* init_page_ptr) {
    screen = screen_ptr;
    init_page = init_page_ptr;
}

//destruktor
Flight_Plan::~Flight_Plan() {

}

void Flight_Plan::render() {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("                               " + init_page -> getFltNumber() + "                                   <- ->", sf::Color::White);

    //LEWA STRONA
    //DEP
    screen -> draw_text(6, "FROM", sf::Color::White);
    screen -> draw_text(0, init_page -> getDep(), sf::Color::Green);

    screen -> draw_text(1, " - - - F - P L N   D I S O N T I N U I T Y - - ", sf::Color::White);

    //DEST
    screen -> draw_text(11, "DEST", sf::Color::White);
    screen -> draw_text(5, init_page -> getDest(), sf::Color::Green);

    //ŚRODEK
    //DEP TIME
    screen -> draw_text(18, "TIME", sf::Color::White);
    screen -> draw_text(12, "----", sf::Color::White);

    //DEST TIME
    screen -> draw_text(23, "TIME", sf::Color::White);
    screen -> draw_text(17, "----", sf::Color::White);

    //PRAWA STRONA
    //SPD/ALT
    screen -> draw_text(30, "SPD   /   ALT", sf::Color::White);
    screen -> draw_text(24, "---   /   ------", sf::Color::White);

    //DIST
    screen -> draw_text(35, "DIST           EFOB", sf::Color::White);
    screen -> draw_text(29, "----       ------", sf::Color::White);

}