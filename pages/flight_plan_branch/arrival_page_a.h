//arrival_page_a.h
//Wyswietla strone Arrival Page A
//Zawiera wskaznik i alokuje pamiec na nastepna podstrone

#ifndef ARRIVAL_PAGE_A_H
#define ARRIVAL_PAGE_A_H

//forward declaration
class Arrival_Page_B;

#include "../screen.h"
#include "flight_plan.h"

class Arrival_Page_A {
    private:
        Screen* screen;     //wskaźnik do obiektu klasy Screen

        //Wskaźnik do poprzedniej strony
        Flight_Plan* flight_plan;

        //Wskaźnik do InitPage do
        Init_Page* init_page{};

        //współrzedne lotniska
        std::string coordinates;

    //klasa zaprzyjazniona
    friend class Arrival_Page_B;

    public:
        //podstrona
        Arrival_Page_B* arrival_page_b;

        //konstruktor
        Arrival_Page_A(Screen* screen, Flight_Plan* flight_plan);

        //destruktor
        ~Arrival_Page_A();

        void render();

        void input_handler(int button_clicked, Active_Screen &current_page) const;
};

#endif