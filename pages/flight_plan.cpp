//flight_plan.cpp
//Implementacja klasy Flight_Plan

#include "flight_plan.h"
#include <iostream>
#include "init_page.h"
#include "../data_base_manager.h"
#include <cmath>
#include "departure_page_a.h"
#include "arrival_page_a.h"

//konstruktor
Flight_Plan::Flight_Plan(Screen* screen_ptr, Init_Page* init_page_ptr) {
    screen = screen_ptr;
    init_page = init_page_ptr;

    //zaalokowanie pamieci na podstrony
    departure_page_a = new Departure_Page_A(screen, this);
    arrival_page_a = new Arrival_Page_A(screen, this);

    dep_runway = {};
    arr_runway = {};
}

//destruktor
Flight_Plan::~Flight_Plan() {
    delete departure_page_a;
    delete arrival_page_a;
}

//Przed uzupelnieniem init page
void Flight_Plan::render_empty() {
    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //komunikat o wymogach przed wypełnieniem tej strony
    screen -> draw_text(2, "      Please fill the INIT A page before", sf::Color::Red);
    screen -> draw_text(3, "            filling the Flight Plan page", sf::Color::Red);
}

//po uzupelnieniu init page
void Flight_Plan::render_ready() {

    //przypisanie wartości do departure i arrival
    departure = init_page -> getDep();
    arrival = init_page -> getDest();

    coordinates_dep = get_coordinates(departure);
    coordinates_arr = get_coordinates(arrival);

    std::cout<<coordinates_dep<<std::endl;

    //wyczyszczenie poprzednich wartosci
    screen -> draw_title("", sf::Color::White);

    //wyczyszczenie napisow
    for (int i=0; i<37; i++) {
        screen -> draw_text(i,"", sf::Color::White);
    }

    //tytuł
    screen -> draw_title("                       " + init_page -> getFltNumber() + "                          <- ->", sf::Color::White);

    //LEWA STRONA
    //DEP
    screen -> draw_text(6, "FROM", sf::Color::White);
    screen -> draw_text(0, departure + dep_runway, sf::Color::Green);

    screen -> draw_text(1, " - - - F - P L N   D I S O N T I N U I T Y - - ", sf::Color::White);

    //DEST
    screen -> draw_text(11, "DEST", sf::Color::White);
    screen -> draw_text(5, arrival + arr_runway, sf::Color::Green);

    //ŚRODEK
    //DEP TIME
    screen -> draw_text(18, "TIME", sf::Color::White);
    screen -> draw_text(12, "----", sf::Color::White);

    //DEST TIME
    screen -> draw_text(23, "TIME", sf::Color::White);
    screen -> draw_text(17, "----", sf::Color::White);

    //PRAWA STRONA
    //SPD/ALT
    screen -> draw_text(30, "SPD   /   ALT", sf::Color::White);
    screen -> draw_text(24, "---   /   ------", sf::Color::White);

    //DIST
    screen -> draw_text(35, "DIST           EFOB", sf::Color::White);
    screen -> draw_text(29, get_distance() + "   ------", sf::Color::White);
}

void Flight_Plan::input_handler(int button_clicked, Active_Screen& current_page) {
    if (button_clicked == 0) {
        departure_page_a -> render();
        current_page = Active_Screen::departure_page_a_page;
    }
    else if (button_clicked == 5) {
        arrival_page_a -> render();
        current_page = Active_Screen::arrival_page_a_page;
    }
}

std::string Flight_Plan::get_coordinates(const std::string &icaoCode) const {
    return db.get_coordinates_from_data_base(icaoCode);
}

double Flight_Plan::get_latitude(std::string coordinates) {
    std::string latitude = coordinates.substr(0,8);

    int degrees = std::atoi(latitude.substr(0,2).c_str());
    int minutes = std::atoi(latitude.substr(2,2).c_str());
    int seconds = std::atoi(latitude.substr(4,2).c_str());
    char direction = latitude[6]; //N lub S

    //zamiana na stopnie dziesiętne
    double decimal_latitude = degrees + minutes/60.0 + seconds/3600.0;

    //kierunek S lub N
    if (direction == 'S') {
        //jesli poludniowy to odwrocic znak
        decimal_latitude *= -1;
    }

    return decimal_latitude;
}

double Flight_Plan::get_longitude(std::string coordinates) {
    std::string longitude = coordinates.substr(8,8);

    int degrees = std::atoi(longitude.substr(0,3).c_str());
    int minutes = std::atoi(longitude.substr(3,2).c_str());
    int seconds = std::atoi(longitude.substr(5,2).c_str());
    char direction = longitude[7];  //E lub W

    double decimal_longitude = degrees + minutes/60.0 + seconds/3600.0;

    //kierunek E lub W
    if (direction == 'W') {
        //odwrocenie znaku
        decimal_longitude *= -1;
    }

    return decimal_longitude;
}

double Flight_Plan::calculate_distance() {
    //pobranie lotnisk dep i dest z init_page
    const std::string dep = init_page -> getDep();
    const std::string dest = init_page -> getDest();

    //wywołanie funkcji z data_base_manager do znajdowania koordynatów lotnisk o podanym kodzie
    std::string coordinates_dep = get_coordinates(dep);
    std::string coordinates_dest = get_coordinates(dest);

    //kordynaty departure: latitude i longitude
    double lat1 = get_latitude(coordinates_dep);
    double lon1 = get_longitude(coordinates_dep);

    //koordynaty destination: latitude i longitude
    double lat2 = get_latitude(coordinates_dest);
    double lon2 = get_longitude(coordinates_dest);

    //promień Ziemi w milach morskich (NM Nautical Miles)
    double R = 3440.1;

    //Róznice w stopniach potrzebna do wzoru
    double d_lat = (lat2 - lat1) * M_PI / 180.0;
    double d_lon = (lon2 - lon1) * M_PI / 180.0;

    //Zamiana szerokości geograficznej na radiany
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    //Wzór Haversine'a
    //przy pomocy: https://www.geeksforgeeks.org/dsa/haversine-formula-to-find-distance-between-two-points-on-a-sphere/
    double a = std::pow(std::sin(d_lat / 2), 2) + std::pow(std::sin(d_lon / 2), 2) * std::cos(lat1) * std::cos(lat2);

    double c = 2 * std::asin(std::sqrt(a));     //asin - arcus sinus

    return R * c;
}

std::string Flight_Plan::get_distance() {
    double d = calculate_distance();
    //zamiana d na string zaokrąglony do czesci calkowitej
    return std::to_string(static_cast<int>(d));
}
