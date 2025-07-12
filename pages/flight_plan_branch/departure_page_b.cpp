#include "departure_page_b.h"
#include "departure_page_a.h"
#include "../data_base_manager.h"

//konstruktor
Departure_Page_B::Departure_Page_B(Screen* screen_ptr, Departure_Page_A* departure_page_a_ptr) {
      screen = screen_ptr;
      departure_page_a = departure_page_a_ptr;
}

//destruktor
Departure_Page_B::~Departure_Page_B() = default;

void Departure_Page_B::render() {

      //przypisanie wartosci do departure
      departure = departure_page_a -> flight_plan -> departure;

      //znalezienie pasow startowych w bazie danych
      runways = db.get_runway_numbers_from_data_base(departure);

      //wyczyszczenie poprzednich wartosci
      screen -> draw_title("", sf::Color::White);

      //wyczyszczenie napisow
      for (int i=0; i<37; i++) {
            screen -> draw_text(i,"", sf::Color::White);
      }

      //tytul
      screen -> draw_title("        D E P A R T U R E   F R O M   " + departure +"     <- ->", sf::Color::White);

      //RWY
      screen -> draw_text(6, "RWY", sf::Color::White);
      screen -> draw_text(0, "- - -", sf::Color::White);

      //SID
      screen -> draw_text(18, "     SID", sf::Color::White);
      screen -> draw_text(12, "- - - - -", sf::Color::White);

      //TRANS
      screen -> draw_text(30, "             TRANS", sf::Color::White);
      screen -> draw_text(24, "       - - - - - -", sf::Color::White);

      screen -> draw_text(7, "              A V A I L A B L E    R U N W A Y S", sf::Color::White);

      //RUNWAYS AVAILABLE
      for (int i=0; i<runways.size(); i++) {
            screen -> draw_text(i+1, "<-" + runways[i], sf::Color(0, 255, 255));     //blue color
      }

      //RETURN
      screen -> draw_text(5, "<RETURN", sf::Color::White);
}

void Departure_Page_B::input_handler(int button_clicked, Active_Screen &current_page) {
      if (button_clicked == 5) {
            departure_page_a -> render();
            current_page = Active_Screen::departure_page_a_page;
      }
}