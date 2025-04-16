#include <SFML\Graphics.hpp>
#include <string>

class Button {
    public:

        std::string button_text;

        //domyślny konstruktor

        Button(float x, float y, float width, float height);

        bool isMouseOver(sf::RenderWindow& window);

        bool isMousePressed();

        bool isClicked(sf::RenderWindow& window);   //MouseOver + MousePressed

        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape button_shape;  //kształt
};