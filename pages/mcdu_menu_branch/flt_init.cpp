#include "flt_init.h"
#include <SFML/Graphics.hpp>

Flt_Init::Flt_Init(Screen* screen_ptr) {
    screen = screen_ptr;
}

Flt_Init::~Flt_Init() {

}

void Flt_Init::render() {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("AOC FLT INIT", sf::Color::White);

    //LEWA STRONA EKRANU
    screen -> draw_text(6, "FLT NO", sf::Color::White);
    screen -> draw_text(0, "[ ][ ][ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    screen -> draw_text(7, "DEP", sf::Color::White);
    screen -> draw_text(1, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    screen -> draw_text(8, "DEST", sf::Color::White);
    screen -> draw_text(2, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    screen -> draw_text(9, "ALT", sf::Color::White);
    screen -> draw_text(3, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    screen -> draw_text(10, "ETE", sf::Color::White);
    screen -> draw_text(4, "[ ][ ][ ][  ]", sf::Color{255, 153, 0}); //orange color

    //PRAWA STRONA EKRANU
    screen -> draw_text(30, "                      UTC", sf::Color::White);
    screen -> draw_text(24, getTimeUTC(), sf::Color::Green);
    screen -> draw_text(32, "                     DATE", sf::Color::White);
    screen -> draw_text(26, getDateUTC(), sf::Color::Green);
}

std::string Flt_Init :: getDateUTC() {
    std::time_t t = std::time(nullptr);
    std::tm* utc = std::gmtime(&t);

    char date[11]; //10 + '\n'

    //sprintf zapisuje dane do bufora (chara)
    std::sprintf(date, "      %02d/%02d/%04d", utc->tm_mday, utc->tm_mon + 1, utc->tm_year + 1900);

    std::string dateUTC = date;

    return dateUTC;
}

std::string Flt_Init :: getTimeUTC() {
    std::time_t t = std::time(nullptr);
    std::tm* utc = std::gmtime(&t);

    char time[5]; //4 + '\n'

    //sprintf zapisuje dane do bufora (chara)
    std::sprintf(time, "                %02d%02d", utc->tm_hour, utc->tm_min);

    std::string timeUTC = time;

    return timeUTC;
}
