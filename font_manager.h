//font_manager.h
//Klasa do zarządzania czcionką
//Umożliwia załadowanie czcionki tylko raz i udostępnienie jej globalnie dzięki obiektowi sf::Font

#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SFML/Graphics.hpp>    //biblioteka SFML do czcionek
#include <string>

class FontManager {
    public:
        // Ładowanie czcionki z podanej ścieżki
        static void loadFont(const std::string& path);

        // Zwrócenie referencji do załadowanej czcionki
        static sf::Font& getFont();

    private:
        // Przechowywana czcionka jako statyczna instancja
        static sf::Font font;   //static - czyli istnieje ttylko jedna taka czcionka dla calej aplikacji
};

#endif