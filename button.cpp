#include <SFML\Graphics.hpp>
#include "headers/button.h"
#include <iostream>
#include "headers/font_manager.h"

//konstruktor
Button::Button(float x, float y, float width, float height, const std::string& button_text, float text_x, float text_y) {
    button_rectangle_shape.setSize(sf::Vector2f(width, height));
    button_rectangle_shape.setPosition(x, y);
    button_rectangle_shape.setFillColor(sf::Color(20, 20, 20));

    button_circle_shape.setRadius(14);
    button_circle_shape.setPosition(x, y);
    button_circle_shape.setFillColor(sf::Color(20, 20, 20));


    text.setString(button_text);
    text.setPosition(text_x, text_y);
    text.setCharacterSize(11);
    text.setFont(FontManager::getFont());

    clicked = false;
}

bool Button::isMouseOver_rectangle(const sf::RenderWindow &window) const {

  //rzutowanie z int na float
  sf::Vector2f mousePosition_float = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    return button_rectangle_shape.getGlobalBounds().contains(mousePosition_float);
}

bool Button::isMouseOver_circle(const sf::RenderWindow &window) const {

    //rzutowanie z int na float
    sf::Vector2f mousePosition_float = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    return button_rectangle_shape.getGlobalBounds().contains(mousePosition_float);
}

bool Button::isMousePressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Button::isClicked(sf::RenderWindow &window) {
    if (isMouseOver_rectangle(window) && isMousePressed() && !clicked) {
        clicked = true;
        return true;
    }
    if (!isMousePressed()) {
        clicked = false;
    }
    return false;
}

void Button::draw_rectangle(sf::RenderWindow &window) {
    if (isMouseOver_rectangle(window)) {
        button_rectangle_shape.setFillColor(sf::Color(77, 77, 77));
    }
    else {
        button_rectangle_shape.setFillColor(sf::Color(20, 20, 20));
    }
    window.draw(button_rectangle_shape);
    window.draw(text);
}

void Button::draw_circle(sf::RenderWindow &window) {
    if (isMouseOver_circle(window)) {
        button_circle_shape.setFillColor(sf::Color(77, 77, 77));
    }
    else {
        button_circle_shape.setFillColor(sf::Color(20, 20, 20));
    }
    window.draw(button_circle_shape);
    window.draw(text);
}
