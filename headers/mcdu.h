#include <SFML\Graphics.hpp>
#include <vector>
#include "screen.h"
#include "button.h"

class MCDU {
    private:
        sf::RectangleShape background;          //niebieskie tło

        sf::RectangleShape screen_background;   //czarne tło ekranu
        Screen screen_display;                  //zawartosc ekranu (napisy)

        sf::RectangleShape func_buttons_background[12];    //tło przycisków funkcyjnych
        sf::RectangleShape func_buttons_white_strip[12];

        std::vector<Button> func_buttons;                          //funkcjonalnosc przyciskow

        Screen screen;  //klasa Screen

    public:
        //konstruktor
        MCDU();

        void update();
        void render(sf::RenderWindow& window);  //przekazanie referencji do oryginalnego obiektu window

};