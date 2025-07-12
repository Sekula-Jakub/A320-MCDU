#include "init_page.h"
#include <iostream>
#include <cmath> //do zaokrąglenia temperatury
#include "input.h"

//konstruktor
Init_Page::Init_Page(Screen* screen_ptr, Flt_Init* flt_init_ptr) {
    screen = screen_ptr;
    flt_init = flt_init_ptr;

    //Zaalokowanie pamieci na podstrone
    init_page_b = new Init_Page_B(screen, this);
}

//destruktor
Init_Page::~Init_Page() {
    delete init_page_b;
}

void Init_Page::render() {

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("                              INIT A                  <- ->", sf::Color::White);

    //LEWA STRONA
    //CO RTE
    screen -> draw_text(6, "CO RTE", sf::Color::White);
    if (co_rte.empty()) {
        screen -> draw_text(0, "[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(0, co_rte, sf::Color(0, 255, 255)); //blue color;
    }

    //ALTN
    screen -> draw_text(7, "ALTN / CO RTE", sf::Color::White);
    if (alternative.empty()) {
        screen -> draw_text(1, "----/----------", sf::Color::White);
    }
    else {
        screen -> draw_text(1, alternative, sf::Color(0, 255, 255));//blue color
    }

    //FLT NBR
    screen -> draw_text(8, "FLT NBR", sf::Color::White);
    if (flt_number.empty()) {
        screen -> draw_text(2, "[ ][ ][ ][ ][ ][ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else {
        screen -> draw_text(2, flt_number, sf::Color(0, 255, 255)); //blue color
    }

    //COST INDEX
    screen -> draw_text(10, "COST INDEX", sf::Color::White);
    if (init_request_pressed == true && cost_index.empty()) {
        screen -> draw_text(4, "[ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else if (init_request_pressed == true && !cost_index.empty()) {
        screen -> draw_text(4, cost_index, sf::Color(0, 255, 255)); //blue color
    }
    else {
        screen -> draw_text(4, "---", sf::Color::White);
    }

    //CRZ FL
    screen -> draw_text(11, "CRZ FL / TEMP", sf::Color::White);
    if (init_request_pressed == true && crz_fl.empty()) {
        screen -> draw_text(5, "[ ][ ][ ][ ] / [ ][ ][ ]", sf::Color{255, 153, 0}); //orange color
    }
    else if (init_request_pressed == true && !crz_fl.empty()) {
        screen -> draw_text(5, crz_fl, sf::Color(0, 255, 255)); //blue color
    }
    else {
        screen -> draw_text(5, "------ /---", sf::Color::White);
    }

    //PRAWA STRONA
    //FROM/TO
    screen -> draw_text(30, "FROM / TO", sf::Color::White);
    if (from_to.empty()) {
        screen -> draw_text(24, "[ ][ ][ ][ ]/[ ][ ][ ][ ]", sf::Color{255, 153, 0});
    }
    else {
        screen -> draw_text(24, from_to, sf::Color(0, 255, 255));
    }

    //INIT REQUEST
    if (init_request_pressed == false) {
        screen -> draw_text(31, "                       INIT", sf::Color{255, 153, 0});
        screen -> draw_text(25, "       REQUEST*", sf::Color{255, 153, 0});
    }

    screen -> draw_text(26, "          IRS INIT>", sf::Color::White);
    screen -> draw_text(27, "              WIND>", sf::Color::White);
    screen -> draw_text(34, "                     TROPO", sf::Color::White);
    screen -> draw_text(28, "             36090", sf::Color(0, 255, 255));
    screen -> draw_text(35, "               GND TEMP", sf::Color::White);
    screen -> draw_text(29, "                   ---", sf::Color::White);

    //input uzytkownika
    screen -> draw_text(36, vector_to_string(init_page_input), sf::Color::White);
}

//init request - pobranie wczesniej wprowadzoncyh danych ze strony Flt Init
void Init_Page::init_request(int button_clicked) {
    std::cout<<"Oto metoda init_request"<<std::endl;
    if (button_clicked == 7) {
        std::cout<<"Kliknieto dobry przycisk"<<std::endl;
        if (!flt_init->dep.empty() && !flt_init->dest.empty() && !flt_init->altn.empty()) {
            std::cout<<"jest OK"<<std::endl;
            co_rte = "NONE";
            std::cout<<co_rte<<std::endl;
            alternative = flt_init -> altn;
            std::cout<<alternative<<std::endl;
            from_to = flt_init -> dep + '/' + flt_init -> dest;
            from = flt_init -> dep;
            to = flt_init -> dest;
            std::cout<<from_to<<std::endl;
            init_request_pressed = true;
        }
    }
}

void Init_Page::getInput(int &button_clicked) {
    get_input(button_clicked, init_page_input);
    std::cout << "flt_init_input.size() = \n" << init_page_input.size() << std::endl;
}

void Init_Page::insert_data(int &button_clicked) {
    switch (button_clicked) {
        case 2:
            insert_into_flt_number(vector_to_string(init_page_input));
            break;

        case 4:
            insert_into_cost_index(vector_to_string(init_page_input));
            break;

        case 5:
            insert_into_crz_fl(vector_to_string(init_page_input));
            break;

        default:
            break;
    }
}

void Init_Page::insert_into_flt_number(const std::string& input) {
    if (input.empty()) {
        return;
    }

    if (input.size() <= 3 && input.size() > 0) {
        init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    if (input.size() >=3 && input.size() <=7) {
        for (int i=0; i<3; i++) {
            if (input[i] <'A' || input[i] > 'Z') {
                init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                return;
            }
        }
        for (int i=3; i<input.size(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                return;
            }
        }
    }

    if (input.size() > 7) {
        init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
        return;
    }

    flt_number = input;
    std::cout << "[DEBUG] Zapisywanie flt_number: " << input << std::endl;

    //wyczyszcenie inputu wektora
    init_page_input.clear();
}

//walidowanie danych do cost_index
void Init_Page::insert_into_cost_index(const std::string& input) {

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
        if (number < 1 || number > 999) {
            throw std::out_of_range("Poza zakresem");
        }

        //przypisanie wartości
        cost_index = input;

        //wyczyszcenie inputu wektora
        init_page_input.clear();
    }
    //w przypadku wystapienia bledu
    catch (...) {
        init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
    }
}

//walidacja danych do crz_fl (cruise flight level)
void Init_Page::insert_into_crz_fl(const std::string& input) {

    //flight level jako liczba całkowita
    int fl_integer;

    //jesli input zaczyna sie od FL (np. FL210), to jest OK i można działać dalej
    if (input[0] =='F' && input[1] =='L') {

        if (input.size() > 5) {
            init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
            return;
        }

        for (int i=2; i<input.size(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                return;
            }
        }

        //nowy string od 2 znaku inputa potrzebny do konwersji
        std::string nowy = input.substr(2);
        fl_integer = std::stoi(nowy);

        //warunek flight level
        if(fl_integer > 0 && fl_integer <= 390) {
            crz_fl = input + " / " + temperature_conversion(fl_integer);
        }
        else {
            init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
            return;
        }
    }

    else {
        if (input.size() > 3) {
            init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
            return;
        }
        else {
            for (int i=0; i<input.size(); i++) {
                if (input[i] < '0' || input[i] > '9') {
                    init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                    return;
                }
            }

            if(stoi(input) > 0 && stoi(input) <= 390) {
                crz_fl = "FL" + input + " / " + temperature_conversion(stoi(input));
            }
            else {
                init_page_input = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};
                return;
            }
        }
    }

    //wyczyszcenie inputu wektora
    init_page_input.clear();
}

//wyliczenie przybliżonej temperatury na odpowiedniej wysokości przelotowej
//FL(Flight Level) 210 oznacza  wysokość 21000 ft
std::string Init_Page::temperature_conversion(int flight_level) {

    const double temp_sea_level = 15.0;
    const double temp_decrease = 0.0065;    //spadek temperatury na jeden metr

    //zamiana z FL na metry
    float attutude_meters = flight_level * 100 * 0.3048;

    int temp = round(temp_sea_level - temp_decrease * attutude_meters);
    return std::to_string(temp);
}

void Init_Page::input_handler(int button_clicked, Active_Screen& current_page) const {
    if (button_clicked == 28) {
        init_page_b -> render();
        std::cout << "Init_page_B" <<std::endl;
        current_page = Active_Screen::init_page_b;
    }
}

//gettery, żeby nie robić danych public
std::string Init_Page::getFltNumber() {
    return flt_number;
}

std::string Init_Page::getDep() {
    return from;
}

std::string Init_Page::getDest() {
    return to;
}

bool Init_Page::getIsFilled() const {
    if (!flt_number.empty() && !from.empty() && !to.empty()) {
        return true;
    }
    return false;
}



