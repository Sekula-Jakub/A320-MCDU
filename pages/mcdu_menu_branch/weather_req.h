#pragma once
#include "screen.h"
#include "data_base_manager.h"

class Weather_req {
private:
    Screen* screen;

    //IDENT
    std::string ident;

    DatabaseManager db; //baza danych

    //podstrony


public:

    //pusty wektor na input
    std::vector<char> weather_req_input = {};

    //czy tak czy nie request metar/tar
    bool metar = false;
    bool tar = false;

    //konstruktor
    explicit Weather_req(Screen* screen);

    //destruktor
    ~Weather_req();

    //renderowanie
    void render() const;

    void input_handler(int button_clicked, Active_Screen& current_page);

    //obsluga inputu uzytkownika
    void getInput(int &button_clicked);

    //zatwierdzenie danych
    void insert_data(int &button_clicked);
};


