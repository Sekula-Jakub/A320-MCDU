#include <SFML\Graphics.hpp>
#include "headers/button.h"
#include <iostream>
#include "headers/font_manager.h"

//konstruktor
Button::Button(float x, float y, float width, float height, const std::string& button_text, float text_x, float text_y) {
    button_shape.setSize(sf::Vector2f(width, height));
    button_shape.setPosition(x, y);
    button_shape.setFillColor(sf::Color(20, 20, 20));


    text.setString(button_text);
    text.setPosition(text_x, text_y);
    text.setCharacterSize(11);
    text.setFont(FontManager::getFont());

    clicked = false;
}

bool Button::isMouseOver(const sf::RenderWindow &window) const {

  //rzutowanie z int na float
  sf::Vector2f mousePosition_float = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    return button_shape.getGlobalBounds().contains(mousePosition_float);
}

bool Button::isMousePressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Button::isClicked(sf::RenderWindow &window) {
    if (isMouseOver(window) && isMousePressed() && !clicked) {
        clicked = true;
        return true;
    }
    if (!isMousePressed()) {
        clicked = false;
    }
    return false;
}

void Button::draw(sf::RenderWindow &window) {
    if (isMouseOver(window)) {
        button_shape.setFillColor(sf::Color::Green);
    }
    else {
        button_shape.setFillColor(sf::Color(20, 20, 20));
    }
    window.draw(button_shape);
    window.draw(text);
}