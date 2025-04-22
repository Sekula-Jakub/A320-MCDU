#include <SFML/Graphics.hpp>
#include "../pages/pages_headers/mcdu_menu.h"

class Screen {
    private:
        sf::Text page_title;

        //strzałki na niektorych stronach (prawo - lewo)
        sf::Texture arrow_tekstura;
        std::vector<sf::Sprite> arrows;

        sf::Text texts[36];     //36 napisow, 3 kolumny w każdej po 6 wierszy, w wierszach po dwa napisy - mniejszy nad większym
        sf::Color texts_colors[36] = {sf::Color::White};            //kolory napisow

        sf::Font font;      //czcionka

    public:
        //konstruktor
        Screen();

        //update tekstu
        void draw_text(int index, const std::string& str, sf::Color color);

        //wyswietlanie zawartosci ekranu
        void display_screen(sf::RenderWindow &window);

};