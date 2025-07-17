//button.h
//Deklaracja klasy Button, reprezentującej przycisk wraz z obsługą kliknięć i wyświetlaniem

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
    public:
        //czy klikniety
        bool clicked;

        //tekst na przycisku
        sf::Text text;
        std::string string_text;
        sf::Font font;

        //Metody są w public, ponieważ są używane na zewnątrz klasy w mcdu.cpp
        //konstruktor
        Button(float x, float y, float width, float height, const std::string& button_text, float text_x, float text_y);

        //destruktor
        ~Button();

        //czy mysz jest nad przyciskiem
        //nad prostokatem
        bool isMouseOver_rectangle(const sf::RenderWindow& window) const;
        //nad kółkiem
        bool isMouseOver_circle(const sf::RenderWindow& window) const;

        static bool isMousePressed();               //czy lewy przycisk myszy klikniety

        bool isClicked(const sf::RenderWindow& window);   //MouseOver + MousePressed

        void draw_rectangle(sf::RenderWindow& window);  //rysowanie prostokątnego przycisku

        void draw_circle(sf::RenderWindow& window);     //rysowanie okraglego przycisku

    private:
        sf::RectangleShape button_rectangle_shape;  //kształt prostokąt
        sf::CircleShape button_circle_shape;       //kształt dla okrągłych przycisków
};

#endif