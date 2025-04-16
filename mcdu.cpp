#include <SFML/Graphics.hpp>
#include "headers/mcdu.h"
#include <iostream>

//konstruktor
MCDU::MCDU() {

      //tworzenie tła
      background.setSize(sf::Vector2f(450, 600));
      background.setFillColor(sf::Color(126, 163, 191));      //Ciemnoniebieski kolor
      background.setPosition(0, 0);

      //tworzenie wyświetlacza
      screen_background.setSize(sf::Vector2f(290, 234));
      screen_background.setFillColor(sf::Color(20, 20, 20));
      screen_background.setPosition(450 / 2 - 145, 600 / 2 - 250);

      //tworzenie przycisków z lewej strony ekranu
      float startX = 40, startY = 50 + 20;

      for (int i=0; i<6; i++) {
            float width = 30.f, height = 20.f;
            func_buttons.emplace_back(startX, startY, width, height);
            startY += 35;
      }

      //tworzenie przyciskow z prawej strony ekranu
      startX = 370 + 10;
      startY = 50 + 20;

      for (int i=6; i<12; i++) {
            float width = 30.f, height = 20.f;
            func_buttons.emplace_back(startX, startY, width, height);
            startY += (35);
      }

      //tworzenie przyciskow na dole


}

void MCDU::update(sf::RenderWindow& window) {
      for (int i=0; i<12; i++) {
            if (func_buttons[i].isClicked(window)) {
                  std::cout << "Kliknieto przycisk " << i <<std::endl;
            }
      }
}

void MCDU::render(sf::RenderWindow& window) {
      window.draw(background);
      window.draw(screen_background);

      //wyswietlacz
      screen.display_screen(window);

      for (auto& button : func_buttons) {
            button.draw(window);
      }



}