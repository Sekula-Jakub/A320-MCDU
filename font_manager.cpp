#include <SFML/Graphics.hpp>
#include "headers/font_manager.h"

sf::Font FontManager::font;

void FontManager::loadFont(const std::string& path) {
    if (!font.loadFromFile(path)) {
        std::cerr << "Failed to load font: " << path << std::endl;
        exit(1);
    }
}

// Zwracanie czcionki
sf::Font& FontManager::getFont() {
    return font;
}