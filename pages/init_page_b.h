#ifndef INIT_PAGE_B_H
#define INIT_PAGE_B_H

#include "../screen.h"
#include <string>
#include <vector>

class Init_Page_B {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen
        Init_Page* init_page; //wskaznik do poprzedniej strony (init_page_a)

        //parametry
        std::string taxi;           //taxi fuel
        std::string zfw_zfwcg;      //zero fuel weight / zero fuel weight center of gravity
        std::string block_fuel;     //block fuel
        std::string tow;            //take off weight

    public:

        //pusty wektor na input
        std::vector<char> init_page_b_input = {};

        //konstruktor
        Init_Page_B(Screen* screen_ptr, Init_Page* init_page_ptr);

        //destruktor
        ~Init_Page_B();

        void render();

        double tow_calculations(double taxi, double zfw, double block);

        void input_handler(int button_clicked, Active_Screen& current_page);

        //obsluga inputu urzytkownika
        void getInput(int &button_clicked);

        //zatwierdzenie danych
        void insert_data(int &button_clicked);

        void insert_into_zfw_zfwcg(const std::string& input);

        void insert_into_block_fuel(const std::string& input);

        static double string_to_double(const std::string& input);
};

#endif
