#ifndef FLT_INIT_H
#define FLT_INIT_H

#include "../data_base_manager.h"
#include "../screen.h"
#include <string>
#include <vector>

class Flt_Init {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        //input jako string
        std::string input_string;

        //klasa zaprzyjaźniona, żeby Init_Page mógł pobrać wpisane we Flt_Init dane
        friend class Init_Page;

        //parametry
        std::string flt_no;
        std::string dep;
        std::string dest;
        std::string altn;
        std::string ete;

        DatabaseManager db; //baza danych

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

        //zatwierdzenie danych
        void insert_data(int &button_clicked);

        //wstawianie w pole wektora z inputu
        void insert_into_flt_no(const std::string& input);

        void insert_into_dep(const std::string& input);

        void insert_into_dest(const std::string& input);

        void insert_into_altn(const std::string& input);

        void insert_into_ete(std::string& input);
};

#endif