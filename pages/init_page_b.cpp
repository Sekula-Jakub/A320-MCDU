#include "init_page_b.h"
#include "init_page.h"
#include "input.h"
#include <iostream>

//konstruktor
Init_Page_B::Init_Page_B(Screen *screen_ptr, Init_Page* init_page_ptr) {
    screen = screen_ptr;
    init_page = init_page_ptr;
}

//destruktor
Init_Page_B::~Init_Page_B() {

}

void Init_Page_B::render() {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("      INIT                   <- ->", sf::Color::White);

    //LEWA STRONA
    //TAXI
    taxi = "0.2";   //domyslna wartość
    screen -> draw_text(6, "TAXI", sf::Color::White);
    screen -> draw_text(0, taxi, sf::Color(0, 255, 255)); //blue color

    //TRIP/TIME
    screen -> draw_text(7, "TRIP/TIME", sf::Color::White);
    screen -> draw_text(1, "---.-/----", sf::Color::White);

    //RTE RSV/%
    screen -> draw_text(8, "RTE RSV/%", sf::Color::White);
    screen -> draw_text(2, "---.-/5.0", sf::Color::White);

    //ALTN/TIME
    screen -> draw_text(9, "ALTN/TIME", sf::Color::White);
    screen -> draw_text(3, "---.-/----", sf::Color::White);

    //FINAL TIME
    screen -> draw_text(10, "FINAL TIME", sf::Color::White);
    screen -> draw_text(4, "1.0/0030", sf::Color(0, 255, 255)); //blue color

    //MIN DEST FOB
    screen -> draw_text(11, "MIN DEST FOB", sf::Color::White);
    screen -> draw_text(5, "1.0", sf::Color(0, 255, 255)); //blue color


    //PRAWA STRONA
    //ZFW/ZWFCG
    screen -> draw_text(30, "       ZFW / ZFWCG", sf::Color::White);
    if (zfw_zfwcg.empty()) {
        screen -> draw_text(24, "   [ ][ ].[ ]/[ ][ ].[ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(24, zfw_zfwcg, sf::Color(0, 255, 255)); //blue color
    }

    //BLOCK
    screen -> draw_text(31, "                   BLOCK", sf::Color::White);
    if (block_fuel.empty()) {
        screen -> draw_text(25, "               [ ][ ].[ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(25, block_fuel, sf::Color(0, 255, 255)); //blue color
    }

    //TOW/LW
    screen -> draw_text(33, "          TOW  /     LW", sf::Color::White);
    if (tow.empty()) {
        screen -> draw_text(15, "                       --.-/ ", sf::Color::White);
    }
    else {
        screen -> draw_text(16, tow, sf::Color(0, 255, 255)); //blue color
    }
    screen -> draw_text(27, "                --.-", sf::Color::White);

    //TRIP WIND
    screen -> draw_text(34, "             TRIP WIND", sf::Color::White);
    screen -> draw_text(28, "             ------", sf::Color::White);

    //EXTRA TIME
    screen -> draw_text(35, "        EXTRA / TIME", sf::Color::White);
    screen -> draw_text(29, "      ---.- / ----", sf::Color::White);
}

void Init_Page_B::input_handler(int button_clicked, Active_Screen& current_page) {
    if (button_clicked == 26) {
        init_page -> render();
        std::cout << "Init_Page_B" <<std::endl;
        current_page = Active_Screen::init_page;
    }
}
