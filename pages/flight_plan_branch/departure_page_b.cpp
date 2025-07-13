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
      available_runways = db.get_runway_data_from_data_base(departure);

      //wyczyszczenie poprzednich wartosci
      screen -> draw_title("", sf::Color::White);

      //wyczyszczenie napisow
      for (int i=0; i<37; i++) {
            screen -> draw_text(i,"", sf::Color::White);
      }

      //tytul
      if (chosen == false) {
            screen -> draw_title("        D E P A R T U R E   F R O M   " + departure +"     <- ->", sf::Color::White);
      }
      else {
            screen -> draw_title("        D E P A R T U R E   F R O M   " + departure +"     <- ->", sf::Color::Yellow);
      }

      //RWY
      screen -> draw_text(6, "RWY", sf::Color::White);
      if (chosen == false) {
            screen -> draw_text(0, "- - -", sf::Color::White);
      }
      else {
            screen -> draw_text(0, rwy, sf::Color::Yellow);
      }

      //SID
      screen -> draw_text(18, "     SID", sf::Color::White);
      if (chosen == false) {
            screen -> draw_text(12, "- - - - -", sf::Color::White);
      }
      else {
            screen -> draw_text(12, "  " + sid, sf::Color::Yellow);
      }

      //TRANS
      screen -> draw_text(30, "             TRANS", sf::Color::White);
      if (chosen == false) {
            screen -> draw_text(24, "       - - - - - -", sf::Color::White);
      }
      else {
            screen -> draw_text(24, "         " + trans, sf::Color::Yellow);
      }

      screen -> draw_text(7, "              A V A I L A B L E    R U N W A Y S", sf::Color::White);

      //RUNWAYS AVAILABLE
      if (chosen == false) {
            for (int i=0; i<available_runways.size(); i++) {
                  screen -> draw_text(i + 1, "<" + available_runways[i].number + "           " + available_runways[i].length + 'm', sf::Color(0, 255, 255));     //blue color
            }
      }

      //RETURN
      if (chosen == false) {
            screen -> draw_text(5, "<RETURN", sf::Color::White);
      }
      else {
            //TMPY F-PLN
            screen -> draw_text(11, "    TMPY", sf::Color::Yellow);
            screen -> draw_text(5, "<F-PLN", sf::Color::Yellow);

            //TMPY INSERT
            screen -> draw_text(35, "                     TMPY", sf::Color{255, 153, 0}); //orange color
            screen -> draw_text(29, "           INSERT*", sf::Color{255, 153, 0}); //orange color
      }

}

void Departure_Page_B::input_handler(int button_clicked, Active_Screen &current_page){
      if (button_clicked == 5 && chosen == false) {
            departure_page_a -> render();
            current_page = Active_Screen::departure_page_a_page;
      }
      //czy przycisk klikniety jest na jakims z dostepnych pasow startowych
      if (button_clicked >= 1 && button_clicked <= available_runways.size() && chosen == false) {
            chosen = true;
            chosen_runway = button_clicked - 1;
            rwy = available_runways[button_clicked - 1].number;
            sid = "NONE";
            trans = "NONE";
            this -> render();
      }
      if (button_clicked == 11 && chosen == true) {
            chosen = false;

            departure_page_a -> flight_plan -> dep_runway = available_runways[chosen_runway].number;

            departure_page_a -> flight_plan -> render_ready();
            current_page = Active_Screen::flight_plan_page;
      }
}