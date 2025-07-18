//departure_page_b.h
//Wyswietla strone Departure Page B
//Pobiera dostepne pasy startowe z bazy danych i umozliwia wybor jednego z nich

#ifndef DEPARTURE_PAGE_B_H
#define DEPARTURE_PAGE_B_H

//forward declaration
class Departure_Page_A;

#include "../screen.h"
#include <vector>
#include "../data_base_manager.h"

class Departure_Page_B {
    private:
        Screen* screen;        //wskaźnik do obiektu klasy Screen

        //wskaźnik do poprzedniej strony
        Departure_Page_A* departure_page_a;

        //wektor z dostepnymi pasami startowymi i ich długościami
        std::vector<Runway_Data> available_runways;

        //departure
        std::string departure;

        DatabaseManager db; //baza danych

        //parametry
        std::string rwy;
        std::string sid;
        std::string trans;

        //flaga czy kliknieto na pas
        bool chosen = false;

        //ktory pas wybrany
        int chosen_runway;

    public:
        //konstruktor
        Departure_Page_B(Screen* screen_ptr, Departure_Page_A* departure_page_a_ptr);

        //destruktor
        ~Departure_Page_B();

        void render();

        void input_handler(int button_clicked, Active_Screen &current_page);

        void runway_select(int button_clicked);
};

#endif
