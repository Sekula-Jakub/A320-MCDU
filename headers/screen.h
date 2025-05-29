#pragma once
#include <SFML/Graphics.hpp>
#include "../pages/active_screen.h"

class Mcdu_Menu;

class Screen {
    private:
        sf::Text page_title;

        //strzałki na niektorych stronach (prawo - lewo)
        sf::Texture arrow_tekstura;
        std::vector<sf::Sprite> arrows;

        sf::Text texts[37];     //36 napisow, 3 kolumny w każdej po 6 wierszy, w wierszach po dwa napisy - mniejszy nad większym + 1 napis input uzytkownika na dole
        sf::Color texts_colors[36] = {sf::Color::White};            //kolory napisow

        sf::Font font;      //czcionka

        //podstrony
        Mcdu_Menu* mcdu_menu;

    public:

        Active_Screen current_page = Active_Screen::null;

        //konstruktor
        Screen();

        //destruktor
        ~Screen();

        //update tytulu strony
        void draw_title(std::string title, sf::Color color);

        //update tekstu
        void draw_text(int index, const std::string& str, sf::Color color);

        //wyswietlanie zawartosci ekranu
        void display_screen(sf::RenderWindow &window, int& button_clicked);
};