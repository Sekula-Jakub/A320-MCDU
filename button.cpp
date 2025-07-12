#include <SFML/Graphics.hpp>
#include "button.h"
#include "font_manager.h"

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

    //zmienna clicked na false bo przycisk nie jest na początku kliknięty
    clicked = false;
}

//destruktor domyślny
Button::~Button() = default;

//Czy mysz jest nad prostokątnym przyciskiem
bool Button::isMouseOver_rectangle(const sf::RenderWindow &window) const {

    //Pobranie pozycji myszy i względem okna i konwersja z int na float, bo tego wymaga SFML
    sf::Vector2f mousePosition_float = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    //czy pozycja myszy mieści się w przycisku
    return button_rectangle_shape.getGlobalBounds().contains(mousePosition_float);
}

//Czy mysz jest nad okrągłym przyciskiem
bool Button::isMouseOver_circle(const sf::RenderWindow &window) const {

    //Pobranie pozycji myszy i względem okna i konwersja z int na float, bo tego wymaga SFML
    const sf::Vector2f mousePosition_float = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    //czy pozycja myszy mieści się w przycisku
    return button_circle_shape.getGlobalBounds().contains(mousePosition_float);
}

//Czy lewy przycisk myszy jest kliknięty
bool Button::isMousePressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

//Czy przycisk został kliknięty, czyli isMouseOver + isMousePressed
bool Button::isClicked(const sf::RenderWindow &window) {
    if (isMouseOver_rectangle(window) && isMousePressed() && !clicked) {
        clicked = true;
        return true;
    }
    if (!isMousePressed()) {
        clicked = false;
    }
    return false;
}

//Rysowanie prostokatnego przycisku
void Button::draw_rectangle(sf::RenderWindow &window) {
    //Zmiana koloru jeśli mysz jest nad przyciskiem
    if (isMouseOver_rectangle(window)) {
        button_rectangle_shape.setFillColor(sf::Color(77, 77, 77));
    }
    else {
        button_rectangle_shape.setFillColor(sf::Color(20, 20, 20));
    }
    //rysowanie kształtu
    window.draw(button_rectangle_shape);
    //rysowanie tekstu na przycisku
    window.draw(text);
}

//Rysowanie okrągłego przycisku
void Button::draw_circle(sf::RenderWindow &window) {
    //Zmiana koloru jeśli mysz jest nad przyciskiem
    if (isMouseOver_circle(window)) {
        button_circle_shape.setFillColor(sf::Color(77, 77, 77));
    }
    else {
        button_circle_shape.setFillColor(sf::Color(20, 20, 20));
    }
    //rysowanie kształtu
    window.draw(button_circle_shape);
    //rysowanie tekstu na przycisku
    window.draw(text);
}
