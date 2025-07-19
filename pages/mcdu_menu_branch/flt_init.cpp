//flt_init.cpp
//Implementacja klasy Flt_Init

#include "flt_init.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../input.h"
#include <../database_sqlite3_files/sqlite3.h>
#include "../data_base_manager.h"
#include <vector>

//konstruktor
Flt_Init::Flt_Init(Screen* screen_ptr) {
    screen = screen_ptr;
}

//domyslny destruktor
Flt_Init::~Flt_Init() = default;

void Flt_Init::render() const {

    std::cout << "[DEBUG] flt_no = " << flt_no << std::endl;

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("                  AOC FLT INIT", sf::Color::White);

    //LEWA STRONA EKRANU

    //FLT NO
    screen -> draw_text(6, "FLT NO", sf::Color::White);
    if(flt_no.empty()) {
        screen -> draw_text(0, "[ ][ ][ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(0, flt_no, sf::Color(0, 255, 255));
    }

    //DEP
    screen -> draw_text(7, "DEP", sf::Color::White);
    if(dep.empty()) {
        screen -> draw_text(1, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(1, dep, sf::Color(0, 255, 255));
    }

    //DEST
    screen -> draw_text(8, "DEST", sf::Color::White);
    if(dest.empty()) {
        screen -> draw_text(2, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(2, dest, sf::Color(0, 255, 255));
    }

    //ALT
    screen -> draw_text(9, "ALTN", sf::Color::White);
    if(altn.empty()) {
        screen -> draw_text(3, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(3, altn, sf::Color(0, 255, 255));
    }

    //ETE
    screen -> draw_text(10, "ETE", sf::Color::White);
    if(ete.empty()) {
        screen -> draw_text(4, "[ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(4, ete, sf::Color(0, 255, 255));
    }

    //PRAWA STRONA EKRANU
    screen -> draw_text(30, "                      UTC", sf::Color::White);
    screen -> draw_text(24, getTimeUTC(), sf::Color::Green);
    screen -> draw_text(32, "                     DATE", sf::Color::White);
    screen -> draw_text(26, getDateUTC(), sf::Color::Green);

    //input uzytkownika
    screen -> draw_text(36, vector_to_string(flt_init_input), sf::Color::White);
}

//Zwraca aktualna date w formacie dd/mm/yyyy
std::string Flt_Init::getDateUTC() {
    const std::time_t t = std::time(nullptr);     //pobranie aktualnego czasu
    const std::tm* utc = std::gmtime(&t);         //konwersja na czas UTC

    //Bufor do ktorego bedzie zapisana data w odpowiednim formacie
    char date[64];

    //sprintf zapisuje dane do bufora (chara)
    //%02d - liczba z dwoma cyframi, z zerem z przodu jeśli potrzeba np 05, 08
    //tm_mon + 1 — bo miesiące są w zakresie 0-11
    //tm_year + 1900 — bo liczony od 1900
    std::snprintf(date, sizeof(date), "      %02d/%02d/%04d", utc->tm_mday, utc->tm_mon + 1, utc->tm_year + 1900);

    std::string dateUTC = date;

    return dateUTC;
}

//Zwraca aktualny czas UTC w formacie hhmm
std::string Flt_Init::getTimeUTC() {
    const std::time_t t = std::time(nullptr);     //pobranie aktualnego czasu
    const std::tm* utc = std::gmtime(&t);         //konwersja na czas UTC

    //Bufopr na wynikowy tekst czasu
    char time[64];

    //sprintf zapisuje dane do bufora (chara)
    std::snprintf(time, sizeof(time), "                %02d%02d", utc->tm_hour, utc->tm_min);

    //string do ktoego zapisujemy bufor znakowy
    std::string timeUTC = time;

    return timeUTC;
}

void Flt_Init::getInput(int &button_clicked) {
    get_input(button_clicked, flt_init_input);
    std::cout << "flt_init_input.size() = \n" << flt_init_input.size() << std::endl;
    //std::cout << vector_to_string(flt_init_input) << std::endl;
}

void Flt_Init::insert_data(const int &button_clicked) {

    switch (button_clicked) {
        case 0:
            insert_into_flt_no(vector_to_string(flt_init_input));
            break;

        case 1:
            insert_into_dep(vector_to_string(flt_init_input));
            break;

        case 2:
            insert_into_dest(vector_to_string(flt_init_input));
            break;

        case 3:
            insert_into_altn(vector_to_string(flt_init_input));
            break;

        case 4: {
            std::string temp = vector_to_string(flt_init_input);
            insert_into_ete(temp);
            break;
        }

        default:
            break;
    }

}

void Flt_Init::insert_into_flt_no(const std::string& input) {

    if (input.empty()) {
        return;
    }

    if (input.size() <= 3 && !input.empty()) {
        flt_init_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    if (input.size() >=3 && input.size() <=7) {
        for (int i=0; i<3; i++) {
            if (input[i] <'A' || input[i] > 'Z') {
                flt_init_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                return;
            }
        }
        for (int i=3; i<input.size(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                flt_init_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                return;
            }
        }
    }

    if (input.size() > 7) {
        flt_init_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    flt_no = input;
    std::cout << "[DEBUG] Zapisywanie FLT_NO: " << input << std::endl;

    //wyczyszcenie inputu wektora
    flt_init_input.clear();

}

void Flt_Init::insert_into_dep(const std::string& input) {

    std::string code = input;

    std::cout<<"code: " << code << std::endl;

    if (db.airport_in_data_base(code) == true) {
        dep = input;
    }
    else {
        flt_init_input = {'N', 'O', 'T', ' ', 'I', 'N', ' ', 'D', 'A', 'T', 'A', ' ', 'B', 'A', 'S', 'E', '!'};
        return;
    }

    //wyczyszcenie inputu wektora
    flt_init_input.clear();
}

void Flt_Init::insert_into_dest(const std::string &input) {

    std::string code = input;

    std::cout<<"code: " << code << std::endl;

    if (db.airport_in_data_base(code) == true) {
        dest = input;
    }

    else {
        flt_init_input = {'N', 'O', 'T', ' ', 'I', 'N', ' ', 'D', 'A', 'T', 'A', ' ', 'B', 'A', 'S', 'E', '!'};
        return;
    }

    //wyczyszcenie inputu wektora
    flt_init_input.clear();
}

void Flt_Init::insert_into_altn(const std::string &input) {

    std::string code = input;

    std::cout<<"code: " << code << std::endl;

    if (db.airport_in_data_base(code) == true) {
        altn = input;
    }

    else {
        flt_init_input = {'N', 'O', 'T', ' ', 'I', 'N', ' ', 'D', 'A', 'T', 'A', ' ', 'B', 'A', 'S', 'E', '!'};
        return;
    }

    //wyczyszcenie inputu wektora
    flt_init_input.clear();
}

//WYJĄTKI
//Insert into estimated time enroute
void Flt_Init::insert_into_ete(std::string &input) {
    int number;

    //wyjatki
    //TRY -> to co moze wyrzucic wyjatek
    try {
        size_t pos;

        //proba zamiany
        number = std::stoi(input, &pos);

        //sprawdzenie, czy caly string zostal zamieniony na liczbe
        if (pos != input.length()) {
            throw std::invalid_argument("Niepełna konwersja");
        }

        //sprawdzenie zakresu liczby
        if (number < 1 || number > 9999) {
            throw std::out_of_range("Poza zakresem");
        }

        //sformatowanie wygladu liczby
        while (input.size() < 4) {
            input.insert(input.begin(), '0');
        }

        ete = input;
        flt_init_input.clear();
    }
    //w przypadku wystapienia bledu
    catch (...) {
        flt_init_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
    }
}

