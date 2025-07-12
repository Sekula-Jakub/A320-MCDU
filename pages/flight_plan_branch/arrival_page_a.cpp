#include "arrival_page_a.h"
#include "../flight_plan.h"

//konstruktor
Arrival_Page_A::Arrival_Page_A(Screen* screen_ptr, Flight_Plan* flight_plan_ptr) {
    screen = screen_ptr;
    flight_plan = flight_plan_ptr;
}

//destruktor
Arrival_Page_A::~Arrival_Page_A() = default;

void Arrival_Page_A::render() {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("                    LAT REV FROM " + flight_plan -> arrival, sf::Color::White);

    coordinates = flight_plan -> coordinates_arr;
    screen -> draw_text(6, "                               " + coordinates, sf::Color::Green);

    //LEWA STRONA
    //OFFSET
    screen -> draw_text(1, "<OFFSET", sf::Color::White);

    //ALTN
    screen -> draw_text(2, "<ALTN", sf::Color::White);

    //ENABLE ALTN
    screen -> draw_text(9, "ENABLE", sf::Color(0, 255, 255));   //blue color
    screen -> draw_text(3, "<- ALTN", sf::Color(0, 255, 255));     //blue color

    //RETURN
    screen -> draw_text(5, "<RETURN", sf::Color::White);

    //PRAWA STRONA
    screen -> draw_text(24, "          ARRIVAL>", sf::Color::White);

    //NEXT WPT
    screen -> draw_text(32, "              NEXT WPT", sf::Color::White);
    screen -> draw_text(26, "              [        ]", sf::Color(0, 255, 255));     //blue color
}

void Arrival_Page_A::input_handler(int button_clicked, Active_Screen &current_page) const {
    if (button_clicked == 5) {
        flight_plan -> render_ready();
        current_page = Active_Screen::flight_plan_page;
    }
}
