#include <SFML/Graphics.hpp>
#include "headers/screen.h"
#include <iostream>

//konstruktor
Screen::Screen() {

    //wczytanie czcionki
    if(font.loadFromFile("fonts/Inter_24pt-Regular.ttf") == false) {
        std::cerr << "Error loading font" << std::endl;
    }

    //wczytanie strzalki
    if (!arrow_tekstura.loadFromFile("assets/arrow_4.png")) {
        printf("Error loading arrow_icon.png\n");
        exit(1);
    }

    //tytul strony
    page_title.setFont(font);
    page_title.setCharacterSize(12);
    page_title.setString("MCDU MENU");
    page_title.setFillColor(sf::Color::White);
    page_title.setPosition(170, 26);

    //teksty glowne
    for(int i=0; i<36; i++) {
        texts[i].setFont(font);
        texts[i].setString("dupa");
        texts[i].setFillColor(sf::Color::White);
    }

    //========LEWA STRONA========
    //main texts
    float startX = 90, startY = 48;

    for(int i=0; i<6; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(14);
        startY += 35;
    }
    //upper_texts
    startX = 90, startY = 40;

    for(int i=6; i<12; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(9);
        startY += 35;
    }

    //========ŚRODEK========
    //pozycja tekstow na środku
    startX = 200;
    startY = 48;

    for(int i=12; i<18; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(14);
        startY += 35;
    }

    //upper_texts na srodku
    startX = 200;
    startY = 40;

    for(int i=18; i<24; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(9);
        startY += 35;
    }

    //========PRAWA STRONA========
    //pozycja tekstow z prawej strony
    startX = 310 + 10;
    startY = 48;

    for(int i=24; i<30; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(14);
        startY += 35;
    }

    //pozycja tekstow na srodku
    startX = 320;
    startY = 40;

    for(int i=30; i<36; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(9);
        startY += 35;
    }

}

void Screen::draw_text(int index, const std::string &text, sf::Color color) {
    //obsluga bledu
    if (index > 36 || index < 0) {
        return;
    }
    texts[index].setString(text);
    texts[index].setColor(color);
}

void Screen::display_screen(sf::RenderWindow &window) {
    window.draw(page_title);

    for(int i=0; i<36; i++) {
      window.draw(texts[i]);
    }
}
