#pragma once
#include <screen.h>
#include <string>

class Flt_Init {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

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
};
