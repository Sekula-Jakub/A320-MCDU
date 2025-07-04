#include "atsu.h"
#include <screen.h>
#include <SFML/Graphics.hpp>
#include <iostream>

//konstruktor
Atsu::Atsu(Screen* screen_ptr) {
    screen = screen_ptr;

    //zaalokowanie pamieci
    aoc_menu = new Aoc_menu(screen);
    std::cout << "[DEBUG] Konstruktor ATSU wywołany" << std::endl;

}

//destruktor
Atsu::~Atsu() {
    delete aoc_menu;
}

void Atsu::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("                      ATSU DATALINK", sf::Color::White);

    screen -> draw_text(0, "<ATC MENU", sf::Color::White);
    screen -> draw_text(24, "     AOC MENU>", sf::Color::White);
    screen -> draw_text(29, "  COMM MENU>", sf::Color::White);
}

void Atsu::input_handler(int button_clicked, Active_Screen &current_page) {

    if (button_clicked == 6) {
        aoc_menu -> render();
        std::cout << "Aoc_menu" <<std::endl;
        current_page = Active_Screen::aoc_menu_page;
    }

}