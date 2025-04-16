#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class FontManager {
public:
    static void loadFont(const std::string& path);  // Ładowanie czcionki
    static sf::Font& getFont();  // Pobieranie czcionki

private:
    static sf::Font font;  // Przechowywana czcionka
};