#include <SFML/Graphics.hpp>
#include "weather_req.h"
#include <iostream>
#include "../../headers/data_base_manager.h"
#include "../input.h"

//konstruktor
Weather_req::Weather_req(Screen* screen_ptr) {
    screen = screen_ptr;
}

//destruktor
Weather_req::~Weather_req() {
    return;
}

void Weather_req::render() const {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<36; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytul
    screen -> draw_title("AOC WEATHER REQ", sf::Color::White);
    //<WEATHER REQ
    screen -> draw_text(6, "IDENT", sf::Color::White);
    if(ident.empty()) {
        screen -> draw_text(0, "[ ][ ][ ][ ]", sf::Color{255, 153, 0});
    }
    else {
        screen -> draw_text(0, ident, sf::Color(0, 255, 255));
    }


    char metar_no_yes = 'N';
    char tar_no_yes = 'N';

    if(metar == false) {
        screen -> draw_text(1, "* METAR <N>", sf::Color(0, 255, 255));
    }
    else {
        screen -> draw_text(1, "* METAR <Y>", sf::Color(0, 255, 255));
    }

    if(tar == false) {
        screen -> draw_text(2, "* TAR <N>", sf::Color(0, 255, 255));
    }
    else {
        screen -> draw_text(2, "* TAR <Y>", sf::Color(0, 255, 255));
    }

    //SEND button
    screen -> draw_text(29, "              SEND *", sf::Color(0, 255, 255));

    //input uzytkownika
    screen -> draw_text(36, vector_to_string(weather_req_input), sf::Color::White);
}

void Weather_req::input_handler(int button_clicked, Active_Screen& current_page) {
      if(button_clicked == 1) {
            if(metar == false) {
                metar = true;
            }
            else {
                metar = false;
            }
      }

      else if(button_clicked == 2) {
          if(tar == false) {
              tar = true;
          }
          else {
              tar = false;
          }
      }
    else if (button_clicked == 11) {
        send_data();
    }
}

void Weather_req::getInput(int &button_clicked) {
    get_input(button_clicked, weather_req_input);
    std::cout << "weather_req_input.size() = \n" << weather_req_input.size() << std::endl;
}

void Weather_req::insert_data(int &button_clicked) {
  if(button_clicked == 0) {
      std::string code = vector_to_string(weather_req_input);

      std::cout<<"code: " << code << std::endl;

      if (db.airport_in_data_base(code) == true) {
          ident = code;
      }
      else {
          weather_req_input = {'N', 'O', 'T', ' ', 'I', 'N', ' ', 'D', 'A', 'T', 'A', ' ', 'B', 'A', 'S', 'E', '!'};
          return;
      }

      //wyczyszcenie inputu wektora
      weather_req_input.clear();
  }
}

void Weather_req::send_data() {
    if (!ident.empty()) {
        ident.clear();
        metar = false;
        tar = false;
        weather_req_input.clear();
        std::cout<<"ident sent"<<std::endl;
    }
}