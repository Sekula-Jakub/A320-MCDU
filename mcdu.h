//mcdu.h
//Deklaracja klasy MCDU, symulującej panel kontrolny komputera pokładowego.
//Klasa zarządza rysowaniem interfejsu, obsługą przycisków oraz logiką ekranów.

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

        std::vector<Button> func_buttons;       //12 przyciskow funkcyjnych po bokach ekranu - numerowane są od 0 do 11 od gówy do dołu, od lewej do prawej

        std::vector<Button> top_buttons;        //18 przyciskow zaraz pod wyswietlaczem - numerowane od 12 do 29 jw.

        sf::Texture arrow_tekstura;             //tekstura ze strzałkami
        std::vector<sf::Sprite> arrows;         //wektor spritów czyli gotowych do rysowania obrazków

        std::vector<Button> alphabet_buttons;   //30 przycisków z literami z prawej strony - numerowane od 30 do 59 jw.

        std::vector<Button> number_buttons;    //12 przyciskow z cyframi na dole z lewej - numerowane od 60 do 71

        Screen screen;  //obiekt klasy Screen odpowiedzialny za wyswietlanie odpowiednich stron

        int button_clicked = -1;      //zmienna przechowująca wartosc przycisku ktory zostal jako ostatni klikniety

    public:

        //konstruktor
        MCDU();

        //destruktor
        ~MCDU();

        //updatowanie po kliknietych przyciskach - przekazanie referencji do oryginalnego obiektu window
        void update(sf::RenderWindow& window);

        //Renderowanie okna - przekazanie referencji do oryginalnego obiektu window
        void render(sf::RenderWindow& window);
};

#endif