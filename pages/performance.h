//performance.h
//Renderuje strone Performance
//Umozliwia wprowadzenie danych startowych

#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include "../screen.h"
#include <string>
#include <vector>

class Performance {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        //wskaznik do flight plan
        Flight_Plan* flight_plan;

        //parametry
        std::string rwy;
        std::string V1;
        std::string VR;
        std::string V2;
        std::string trans_alt;
        std::string flaps;
        std::string flex;

    public:
        //pusty wektor na input
        std::vector<char> performance_input = {};

        //konstruktor
        Performance(Screen* screen_ptr, Flight_Plan* flight_plan_ptr);

        //destruktor
        ~Performance();

        void render();

        //obsluga inputu urzytkownika
        void getInput(int &button_clicked);

        //zatwierdzenie danych
        void insert_data(int &button_clicked);

        void insert_into_V1_VR_V2(const std::string& input, int button_clicked);
        void insert_into_VR(const std::string& input);
        void insert_into_V2(const std::string& input);
        void insert_into_trans(const std::string& input);
        void insert_into_flaps(const std::string& input);
        void insert_into_flex(const std::string& input);

        void input_handler(int button_clicked, Active_Screen& current_page) const;
};

#endif
