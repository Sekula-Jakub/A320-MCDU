#include <SFML\Graphics.hpp>
#include "headers/button.h"

//konstruktor
Button::Button(float x, float y, float width, float height) {
    button_shape.setSize(sf::Vector2f(width, height));
    button_shape.setPosition(x, y);
    button_shape.setFillColor(sf::Color(20, 20, 20));
}

bool Button::isMouseOver(sf::RenderWindow &window) {
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

  //rzutowanie z int na float
  sf::Vector2f mousePosition_float = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    return button_shape.getGlobalBounds().contains(mousePosition_float);
}

bool Button::isMousePressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Button::isClicked(sf::RenderWindow &window) {
    return isMouseOver(window) && isMousePressed();
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(button_shape);
}