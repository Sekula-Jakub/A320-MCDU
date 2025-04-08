#include <SFML\Graphics.hpp>

class Screen {
    private:
        sf::Text page_title;
        sf::Text texts[12];
        sf::Color texts_colors[12] = {sf::Color::White};
        sf::Font font;

    public:
        //konstruktor
        Screen();

        //update tekstu
        void update_Text(int index, const std::string& str);

        //wyswietlanie zawartosci ekranu
        void display_screen(sf::RenderWindow &window);

};