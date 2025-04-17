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
        bool isMouseOver_rectangle(const sf::RenderWindow& window) const;

        bool isMouseOver_circle(const sf::RenderWindow& window) const;

        //lewy przycisk myszy klikniety
        static bool isMousePressed();

        bool isClicked(sf::RenderWindow& window);   //MouseOver + MousePressed

        void draw_rectangle(sf::RenderWindow& window);  //rysowanie prostokątnego przycisku

        void draw_circle(sf::RenderWindow& window);     //rysowanie okraglego przycisku

    private:
        sf::RectangleShape button_rectangle_shape;  //kształt prostokąt
        sf::CircleShape button_circle_shape;       //kształt dla okrągłych przycisków
};