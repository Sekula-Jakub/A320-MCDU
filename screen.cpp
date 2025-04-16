#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/screen.h"

//konstruktor
Screen::Screen() {
    //wczytanie czcionki
    if(font.loadFromFile("fonts/Inter_24pt-Regular.ttf") == false) {
      std::cerr << "Error loading font" << std::endl;
    }

    //tytul strony
    page_title.setFont(font);
    page_title.setCharacterSize(14);
    page_title.setString("MCDU MENU");
    page_title.setFillColor(sf::Color::White);
    page_title.setPosition(170, 52);

    //teksty
    for(int i=0; i<12; i++) {
        texts[i].setFont(font);
        texts[i].setCharacterSize(14);
        texts[i].setString("dupa");
        texts[i].setFillColor(sf::Color::White);
    }

    //pozycja tekstow z lewej strony
    float startX = 90, startY = 50 + 20;

    for(int i=0; i<6; i++) {
        texts[i].setPosition(startX, startY);
        startY += 35;
    }

    //pozycja tekstow z prawej strony
    startX = 310 + 10;
    startY = 50 + 20;

    for(int i=6; i<12; i++) {
        texts[i].setPosition(startX, startY);
        startY += 35;
    }
}

void Screen::update_Text(int index, const std::string& str) {
    if(index >= 0 && index < 12) {
        texts[index].setString(str);
    }
}

void Screen::display_screen(sf::RenderWindow &window) {
    window.draw(page_title);

    for(int i=0; i<12; i++) {
      window.draw(texts[i]);
    }
}
