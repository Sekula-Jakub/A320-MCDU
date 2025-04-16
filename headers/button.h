#include <SFML\Graphics.hpp>
#include <string>

class Button {
    public:

        bool clicked;       //czy klikniety

        //tekst na przycisku
        sf::Text text;
        std::string string_text;
        sf::Font font;

        //konstruktor
        Button(float x, float y, float width, float height, const std::string& button_text, float text_x, float text_y);

        //mysz nad przyciskiem (const podpowiedzial edytor)
        bool isMouseOver(const sf::RenderWindow& window) const;

        //lewy przycisk myszy klikniety
        static bool isMousePressed();

        bool isClicked(sf::RenderWindow& window);   //MouseOver + MousePressed

        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape button_shape;  //kształt
};