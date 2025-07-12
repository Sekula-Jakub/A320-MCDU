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

        //dostepne pasy startowe i ich długości
        std::vector<std::string> runways;
        std::vector<std::string> runway_lengths;

        //departure
        std::string departure;

        DatabaseManager db; //baza danych

    public:
        //konstruktor
        Departure_Page_B(Screen* screen_ptr, Departure_Page_A* departure_page_a_ptr);

        //destruktor
        ~Departure_Page_B();

        void render();

        void input_handler(int button_clicked, Active_Screen &current_page);
};

#endif
