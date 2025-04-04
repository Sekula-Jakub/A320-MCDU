#include <SFML/Graphics.hpp>
#include "headers/mcdu.h"

//konstruktor
MCDU::MCDU() {

      //tworzenie tła
      background.setSize(sf::Vector2f(450, 600));
      background.setFillColor(sf::Color(126, 163, 191));      //Ciemnoniebieski kolor
      background.setPosition(0, 0);

      //tworzenie wyświetlacza
      screen_background.setSize(sf::Vector2f(290, 234));
      screen_background.setFillColor(sf::Color::Black);
      screen_background.setPosition(450 / 2 - 145, 600 / 2 - 250);

      //tworzenie przycisków z lewej strony ekranu
      float startX = 40, startY = 50 + 20;

      for (int i=0; i<6; i++) {
            func_buttons_background[i].setSize(sf::Vector2f(30, 20));
            func_buttons_background[i].setPosition(startX, startY);
            func_buttons_background[i].setFillColor(sf::Color::Black);
            startY += (35);
      }

      //tworzenie przyciskow z prawej strony ekranu
      startX = 370 + 10;
      startY = 50 + 20;

      for (int i=6; i<12; i++) {
            func_buttons_background[i].setSize(sf::Vector2f(30, 20));
            func_buttons_background[i].setPosition(startX, startY);
            func_buttons_background[i].setFillColor(sf::Color::Black);
            startY += (35);
      }
}

void MCDU::update() {

}

void MCDU::render(sf::RenderWindow& window) {
      window.draw(background);
      window.draw(screen_background);
      for (int i=0; i<12; i++) {
            window.draw(func_buttons_background[i]);
      }
}