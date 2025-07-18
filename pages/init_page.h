//init_page.h
//Renderuje ekran Init Page A
//Umozliwia wprowadzanie parametrow lotu

#ifndef INIT_PAGE_H
#define INIT_PAGE_H

#include "../screen.h"
#include <string>
#include "mcdu_menu_branch/aoc_menu.h"
#include <vector>
#include "init_page_b.h"

class Init_Page {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        //wskaźnik do Flt_Init
        Flt_Init *flt_init;

        //parametry
        std::string co_rte;
        std::string alternative;
        std::string from_to;
        std::string from;
        std::string to;
        std::string flt_number;
        std::string cost_index;
        std::string crz_fl;

    public:

        //podstrony
        Init_Page_B* init_page_b;

        //flaga init_request
        bool init_request_pressed = false;

        //pusty wektor na input
        std::vector<char> init_page_input = {};

        //konstruktor
        Init_Page(Screen* screen_ptr, Flt_Init* flt_init);

        //destruktor
        ~Init_Page();

        void render();

        //INIT REQUEST
        void init_request(int button_clicked);

        //obsluga inputu urzytkownika
        void getInput(int &button_clicked);

        //zatwierdzenie danych
        void insert_data(int &button_clicked);

        void insert_into_flt_number(const std::string& input);

        void insert_into_cost_index(const std::string& input);

        void insert_into_crz_fl(const std::string& input);

        //konwersja temperatury - zwraca temperature na wysokości przelotowej jako string
        std::string temperature_conversion(int attitude);

        void input_handler(int button_clicked, Active_Screen& current_page) const;

        //gettery
        std::string getFltNumber();
        std::string getDep();
        std::string getDest();
        bool getIsFilled() const;
};

#endif