#ifndef MCDU_H
#define MCDU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "screen.h"
#include "button.h"

class MCDU {
    private:
        sf::RectangleShape background;          //niebieskie tło

        sf::RectangleShape screen_background;   //czarne tło ekranu

        std::vector<Button> func_buttons;       //12 przyciskow funkcyjnych po bokach ekranu

        std::vector<Button> top_buttons;        //18 przyciskow zaraz pod wyswietlaczem

        sf::Texture arrow_tekstura;             //tekstura ze strzałkami
        std::vector<sf::Sprite> arrows;         //wektor spritów czyli gotowych do rysowania obrazków

        std::vector<Button> alphabet_buttons;   //30 przycisków z literami z prawej strony

        std::vector<Button> number_buttons;    //12 przyciskow z cyframi na dole z lewej

        Screen screen;  //obiekt klasy Screen

        int button_clicked = -1;      //zmienna przechowująca wartosc przycisku ktory zostal jako ostatni klikniety

    public:

        //konstruktor
        MCDU();

        //destruktor
        ~MCDU();

        //updatowanie po kliknietych przyciskach
        void update(sf::RenderWindow& window);

        //Renderowanie okna - przekazanie referencji do oryginalnego obiektu window
        void render(sf::RenderWindow& window);

};

#endif