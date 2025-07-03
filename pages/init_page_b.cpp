#include "init_page_b.h"
#include "init_page.h"
#include "input.h"
#include <iostream>

//konstruktor
Init_Page_B::Init_Page_B(Screen *screen_ptr, Init_Page* init_page_ptr) {
    screen = screen_ptr;
    init_page = init_page_ptr;
}

//destruktor
Init_Page_B::~Init_Page_B() {

}

void Init_Page_B::render() {

    //wyciagniecie samego ZFW, czyli pierwszych 4 znaków
    std::string zfw = zfw_zfwcg.substr(0,4);

    //policzenie TOW gdy wymagane pola nie są puste
    if (!taxi.empty() && !zfw.empty() && !block_fuel.empty()) {

        double taxi_double = string_to_double(taxi);
        std::cout<<taxi_double<<std::endl;

        double zfw_double = string_to_double(zfw);
        std::cout<<zfw_double<<std::endl;

        double block_fuel_double = string_to_double(block_fuel);
        std::cout<<block_fuel_double<<std::endl;

        tow = std::to_string(tow_calculations(taxi_double, zfw_double, block_fuel_double)).substr(0,4);
    }

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("      INIT                   <- ->", sf::Color::White);

    //LEWA STRONA
    //TAXI
    taxi = "0.2";   //domyslna wartość
    screen -> draw_text(6, "TAXI", sf::Color::White);
    screen -> draw_text(0, taxi, sf::Color(0, 255, 255)); //blue color

    //TRIP/TIME
    screen -> draw_text(7, "TRIP/TIME", sf::Color::White);
    screen -> draw_text(1, "---.-/----", sf::Color::White);

    //RTE RSV/%
    screen -> draw_text(8, "RTE RSV/%", sf::Color::White);
    screen -> draw_text(2, "---.-/5.0", sf::Color::White);

    //ALTN/TIME
    screen -> draw_text(9, "ALTN/TIME", sf::Color::White);
    screen -> draw_text(3, "---.-/----", sf::Color::White);

    //FINAL TIME
    screen -> draw_text(10, "FINAL TIME", sf::Color::White);
    screen -> draw_text(4, "1.0/0030", sf::Color(0, 255, 255)); //blue color

    //MIN DEST FOB
    screen -> draw_text(11, "MIN DEST FOB", sf::Color::White);
    screen -> draw_text(5, "1.0", sf::Color(0, 255, 255)); //blue color


    //PRAWA STRONA
    //ZFW/ZWFCG
    screen -> draw_text(30, "       ZFW / ZFWCG", sf::Color::White);
    if (zfw_zfwcg.empty()) {
        screen -> draw_text(24, "   [ ][ ].[ ]/[ ][ ].[ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(24, "        " + zfw_zfwcg, sf::Color(0, 255, 255)); //blue color
    }

    //BLOCK
    screen -> draw_text(31, "                   BLOCK", sf::Color::White);
    if (block_fuel.empty()) {
        screen -> draw_text(25, "               [ ][ ].[ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(25, "               " + block_fuel, sf::Color(0, 255, 255)); //blue color
    }

    //TOW/LW
    screen -> draw_text(33, "          TOW  /     LW", sf::Color::White);
    if (tow.empty()) {
        screen -> draw_text(15, "                       --.-/ ", sf::Color::White);
    }
    else {
        screen -> draw_text(15, "                      " + tow, sf::Color::Green);
    }
    screen -> draw_text(27, "                --.-", sf::Color::White);

    //TRIP WIND
    screen -> draw_text(34, "             TRIP WIND", sf::Color::White);
    screen -> draw_text(28, "             ------", sf::Color::White);

    //EXTRA TIME
    screen -> draw_text(35, "        EXTRA / TIME", sf::Color::White);
    screen -> draw_text(29, "      ---.- / ----", sf::Color::White);

    //input uzytkownika
    screen -> draw_text(36, vector_to_string(init_page_b_input), sf::Color::White);

}

void Init_Page_B::input_handler(int button_clicked, Active_Screen& current_page) {
    if (button_clicked == 26) {
        init_page -> render();
        std::cout << "Init_Page_B" <<std::endl;
        current_page = Active_Screen::init_page;
    }
}

void Init_Page_B::getInput(int &button_clicked) {
    get_input(button_clicked, init_page_b_input);
    std::cout << "flt_init_input.size() = \n" << init_page_b_input.size() << std::endl;
}

void Init_Page_B::insert_data(int &button_clicked) {
    switch (button_clicked) {
        case 6:
            insert_into_zfw_zfwcg(vector_to_string(init_page_b_input));
        break;

        case 7:
            insert_into_block_fuel(vector_to_string(init_page_b_input));
        break;

        default:
            break;
    }
}

void Init_Page_B::insert_into_zfw_zfwcg(const std::string &input) {
    //Warunki sprawdzające poprawnośc wpisanych danych
    if (input.empty() || input.size() != 9) {
        init_page_b_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    if (input[2] != '.' || input[7] != '.') {
        init_page_b_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    for (int i=0; i<9; i++) {
        if (i == 2 || i == 4 || i == 7) {
            continue;
        }
        if (input[i] <'0' || input[i] > '9') {
            init_page_b_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
            return;
        }
    }
    zfw_zfwcg = input;

    //wyczyszcenie inputu wektora
    init_page_b_input.clear();
}

void Init_Page_B::insert_into_block_fuel(const std::string &input) {
    //Warunki sprawdzające poprawnośc wpisanych danych
    if (input.empty() || input.size() < 3 || input.size() > 4) {
        init_page_b_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    if (input[1] != '.' && input[2] != '.') {
        init_page_b_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    if (input.size() == 4) {
        for (int i=0; i<4; i++) {
            if (i == 2) {
                continue;
            }
            if (input[i] < '0' || input[i] > '9') {
                init_page_b_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                return;
            }
        }
    }
    else if (input.size() == 3) {
        if (input[0] < '0' || input[0] > '9' || input[2] < '0' || input[2] > '9') {
            init_page_b_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
            return;
        }
    }

    block_fuel = input;

    //wyczyszcenie inputu wektora
    init_page_b_input.clear();
}

double Init_Page_B::string_to_double(const std::string& input) {
    return std::stod(input);
}

double Init_Page_B::tow_calculations(double taxi, double zfw, double block) {
    return zfw + block - taxi;
}


