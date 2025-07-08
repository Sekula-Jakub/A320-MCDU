#include "departure_page_a.h"

#include "../flight_plan.h"
#include "../init_page.h"
#include "../../headers/data_base_manager.h"

//konstruktor
Departure_Page_A::Departure_Page_A(Screen* screen_ptr, Flight_Plan* flight_plan_ptr) {
    screen = screen_ptr;
    flight_plan = flight_plan_ptr;
}

//destruktor
Departure_Page_A::~Departure_Page_A() {

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