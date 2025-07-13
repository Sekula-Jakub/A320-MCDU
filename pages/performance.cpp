#include "performance.h"
#include <iostream>
#include "input.h"

//konstruktor
Performance::Performance(Screen* screen_ptr, Flight_Plan* flight_plan_ptr) {
    screen = screen_ptr;
    flight_plan = flight_plan_ptr;
}

//domyslny destruktor
Performance::~Performance() = default;

void Performance::render() {

    //pobranie numeru pasa strtowego z flight_plan
    rwy = flight_plan -> dep_runway;

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    screen -> draw_title("                  TAKE  OFF  RWY  " + rwy, sf::Color::White );

    //LEWA STRONA
    //V1
    screen -> draw_text(6,"V1", sf::Color::White);
    if (V1.empty()) {
        screen -> draw_text(0,"[ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(0, V1, sf::Color(0, 255, 255)); //blue color;
    }

    //VR
    screen -> draw_text(7,"VR", sf::Color::White);
    if (VR.empty()) {
        screen -> draw_text(1,"[ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(1, VR, sf::Color(0, 255, 255)); //blue color;
    }

    //V2
    screen -> draw_text(8,"V2", sf::Color::White);
    if (V2.empty()) {
        screen -> draw_text(2,"[ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(2, V2, sf::Color(0, 255, 255)); //blue color;
    }

    //TRANS ALT
    screen -> draw_text(9,"TRANS  ALT", sf::Color::White);
    if (trans_alt.empty()) {
        screen -> draw_text(3,"[        ]", sf::Color(0, 255, 255)); //blue color;
    }
    else {
        screen -> draw_text(3, trans_alt, sf::Color(0, 255, 255)); //blue color;
    }

    //THR RED/ACC
    screen -> draw_text(10,"THR  RED / ACC", sf::Color::White);
    screen -> draw_text(4,"1341 / 1341", sf::Color(0, 255, 255)); //blue color;

    //ŚRODEK
    //FLP RETR
    screen -> draw_text(18,"FLP  RETR", sf::Color::White);
    screen -> draw_text(12,"F = 147", sf::Color::Green);

    //SLT RETR
    screen -> draw_text(19,"SLT  RETR", sf::Color::White);
    screen -> draw_text(13,"S = 191", sf::Color::Green);

    //CLEAN
    screen -> draw_text(20,"CLEAN", sf::Color::White);
    screen -> draw_text(14,"O = 216", sf::Color::Green);

    //PRAWA STRONA
    //TO SHIFT
    screen -> draw_text(31,"            TO  SHIFT", sf::Color::White);
    screen -> draw_text(25,"          [       ]*", sf::Color(0, 255, 255)); //blue color;

    //FLAPS/THS
    screen -> draw_text(32,"          FLAPS / THS", sf::Color::White);
    if (flaps.empty()) {
        screen -> draw_text(26,"    [   ] / [        ]", sf::Color(0, 255, 255)); //blue color;
    }
    else {
        screen -> draw_text(26, "       " + flaps + " / [        ]", sf::Color(0, 255, 255)); //blue color;
    }

    //FLEX TO TEMP
    screen -> draw_text(33,"        FLEX TO TEMP", sf::Color::White);
    if (flex.empty()) {
        screen -> draw_text(27,"          [       ]", sf::Color(0, 255, 255)); //blue color;
    }
    else {
        screen -> draw_text(27, "               " + flex, sf::Color(0, 255, 255)); //blue color;
    }

    //ENG OUT ACC
    screen -> draw_text(34,"        ENG OUT ACC", sf::Color::White);
    screen -> draw_text(28,"              1341", sf::Color(0, 255, 255)); //blue color;

    //INPUT
    screen -> draw_text(36,vector_to_string(performance_input), sf::Color::White);
}

//pobranie inputu
void Performance::getInput(int &button_clicked) {
    //wywołanie funkcji z klasy input
    get_input(button_clicked, performance_input);
    std::cout << "flt_init_input.size() = \n" << performance_input.size() << std::endl;
}

//wprowadzenie danych
void Performance::insert_data(int &button_clicked) {
    switch (button_clicked) {
        case 0:
            insert_into_V1_VR_V2(vector_to_string(performance_input), button_clicked);
            break;

        case 1:
            insert_into_V1_VR_V2(vector_to_string(performance_input), button_clicked);
            break;

        case 2:
            insert_into_V1_VR_V2(vector_to_string(performance_input), button_clicked);
            break;

        case 3:
            insert_into_trans(vector_to_string(performance_input));
            break;

        case 8:
            insert_into_flaps(vector_to_string(performance_input));
            break;

        case 9:
            insert_into_flex(vector_to_string(performance_input));
            break;

        default:
            break;
    }
}

void Performance::insert_into_V1_VR_V2(const std::string& input, int button_clicked) {
    if (input.empty()) {
        return;
    }

    if (input.size() != 3) {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    //konwersja na int
    int number;

    //wyjatki
    //TRY -> to co moze wyrzucic wyjatek po nieudanej próbie konwersji stringa na int
    try {
        size_t pos; //indeks pierwszego znaku po konwertowanej liczbie

        //proba zamiany
        number = std::stoi(input, &pos);

        //sprawdzenie, czy caly string zostal zamieniony na liczbe
        if (pos != input.length()) {
            throw std::invalid_argument("Niepełna konwersja");
        }

        //sprawdzenie zakresu liczby
        if (number < 100 || number > 200) {
            throw std::out_of_range("Poza zakresem");
        }

        //przypisanie wartości
        switch (button_clicked) {
            case 0:
                V1 = input;
                break;

            case 1:
                VR = input;
                break;

            case 2:
                V2 = input;
                break;

            default:
                break;
        }

        //wyczyszcenie inputu wektora
        performance_input.clear();
    }
    //w przypadku wystapienia bledu
    catch (...) {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
    }
}

void Performance::insert_into_trans(const std::string &input) {
    if (input.empty()) {
        return;
    }

    if (input.size() != 4) {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    //konwersja na int
    int number;

    //wyjatki
    //TRY -> to co moze wyrzucic wyjatek po nieudanej próbie konwersji stringa na int
    try {
        size_t pos; //indeks pierwszego znaku po konwertowanej liczbie

        //proba zamiany
        number = std::stoi(input, &pos);

        //sprawdzenie, czy caly string zostal zamieniony na liczbe
        if (pos != input.length()) {
            throw std::invalid_argument("Niepełna konwersja");
        }

        //sprawdzenie zakresu liczby
        if (number < 1000 || number > 10000) {
            throw std::out_of_range("Poza zakresem");
        }

        //przypisanie wartości
        trans_alt = input;

        //wyczyszcenie inputu wektora
        performance_input.clear();
    }
    //w przypadku wystapienia bledu
    catch (...) {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
    }
}

void Performance::insert_into_flaps(const std::string &input) {
    if (input.empty()) {
        return;
    }

    if (input.size() != 1) {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    if (input[0] != '1' && input[0] != '2' && input[0] != '3') {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    //przypisanie wartości
    flaps = input;

    std::cout<<"flaps = "<<flaps<<std::endl;

    //wyczyszcenie inputu wektora
    performance_input.clear();
}

void Performance::insert_into_flex(const std::string &input) {

    if (input.empty()) {
        return;
    }

    if (input.size() != 2) {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    //konwersja na int
    int number;

    //wyjatki
    //TRY -> to co moze wyrzucic wyjatek po nieudanej próbie konwersji stringa na int
    try {
        size_t pos; //indeks pierwszego znaku po konwertowanej liczbie

        //proba zamiany
        number = std::stoi(input, &pos);

        //sprawdzenie, czy caly string zostal zamieniony na liczbe
        if (pos != input.length()) {
            throw std::invalid_argument("Niepełna konwersja");
        }

        //sprawdzenie zakresu liczby
        if (number < 50 || number > 65) {
            throw std::out_of_range("Poza zakresem");
        }

        //przypisanie wartości
        flex = input;

        //wyczyszcenie inputu wektora
        performance_input.clear();
    }
    //w przypadku wystapienia bledu
    catch (...) {
        performance_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
    }
}
