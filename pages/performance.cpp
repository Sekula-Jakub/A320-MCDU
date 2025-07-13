#include "performance.h"
#include <iostream>
#include "input.h"

//konstruktor
Performance::Performance(Screen* screen_ptr, Flight_Plan* flight_plan_ptr) {
    screen = screen_ptr;
    flight_plan = flight_plan_ptr;
}

//domyslny destruktor
Performance::~Performance() = default;

void Performance::render() {

    //pobranie numeru pasa strtowego z flight_plan
    rwy = flight_plan -> dep_runway;

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("                  TAKE  OFF  RWY  " + rwy, sf::Color::White );

    //LEWA STRONA
    //V1
    screen -> draw_text(6,"V1", sf::Color::White);
    if (V1.empty()) {
        screen -> draw_text(0,"[ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }

    //VR
    screen -> draw_text(7,"VR", sf::Color::White);
    if (VR.empty()) {
        screen -> draw_text(1,"[ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }

    //V2
    screen -> draw_text(8,"V2", sf::Color::White);
    if (V2.empty()) {
        screen -> draw_text(2,"[ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }

    //TRANS ALT
    screen -> draw_text(9,"TRANS  ALT", sf::Color::White);
    if (trans_alt.empty()) {
        screen -> draw_text(3,"[        ]", sf::Color(0, 255, 255)); //blue color;
    }

    //THR RED/ACC
    screen -> draw_text(10,"THR  RED / ACC", sf::Color::White);
    screen -> draw_text(4,"1341 / 1341", sf::Color(0, 255, 255)); //blue color;

    //ŚRODEK
    //FLP RETR
    screen -> draw_text(18,"FLP  RETR", sf::Color::White);
    screen -> draw_text(12,"F = 147", sf::Color::Green);

    //SLT RETR
    screen -> draw_text(19,"SLT  RETR", sf::Color::White);
    screen -> draw_text(13,"S = 191", sf::Color::Green);

    //CLEAN
    screen -> draw_text(20,"CLEAN", sf::Color::White);
    screen -> draw_text(14,"O = 216", sf::Color::Green);

    //PRAWA STRONA
    //TO SHIFT
    screen -> draw_text(31,"            TO  SHIFT", sf::Color::White);
    screen -> draw_text(25,"          [       ]*", sf::Color(0, 255, 255)); //blue color;

    //FLAPS/THS
    screen -> draw_text(32,"          FLAPS / THS", sf::Color::White);
    screen -> draw_text(26,"    [   ] / [        ]", sf::Color(0, 255, 255)); //blue color;

    //FLEX TO TEMP
    screen -> draw_text(33,"        FLEX TO TEMP", sf::Color::White);
    screen -> draw_text(27,"          [       ]", sf::Color(0, 255, 255)); //blue color;

    //ENG OUT ACC
    screen -> draw_text(34,"        ENG OUT ACC", sf::Color::White);
    screen -> draw_text(28,"              1341", sf::Color(0, 255, 255)); //blue color;

}