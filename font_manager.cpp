//font_manager.cpp
//Implementacja klasy FontManager

#include <SFML/Graphics.hpp>
#include "font_manager.h"
#include <iostream>

//definicja globalnej zmiennej statycznej
//automatyczna inicjalizacja tej zmiennej
sf::Font FontManager::font;

//Załadowanie czcionki z pliku
void FontManager::loadFont(const std::string& path) {
    if (!font.loadFromFile(path)) {
        std::cerr << "Failed to load font: " << path << std::endl;
        exit(1);
    }
}

// Zwracanie referencji do załadowanej wcześniej czcionki
sf::Font& FontManager::getFont() {
    return font;
}