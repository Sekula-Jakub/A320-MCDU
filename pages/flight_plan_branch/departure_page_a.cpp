//departure_page_a.cpp
//Implementacja klasy Departure_Page_A

#include "departure_page_a.h"
#include "../flight_plan.h"
#include "departure_page_b.h"

//konstruktor
Departure_Page_A::Departure_Page_A(Screen* screen_ptr, Flight_Plan* flight_plan_ptr) {
    screen = screen_ptr;
    flight_plan = flight_plan_ptr;

    //zaalokowanie pamiecie na podstrone
    departure_page_b = new Departure_Page_B(screen, this);
}

//domyślny destruktor
Departure_Page_A::~Departure_Page_A() {
    delete departure_page_b;
}

void Departure_Page_A::render() {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("                    LAT REV FROM " + flight_plan -> departure, sf::Color::White);

    coordinates = flight_plan -> coordinates_dep;
    screen -> draw_text(6, "                               " + coordinates, sf::Color::Green);

    //LEWA STRONA
    //DEPARTURE
    screen -> draw_text(0, "<DEPARTURE", sf::Color::White);

    //OFFSET
    screen -> draw_text(1, "<OFFSET", sf::Color::White);

    //ENABLE ALTN
    screen -> draw_text(9, "ENABLE", sf::Color(0, 255, 255));   //blue color
    screen -> draw_text(3, "<- ALTN", sf::Color(0, 255, 255));     //blue color

    //RETURN
    screen -> draw_text(5, "<RETURN", sf::Color::White);

    //PRAWA STRONA
    screen -> draw_text(24, "         FIX INFO>", sf::Color::White);
    screen -> draw_text(31, "   LL XING/INCR/NO", sf::Color::White);
    screen -> draw_text(25, " [     ] / [   ] / [   ]", sf::Color(0, 255, 255));     //blue color
    screen -> draw_text(32, "              NEXT WPT", sf::Color::White);
    screen -> draw_text(26, "              [        ]", sf::Color(0, 255, 255));     //blue color
    screen -> draw_text(33, "              NEW DEST", sf::Color::White);
    screen -> draw_text(27, "              [        ]", sf::Color(0, 255, 255));     //blue color
}

void Departure_Page_A::input_handler(int button_clicked, Active_Screen &current_page) const {
    //Return przycisk
    if (button_clicked == 5) {
        flight_plan -> render_ready();
        current_page = Active_Screen::flight_plan_page;
    }
    //Departure przycisk
    else if (button_clicked == 0) {
        departure_page_b -> render();
        current_page = Active_Screen::departure_page_b_page;
    }
}
