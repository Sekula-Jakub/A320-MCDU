#include <SFML/Graphics.hpp>
#include "headers/mcdu.h"
#include <iostream>
#include <string>

//konstruktor
MCDU::MCDU() {

      //tworzenie tła
      background.setSize(sf::Vector2f(450, 600));
      background.setFillColor(sf::Color(126, 163, 191));      //Ciemnoniebieski kolor
      background.setPosition(0, 0);

      //tworzenie wyświetlacza
      screen_background.setSize(sf::Vector2f(290, 234));
      screen_background.setFillColor(sf::Color(20, 20, 20));
      screen_background.setPosition(450 / 2 - 145, 600 / 2 - 275);

      //tworzenie przycisków z lewej strony wyswietlacza
      float startX = 40, startY = 45;
      float width = 30.f, height = 20.f;        //wymiary jako float

      for (int i=0; i<6; i++) {
            func_buttons.emplace_back(startX, startY, width, height, "-", startX + width / 2 - 3, startY + height / 2 - 8);
            startY += 35;
      }

      //tworzenie przyciskow z prawej strony wyswietlacza
      startX = 370 + 10;
      startY = 45;

      for (int i=0; i<6; i++) {
            func_buttons.emplace_back(startX, startY, width, height, "-", startX + width / 2 - 3, startY + height / 2 - 8);
            startY += (35);
      }

      //tworzenie przyciskow na dole pod wyswietlaczem
      startX = 80;
      startY = 270;
      width = 40.f, height = 30.f;

      //nazwy przycisków
      std::string top_button_names[12] = {"DIR", "PROG", " PERF", "  INIT", "DATA", " ", "F-PLN", "  RAD\n  NAV", "  FUEL\n PRED", " SEC\nF-PLN", "  ATC\nCOMM", "MCDU\nMENU"};

      int counter = 0;
      for (int i=0; i<2; i++) {
            for (int j=0; j<6; j++) {
                  if (counter == 0) {
                        top_buttons.emplace_back(startX, startY, width, height, top_button_names[counter], startX + width / 2 - 10, startY + height / 2 - 8);
                  }

                  else if (counter > 0 && counter < 7) {
                        top_buttons.emplace_back(startX, startY, width, height, top_button_names[counter], startX + width / 2 - 17, startY + height / 2 - 8);
                  }

                  else {
                        top_buttons.emplace_back(startX, startY, width, height, top_button_names[counter], startX + width / 2 - 19, startY + height / 2 - 14);
                  }
                  startX += 50;
                  counter++;
            }
            startX = 80;
            startY += 35;
      }
}

void MCDU::update(sf::RenderWindow& window) {
      //update po przyciskach func_buttton
      for (int i=0; i<12; i++) {
            if (func_buttons[i].isClicked(window)) {
                  std::cout << "Kliknieto przycisk " << i <<std::endl;
            }
      }

      //update po przyciskach top_buttton
      for (int i=0; i<12; i++) {
            if (top_buttons[i].isClicked(window)) {
                  std::cout << "Kliknieto przycisk " << i + 12 <<std::endl;
            }
      }

}

void MCDU::render(sf::RenderWindow& window) {
      window.draw(background);
      window.draw(screen_background);

      //wyswietlacz
      screen.display_screen(window);

      //przyciski z prawej i lewej strony wyswietlacza
      for (int i=0; i<12; i++) {
            func_buttons[i].draw(window);
      }

      //przyciski top_buttons pod wyswietlaczem
      for (int i=0; i<12 ;i++) {
            top_buttons[i].draw(window);
      }
}