#include "aoc_menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Aoc_menu::Aoc_menu(Screen* screen_ptr) {
    screen = screen_ptr;

    //zaalokowanie pamieci
    flt_init = new Flt_Init(screen);

    std::cout << "[DEBUG] Konstruktor AOC_MENU wywołany" << std::endl;

}

Aoc_menu::~Aoc_menu() {
    delete flt_init;
}


void Aoc_menu::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("AOC MENU", sf::Color::White);

    //LEWA STRONA EKRANU
    screen -> draw_text(0, "<FLT INIT", sf::Color::White);
    screen -> draw_text(1, "<ATC REQ", sf::Color::White);
    screen -> draw_text(3, "<ADC DELAY", sf::Color::White);
    screen -> draw_text(4, "<ARR MSG", sf::Color::White);

    //PRAWA STRONA EKRANU
    screen -> draw_text(24, "                 WX>", sf::Color::White);
    screen -> draw_text(25, "               ATIS>", sf::Color::White);
    screen -> draw_text(26, "     DIVERSION>", sf::Color::White);
    screen -> draw_text(27, "    FREE TEXT>", sf::Color::White);
    screen -> draw_text(28, "  RCVD MSGS>", sf::Color::White);

}

void Aoc_menu::input_handler(int button_clicked, Active_Screen &current_page) {

    if (button_clicked == 0) {
        flt_init -> render();
        std::cout << "Flt Init" <<std::endl;
        current_page = Active_Screen::flt_init_page;
    }
}
