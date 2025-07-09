#pragma once
#include "screen.h"
#include "data_base_manager.h"

class Arrival_Page_A {
private:
    Screen* screen;     //wskaźnik do obiektu klasy Screen

    //Wskaźnik do poprzedniej strony
    Flight_Plan* flight_plan;

    //Wskaźnik do InitPage do
    Init_Page* init_page;

    //współrzedne lotniska
    std::string coordinates;

public:
    //konstruktor
    Arrival_Page_A(Screen* screen, Flight_Plan* flight_plan);

    //destruktor
    ~Arrival_Page_A();

    void render();

    void input_handler(int button_clicked, Active_Screen &current_page) const;

};
