#pragma once
#include <screen.h>
#include <string>
#include <vector>
#include "../input.h"

class Flt_Init {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

    //input jako string
    std::string input_string;

    //parametry
    std::string flt_no;
    std::string dep;
    std::string dest;
    std::string altn;
    std::string ete;

    //podstrony

public:

    //pusty wektor na input
    std::vector<char> flt_init_input = {};

    //konstruktor
    explicit Flt_Init(Screen* screen_ptr);

    //destruktor
    ~Flt_Init();

    //renderowanie
    void render();

    //data i czas
    static std::string getDateUTC();
    static std::string getTimeUTC();

    //obsluga inputu uzytkownika
    void getInput(int &button_clicked);
};
