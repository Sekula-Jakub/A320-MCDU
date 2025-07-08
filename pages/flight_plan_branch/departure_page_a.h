#pragma once
#include "screen.h"
#include "data_base_manager.h"

class Departure_Page_A {
private:
    Screen* screen;     //wskaźnik do obiektu klasy Screen
    Flight_Plan* flight_plan;

    //Wskaźnik do InitPage do
    Init_Page* init_page;

    //współrzedne lotniska
    std::string coordinates;

public:
    //konstruktor
    Departure_Page_A(Screen* screen, Flight_Plan* flight_plan);

    //destruktor
    ~Departure_Page_A();

    void render();

};
