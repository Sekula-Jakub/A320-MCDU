#include "departure_page_a.h"

#include "../init_page.h"
#include "../../headers/data_base_manager.h"

//konstruktor
Departure_Page_A::Departure_Page_A(Screen* screen_ptr) {
    screen = screen_ptr;
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

    screen -> draw_title("      LAT REV FROM " + init_page -> getDep(), sf::Color::White);
}