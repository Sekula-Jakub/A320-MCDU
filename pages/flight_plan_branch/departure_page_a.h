#ifndef DEPARTURE_PAGE_A_H
#define DEPARTURE_PAGE_A_H

//forward declaration
class Departure_Page_B;

#include "../screen.h"
#include "flight_plan.h"

class Departure_Page_A {
    private:
        Screen* screen;     //wskaźnik do obiektu klasy Screen

        //Wskaźnik do poprzedniej strony
        Flight_Plan* flight_plan;

        //Wskaźnik do InitPage
        Init_Page* init_page;

        //współrzedne lotniska
        std::string coordinates;

        //klasa zaprzyjazniona
        friend class Departure_Page_B;


    public:
        //podstrona
        Departure_Page_B* departure_page_b;

        //konstruktor
        Departure_Page_A(Screen* screen_ptr, Flight_Plan* flight_plan_ptr);

        //destruktor
        ~Departure_Page_A();

        void render();

        void input_handler(int button_clicked, Active_Screen &current_page) const;
};

#endif