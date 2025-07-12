#include "mcdu_menu.h"
#include <iostream>

//konstruktor
Mcdu_Menu::Mcdu_Menu(Screen* screen_ptr) {
    screen = screen_ptr;

    //Zaalokowanie pamieci na podstrony
    atsu = new Atsu(screen); //Przekazanie wskaznika na ekran
    fmgc = new Fmgc(screen);
}

//destruktor
Mcdu_Menu::~Mcdu_Menu() {
    delete atsu;
    delete fmgc;
}

void Mcdu_Menu::render() {

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("                        MCDU MENU", sf::Color::White);
    //tresc strony
    screen -> draw_text(0, "<FMGC", sf::Color::Green);
    screen -> draw_text(1, "<ATSU", sf::Color::White);
    screen -> draw_text(24, "          CONFIG>", sf::Color::White);
    screen -> draw_text(25, "            MAINT>", sf::Color::White);
    screen -> draw_text(29, "          RETURN>", sf::Color::White);
}

void Mcdu_Menu::input_handler(int button_clicked, Active_Screen& current_page) const {

    if (button_clicked == 1) {
        atsu -> render();
        std::cout << "Atsu" <<std::endl;
        current_page = Active_Screen::atsu_menu_page;
    }

    else if (button_clicked == 0) {
        fmgc -> render();
        std::cout << "Fmgc"<<std::endl;
        current_page = Active_Screen::fmgc_page;
    }
}
