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
      startX = 77;
      startY = 265;
      width = 46.f, height = 28.f;

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
            startX = 77;
            startY += 32;
      }

      //dodanie zdjecia strzalki
      if (!arrow_tekstura.loadFromFile("assets/arrow_4.png")) {
            printf("Error loading arrow_icon.png\n");
            exit(1);
      }

      //przyciski ze strzałkami
      startX = 77;
      startY = 330;
      for (int i=0; i<3; i++) {
            for (int j=0; j<2; j++) {

                  if (counter == 12) {
                        top_buttons.emplace_back(startX, startY, width, height, "  AIR\nPORT", startX + width / 2 - 16, startY + height / 2 - 13);
                  }

                  else if (counter == 13) {
                        top_buttons.emplace_back(startX, startY, width, height, "", startX + width / 2 - 16, startY + height / 2 - 13);
                  }

                  else if (counter == 14) {
                        top_buttons.emplace_back(startX, startY, width, height, "", startX + width / 2 - 3, startY + height / 2 - 8 );
                        sf::Sprite arrow_left(arrow_tekstura);
                        arrow_left.setPosition(startX + 10, startY + 26);
                        arrow_left.setRotation(270);
                        arrows.emplace_back(arrow_left);
                  }

                  else if (counter == 15) {
                        top_buttons.emplace_back(startX, startY, width, height, "", startX + width / 2 - 3, startY + height / 2 - 8);
                        sf::Sprite arrow_top(arrow_tekstura);
                        arrow_top.setPosition(startX + 10, startY + 2);
                        arrows.emplace_back(arrow_top);
                  }

                  else if (counter == 16) {
                        top_buttons.emplace_back(startX, startY, width, height, "", startX + width / 2 - 3, startY + height / 2 - 8);
                        sf::Sprite arrow_right(arrow_tekstura);
                        arrow_right.setPosition(startX + 34, startY + 2);
                        arrow_right.setRotation(90);
                        arrows.emplace_back(arrow_right);
                  }

                  else {
                        top_buttons.emplace_back(startX, startY, width, height, "", startX + width / 2 - 3, startY + height / 2 - 8);
                        sf::Sprite arrow_down(arrow_tekstura);
                        arrow_down.setPosition(startX + 34, startY + 26);
                        arrow_down.setRotation(180);
                        arrows.emplace_back(arrow_down);
                  }
                  startX += 50;
                  counter++;
            }
            startX = 77;
            startY += 32;
      }

      //dodanie przycisków z literami alphabet_buttons
      counter = 0;
      startX = 190;
      startY = 340;
      width = 30.f;
      height = 30.f;
      std::string alphabet_button_names[30] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " /", "    SP", "OVFY", "  CLR"};

      for (int i=0; i<6; i++) {
            for (int j=0; j<5; j++) {
                  //dla liter alfabetu
                  if (counter < 27) {
                        alphabet_buttons.emplace_back(startX, startY, width, height, alphabet_button_names[counter], startX + width / 2 - 5, startY + height / 2 - 7);
                  }
                  //dla pozostałych 3 znakow i napisow na przyciskach
                  else {
                        alphabet_buttons.emplace_back(startX, startY, width, height, alphabet_button_names[counter], startX + width / 2 - 16, startY + height / 2 - 7);
                  }

                  startX += 38;
                  counter++;
            }
            startX = 190;
            startY += 38;
      }

      //okragle przyciski z cyframi w lewym dolnym rogu
      counter = 0;
      startX = 77;
      startY = 430;
      std::string number_buttons_names[12] = {"  1", "  2", "  3", "  4", "  5", "  6", "  7", "  8", "  9", "   .", "  0", "+/-"};
      for (int i=0; i<4; i++) {
            for (int j=0; j<3; j++) {
                  number_buttons.emplace_back(startX, startY, width, height, number_buttons_names[counter], startX + width / 2 - 9, startY + height / 2 - 7);
                  startX += 34;
                  counter++;
            }
            startX = 77;
            startY += 34;
      }

}

void MCDU::update(sf::RenderWindow& window) {
      //update po przyciskach func_buttton
      for (int i=0; i<func_buttons.size(); i++) {
            if (func_buttons[i].isClicked(window)) {
                  std::cout << "Kliknieto przycisk " << i <<std::endl;
            }
      }

      //update po przyciskach top_buttton
      for (int i=0; i<top_buttons.size(); i++) {
            if (top_buttons[i].isClicked(window)) {
                  std::cout << "Kliknieto przycisk " << i + 12 <<std::endl;
            }
      }

      //update po przyciskach alpgabet_buttons
      for (int i=0; i<alphabet_buttons.size(); i++) {
            if (alphabet_buttons[i].isClicked(window)) {
                  std::cout << "Kliknieto przycisk " << i + 30 <<std::endl;
            }
      }

      //update po przyciskach number_buttons
      for (int i=0; i<number_buttons.size(); i++) {
            if (number_buttons[i].isClicked(window)) {
                  std::cout << "Kliknieto przycisk " << i + 60 <<std::endl;
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
            func_buttons[i].draw_rectangle(window);
      }

      //przyciski top_buttons pod wyswietlaczem
      for (int i=0; i<top_buttons.size(); i++) {
            top_buttons[i].draw_rectangle(window);
      }

      //strzalki na przyciskach
      for (int i=0; i<arrows.size(); i++) {
            window.draw(arrows[i]);
      }

      //przyciski alphabet_buttons
      for (int i=0; i<alphabet_buttons.size(); i++) {
            alphabet_buttons[i].draw_rectangle(window);
      }

      //przyciski number_buttons
      for (int i=0; i<number_buttons.size(); i++) {
            number_buttons[i].draw_circle(window);
      }
}