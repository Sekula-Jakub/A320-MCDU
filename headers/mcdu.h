#include <SFML\Graphics.hpp>
#include <vector>
#include "screen.h"
#include "button.h"

class MCDU {
    private:
        sf::RectangleShape background;          //niebieskie tło

        sf::RectangleShape screen_background;   //czarne tło ekranu
        Screen screen_display;                  //zawartosc ekranu (napisy)

        std::vector<Button> func_buttons;       //12 przyciskow funkcyjnych po bokach ekranu

        std::vector<Button> top_buttons;        //18 przyciskow zaraz pod wyswietlaczem

        sf::Texture arrow_tekstura;
        std::vector<sf::Sprite> arrows;

        std::vector<Button> alphabet_buttons;   //30 przycisków z literami z prawej strony

        std::vector<Button> number_buttons;    //12 przyciskow z cyframi na dole z lewej

        Screen screen;  //klasa Screen

    public:
        //konstruktor
        MCDU();

        void update(sf::RenderWindow& window);
        void render(sf::RenderWindow& window);  //przekazanie referencji do oryginalnego obiektu window

};