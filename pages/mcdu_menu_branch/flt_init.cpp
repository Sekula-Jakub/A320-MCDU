#include "flt_init.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Flt_Init::Flt_Init(Screen* screen_ptr) {
    screen = screen_ptr;
}

Flt_Init::~Flt_Init() {

}

void Flt_Init::render() {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("AOC FLT INIT", sf::Color::White);

    //LEWA STRONA EKRANU

    //FLT NO
    screen -> draw_text(6, "FLT NO", sf::Color::White);
    if(flt_no.empty()) {
        screen -> draw_text(0, "[ ][ ][ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(0, flt_no, sf::Color::White);
    }

    //DEP
    screen -> draw_text(7, "DEP", sf::Color::White);
    if(dep.empty()) {
        screen -> draw_text(1, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(1, dep, sf::Color::White);
    }

    //DEST
    screen -> draw_text(8, "DEST", sf::Color::White);
    if(dest.empty()) {
        screen -> draw_text(2, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(2, dest, sf::Color::White);
    }

    //ALT
    screen -> draw_text(9, "ALTN", sf::Color::White);
    if(altn.empty()) {
        screen -> draw_text(3, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(3, altn, sf::Color::White);
    }

    //ETE
    screen -> draw_text(10, "ETE", sf::Color::White);
    if(ete.empty()) {
        screen -> draw_text(4, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(4, altn, sf::Color::White);
    }

    //PRAWA STRONA EKRANU
    screen -> draw_text(30, "                      UTC", sf::Color::White);
    screen -> draw_text(24, getTimeUTC(), sf::Color::Green);
    screen -> draw_text(32, "                     DATE", sf::Color::White);
    screen -> draw_text(26, getDateUTC(), sf::Color::Green);

    //input uzytkownika
    screen -> draw_text(36, vector_to_string(flt_init_input), sf::Color::White);
}

std::string Flt_Init :: getDateUTC() {
    std::time_t t = std::time(nullptr);
    std::tm* utc = std::gmtime(&t);

    char date[11]; //10 + '\0'

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

void Flt_Init::getInput(int &button_clicked) {
    get_input(button_clicked, flt_init_input);
    std::cout << "flt_init_input.size() = \n" << flt_init_input.size() << std::endl;
    std::cout << vector_to_string(flt_init_input) << std::endl;
}

