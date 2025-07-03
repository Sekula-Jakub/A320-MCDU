#include "init_page.h"

//konstruktor
Init_Page::Init_Page(Screen* screen_ptr) {
    screen = screen_ptr;
}

Init_Page::~Init_Page() {

}

void Init_Page::render() {

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("      INIT", sf::Color::White);

    //LEWA STRONA
    screen -> draw_text(6, "CO RTE", sf::Color::White);
    screen -> draw_text(0, "[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color;
    screen -> draw_text(7, "ALTN/CO RTE", sf::Color::White);
    screen -> draw_text(1, "----/----------", sf::Color::White);
    screen -> draw_text(8, "FLT NBR", sf::Color::White);
    screen -> draw_text(2, "[ ][ ][ ][ ][ ][ ][ ][ ]", sf::Color{255, 153, 0});
    screen -> draw_text(10, "COST INDEX", sf::Color::White);
    screen -> draw_text(4, "---", sf::Color::White);
    screen -> draw_text(11, "CRZ FL/TEMP", sf::Color::White);
    screen -> draw_text(5, "------ /---", sf::Color::White);

    //PRAWA STRONA
    screen -> draw_text(30, "FROM/TO", sf::Color::White);
    screen -> draw_text(24, "[ ][ ][ ][ ]/[ ][ ][ ][ ]", sf::Color{255, 153, 0});
    screen -> draw_text(31, "                       INIT", sf::Color{255, 153, 0});
    screen -> draw_text(25, "       REQUEST*", sf::Color{255, 153, 0});
    screen -> draw_text(26, "          IRS INIT>", sf::Color::White);
    screen -> draw_text(27, "              WIND>", sf::Color::White);
    screen -> draw_text(34, "                     TROPO", sf::Color::White);
    screen -> draw_text(28, "             36090", sf::Color(0, 255, 255));
    screen -> draw_text(35, "               GND TEMP", sf::Color::White);
    screen -> draw_text(29, "                   ---", sf::Color::White);
}

