#include <SFML/Graphics.hpp>
#include "headers/mcdu.h"

//konstruktor
MCDU::MCDU() {

      //tworzenie tła
      background.setSize(sf::Vector2f(450, 600));
      background.setFillColor(sf::Color(126, 163, 191));      //Ciemnoniebieski kolor
      background.setPosition(0, 0);

      //tworzenie wyświetlacza
      screen.setSize(sf::Vector2f(250, 250));
      screen.setFillColor(sf::Color::Black);
      screen.setPosition(450 / 2 - 125, 600 / 2 - 250);
}

void MCDU::update() {

}

void MCDU::render(sf::RenderWindow& window) {
      window.draw(background);
      window.draw(screen);
}