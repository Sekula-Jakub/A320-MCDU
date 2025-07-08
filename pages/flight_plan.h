#pragma once
#include "../headers/screen.h"
#include <string>
#include "data_base_manager.h"
#include "flight_plan_branch/departure_page_a.h"

class Flight_Plan {
private:
    Screen* screen;     //wskaźnik do obiektu klasy Screen

    //Wskaźnik do InitPage do
    Init_Page* init_page;

    DatabaseManager db; //baza danych

public:

    std::string departure;
    std::string arrival;

    std::string coordinates_dep;
    std::string coordinates_arr;

    //podstrony
    Departure_Page_A* departure_page_a;

    //konstruktor
    Flight_Plan(Screen* screen, Init_Page* init_page);

    //destruktor
    ~Flight_Plan();

    void render_empty();

    void render_ready();

    void input_handler(int button_clicked, Active_Screen& current_page);

    //wyszukanie w bazie danych koordynatow
    std::string get_coordinates(const std::string &icaoCode) const;

    //odległośc między dwoma punktami
    double calculate_distance();

    //wyłuskanie latitude
    double get_latitude(std::string coordinates);

    //wyłuskanie longitude
    double get_longitude(std::string coordinates);

    std::string get_distance();
};