#include "arrival_page_b.h"
#include "arrival_page_a.h"
#include "../data_base_manager.h"

//konstruktor
Arrival_Page_B::Arrival_Page_B(Screen* screen_ptr, Arrival_Page_A* arrival_page_a_ptr) {
      screen = screen_ptr;
      arrival_page_a = arrival_page_a_ptr;
}

//destruktor
Arrival_Page_B::~Arrival_Page_B() = default;

void Arrival_Page_B::render() {

      //przypisanie wartosci do arrival
      arrival = arrival_page_a -> flight_plan -> arrival;

      //znalezienie pasow startowych w bazie danych
      available_runways = db.get_runway_data_from_data_base(arrival);

      //wyczyszczenie poprzednich wartosci
      screen -> draw_title("", sf::Color::White);

      //wyczyszczenie napisow
      for (int i=0; i<37; i++) {
            screen -> draw_text(i,"", sf::Color::White);
      }

      //tytul
      if (chosen == false) {
            screen -> draw_title("        A R R I V A L   T O  " + arrival +"     <- ->", sf::Color::White);
      }
      else {
            screen -> draw_title("        A R R I V A L   T O  " + arrival +"     <- ->", sf::Color::Yellow);
      }

      //APPR
      screen -> draw_text(6, "APPR", sf::Color::White);
      if (chosen == false) {
            screen -> draw_text(0, "- - - - -", sf::Color::White);
      }
      else {
            screen -> draw_text(0, appr, sf::Color::Yellow);
      }

      //VIA
      screen -> draw_text(18, "     VIA", sf::Color::White);
      if (chosen == false) {
            screen -> draw_text(12, "- - - - -", sf::Color::White);
      }
      else {
            screen -> draw_text(12, "  " + via, sf::Color::Yellow);
      }

      //STAR
      screen -> draw_text(30, "             STAR", sf::Color::White);
      if (chosen == false) {
            screen -> draw_text(24, "       - - - - -", sf::Color::White);
      }
      else {
            screen -> draw_text(24, "         " + star, sf::Color::Yellow);
      }

      //TRANS
      screen -> draw_text(31, "           TRANS", sf::Color::White);
      if (chosen == false) {
            screen -> draw_text(25, "       - - - - -", sf::Color::White);
      }
      else {
            screen -> draw_text(25, "         " + trans, sf::Color::Yellow);
      }

      screen -> draw_text(7, "A P P R        A V A I L A B L E", sf::Color::White);

      //APPR AVAILABLE
      if (chosen == false) {
            for (int i=0; i<available_runways.size(); i++) {
                  if (i + 1 <= 4) {
                        screen -> draw_text(i + 1, "<" + available_runways[i].number + "           " + available_runways[i].length + 'm', sf::Color(0, 255, 255));     //blue color
                  }
            }
      }

      //RETURN
      screen -> draw_text(5, "<RETURN", sf::Color::White);

      if(chosen == true) {
            //TMPY F-PLN
            screen -> draw_text(11, "    TMPY", sf::Color::Yellow);
            screen -> draw_text(5, "<F-PLN", sf::Color::Yellow);

            //TMPY INSERT
            screen -> draw_text(35, "                     TMPY", sf::Color{255, 153, 0}); //orange color
            screen -> draw_text(29, "           INSERT*", sf::Color{255, 153, 0}); //orange color
      }
}

void Arrival_Page_B::input_handler(int button_clicked, Active_Screen &current_page){
      if (button_clicked == 5 && chosen == false) {
            arrival_page_a -> render();
            current_page = Active_Screen::arrival_page_a_page;
      }
      //czy przycisk klikniety jest na jakims z dostepnych pasow startowych
      if (button_clicked >= 1 && button_clicked <= available_runways.size() && chosen == false) {
            chosen = true;
            chosen_runway = button_clicked - 1;
            appr = available_runways[chosen_runway].number;
            via = "NONE";
            star = "NONE";
            trans = "NONE";
            this -> render();
      }
      if (button_clicked == 11 && chosen == true) {
            chosen = false;

            arrival_page_a -> flight_plan -> arr_runway = available_runways[chosen_runway].number;

            arrival_page_a -> flight_plan -> render_ready();
            current_page = Active_Screen::flight_plan_page;
      }
}