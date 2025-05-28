#pragma once
#include <screen.h>
#include <string>
#include <vector>

class Flt_Init {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

    //input uzytkownika jako wektor
    std::vector<char> input;

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

    //konstruktor
    explicit Flt_Init(Screen* screen_ptr);

    //destruktor
    ~Flt_Init();

    //renderowanie
    void render();

    //data i czas
    std::string getDateUTC();
    std::string getTimeUTC();

    //obsluga inputu uzytkownika
    void getInput(int button_clicked);
};
