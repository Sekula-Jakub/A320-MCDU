#include <SFML/Graphics.hpp>
#include "headers/mcdu.h"
#include <iostream>

int main() {
    //renderowanie okna
    sf::RenderWindow window(sf::VideoMode(450, 600), "Airbus MCDU");

    //dodanie ikony do okna
    sf::Image icon;
    if (!icon.loadFromFile("assets/icon.png")) {
        std::cerr << "Niegit add .gitignore można załadować ikony!" << std::endl;
    }
    else {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    //stworzenie obiektu mcdu klasy MCDU
    MCDU mcdu;

    while (window.isOpen()) {
        //obsluga zdarzen
        sf::Event event;

        while (window.pollEvent(event)) {
            //zamykanie okna
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //aktualizacja logiki mcdu
        mcdu.update();

        //renderowanie
        window.clear();
        mcdu.render(window);
        window.display();
    }

    return 0;
}