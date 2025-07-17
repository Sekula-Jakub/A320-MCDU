//main.cpp
//Głowna pątla programu. Inicjalizuje okno programu z użycium SFML, ładuje czcionkę,
//tworzy obiekt klasy MCDU i obsluguje aktualizacje.

#include <SFML/Graphics.hpp>
#include "mcdu.h"
#include "font_manager.h"
#include <iostream>

int main() {

    //zaladowanie czcionki przy pomocy klasy FontManager
    FontManager::loadFont("fonts/Inter_28pt-Black.ttf");

    //renderowanie okna
    sf::RenderWindow window(sf::VideoMode(450, 600), "Airbus A320 MCDU");

    //ograniczenie odświeżania ekranu do 30 kl/s dla zmniejszenia zuzycia zasobów
    window.setFramerateLimit(30);

    //dodanie ikony do okna
    sf::Image icon;
    if (!icon.loadFromFile("assets/icon.png")) {
        std::cerr << "Nie można załadować ikony!" << std::endl;
    }
    else {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());    // getPixelsPtr() - wskaźnik do danych pikseli w pamięci
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
        mcdu.update(window);

        //RENDEROWANIE
        //wyczyszcenie okna window
        window.clear();

        //wyrenderowaniu mcdu
        mcdu.render(window);

        //wyświetlenie okna window
        window.display();
    }
    return 0;
}