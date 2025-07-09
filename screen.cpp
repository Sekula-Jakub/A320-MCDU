#include <SFML/Graphics.hpp>
#include "headers/screen.h"
#include <iostream>
#include "pages/mcdu_menu.h"
#include "pages/data_page.h"
#include "pages/init_page.h"
#include "pages/flight_plan.h"

//konstruktor
Screen::Screen() {

    mcdu_menu = new Mcdu_Menu(this);
    data_page = new Data_Page(this);
    init_page = new Init_Page(this, mcdu_menu -> atsu -> aoc_menu -> flt_init);
    flight_plan = new Flight_Plan(this, init_page);

    Active_Screen current_page = Active_Screen::null;

    //wczytanie czcionki
    if (font.loadFromFile("fonts/Inter_24pt-Regular.ttf") == false) {
        std::cerr << "Error loading font" << std::endl;
    }

    //wczytanie strzalki
    if (!arrow_tekstura.loadFromFile("assets/arrow_4.png")) {
        printf("Error loading arrow_icon.png\n");
        exit(1);
    }

    //tytul strony
    page_title.setFont(font);
    page_title.setCharacterSize(13);
    page_title.setFillColor(sf::Color::White);
    page_title.setPosition(100, 26);

    //teksty glowne
    for (int i = 0; i < 37; i++) {
        texts[i].setFont(font);
        //texts[i].setString("dupa");
        texts[i].setFillColor(sf::Color::White);
    }

    //===========LEWA STRONA===========
    //main texts
    float startX = 90, startY = 48;

    for (int i = 0; i < 6; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(14);
        startY += 35;
    }
    //upper_texts
    startX = 90, startY = 40;

    for (int i = 6; i < 12; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(10);
        startY += 35;
    }

    //===========ŚRODEK===========
    //pozycja tekstow na środku
    startX = 200;
    startY = 48;

    for (int i = 12; i < 18; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(14);
        startY += 35;
    }

    //upper_texts na srodku
    startX = 200;
    startY = 40;

    for (int i = 18; i < 24; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(10);
        startY += 35;
    }

    //===========PRAWA STRONA===========
    //pozycja tekstow z prawej strony
    startX = 260;
    startY = 48;

    for (int i = 24; i < 30; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(14);
        startY += 35;
    }

    //upper_texts z prawej
    startX = 260;
    startY = 40;

    for (int i = 30; i < 36; i++) {
        texts[i].setPosition(startX, startY);
        texts[i].setCharacterSize(10);
        startY += 35;
    }

    //===========DOLNY INPUT============
    texts[36].setPosition(92, 237);
    texts[36].setCharacterSize(14);
}

//destruktor
Screen::~Screen() {
    delete mcdu_menu;
    mcdu_menu = nullptr;
}

void Screen::draw_text(int index, const std::string &text, sf::Color color) {
    //obsluga bledu
    if (index > 36 || index < 0) {
        return;
    }
    texts[index].setString(text);
    texts[index].setColor(color);
}

void Screen::draw_title(const std::string text, sf::Color color) {
        page_title.setString(text);
        page_title.setColor(color);
}

void Screen::display_screen(sf::RenderWindow &window, int& button_clicked) {

    //MCDU MENU PAGE
    if (button_clicked == 23 && current_page != Active_Screen::mcdu_menu_page) {
        button_clicked = -1;
        current_page = Active_Screen::mcdu_menu_page;
        mcdu_menu -> render();
        std::cout << "mcdu menu" <<std::endl;
    }

    //DATA PAGE
    if (button_clicked == 16 && current_page != Active_Screen::data_page) {
        button_clicked = -1;
        data_page -> render();
        current_page = Active_Screen::data_page;
    }

    //FLIGHT PLAN
    if (button_clicked == 18 && current_page != Active_Screen::flight_plan_page) {
        std::cout<<"Flight Plan klikniety"<<std::endl;
        if (init_page -> getIsFilled() == false) {
            flight_plan -> render_empty();
        }
        else {
            flight_plan -> render_ready();

        }
        button_clicked = -1;
        current_page = Active_Screen::flight_plan_page;
    }

    //INIT PAGE
    if (button_clicked == 15 && current_page != Active_Screen::init_page) {
        button_clicked = -1;
        init_page -> render();
        current_page = Active_Screen::init_page;
    }

    //DEPARTURE_A PAGE ON FLIGHT PLAN PAGE
    if (current_page == Active_Screen::flight_plan_page && button_clicked != -1 && init_page -> getIsFilled() == true) {
        std::cout<<"dep klikniety"<<std::endl;
        flight_plan -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    //DEPARTURE PAGE A
    if (current_page == Active_Screen::departure_page_a_page) {
        flight_plan -> departure_page_a -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    //ARRIVAL PAGE A
    if (current_page == Active_Screen::arrival_page_a_page) {
        flight_plan -> arrival_page_a -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    //INIT RREQUEST ON INIT PAGE
    if (current_page == Active_Screen::init_page && button_clicked != -1) {
        init_page -> init_request(button_clicked);
        init_page -> getInput(button_clicked);
        if (init_page -> init_request_pressed == true) {
            init_page -> insert_data(button_clicked);
        }
        init_page -> render();
        init_page -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    //INIT PAGE B
    if (current_page == Active_Screen::init_page_b && button_clicked != -1) {
        init_page -> init_page_b -> input_handler(button_clicked, current_page);
        init_page -> init_page_b -> getInput(button_clicked);
        init_page -> init_page_b -> insert_data(button_clicked);
        if (button_clicked != 26) {
            init_page -> init_page_b -> render();
        }
        button_clicked = -1;
    }

    //MCDU MENU PAGE - PODMENU
    if (current_page == Active_Screen::mcdu_menu_page && button_clicked != -1) {
        mcdu_menu -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    if (current_page == Active_Screen::atsu_menu_page) {
        mcdu_menu -> atsu -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    if (current_page == Active_Screen::aoc_menu_page) {
        mcdu_menu -> atsu -> aoc_menu -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    if (current_page == Active_Screen::flt_init_page) {
        if (button_clicked != -1) {
            std::cout<<"wchodze\n";
            mcdu_menu -> atsu -> aoc_menu -> flt_init -> getInput(button_clicked);
            mcdu_menu -> atsu -> aoc_menu -> flt_init -> insert_data(button_clicked);
            mcdu_menu -> atsu -> aoc_menu -> flt_init -> render();
            button_clicked = -1;
        }
        //std::cout<<"button_clicked: "<<button_clicked<<std::endl;
    }

    if (current_page == Active_Screen::wx_page) {
        mcdu_menu -> atsu -> aoc_menu -> wx -> input_handler(button_clicked, current_page);
        button_clicked = -1;
    }

    if (current_page == Active_Screen::weather_request_page) {
        if (button_clicked != -1) {
            mcdu_menu -> atsu -> aoc_menu -> wx -> weather_req -> input_handler(button_clicked, current_page);
            mcdu_menu -> atsu -> aoc_menu -> wx -> weather_req -> getInput(button_clicked);
            mcdu_menu -> atsu -> aoc_menu -> wx -> weather_req -> insert_data(button_clicked);
            mcdu_menu -> atsu -> aoc_menu -> wx -> weather_req -> render();
        }
        button_clicked = -1;
    }

    //wypisane zupdatowanych napisow
    window.draw(page_title);

    for(int i=0; i<37; i++) {
        window.draw(texts[i]);
    }
}
