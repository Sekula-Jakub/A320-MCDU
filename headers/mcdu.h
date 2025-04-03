#include <SFML\Graphics.hpp>
#include <vector>
#include "screen.h"
#include "button.h"

class MCDU {
    private:
        sf::RectangleShape background;
        Screen screen;
        std::vector<Button> buttons;

    public:
        //konstruktor
        MCDU();

        void update();
        void render(sf::RenderWindow& window);  //przekazanie referencji do oryginalnego obiektu window

};