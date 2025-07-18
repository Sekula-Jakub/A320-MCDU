//arrival_page_b.h
//Wyswietla strone Arrival Page B
//Pobiera dostepne pasy startowe z bazy danych i umozliwia wybor jednego z nich

#ifndef ARRIVAL_PAGE_B_H
#define ARRIVAL_PAGE_B_H

//forward declaration
class Arrival_Page_A;

#include "../screen.h"
#include <vector>
#include "../data_base_manager.h"

class Arrival_Page_B {
    private:
        Screen* screen;        //wskaźnik do obiektu klasy Screen

        //wskaźnik do poprzedniej strony
        Arrival_Page_A* arrival_page_a;

        //wektor z dostepnymi pasami startowymi i ich długościami
        std::vector<Runway_Data> available_runways;

        //arrival
        std::string arrival;

        DatabaseManager db; //baza danych

        //parametry
        std::string appr;
        std::string via;
        std::string star;
        std::string trans;

        //flaga czy kliknieto na pas
        bool chosen = false;

        //ktory pas wybrany
        int chosen_runway{};

    public:
        //konstruktor
        Arrival_Page_B(Screen* screen_ptr, Arrival_Page_A* arrival_page_a_ptr);

        //destruktor
        ~Arrival_Page_B();

        void render();

        void input_handler(int button_clicked, Active_Screen &current_page);

        void runway_select(int button_clicked);
};

#endif //ARRIVAL_PAGE_B_H
