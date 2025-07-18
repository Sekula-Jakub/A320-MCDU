//data_page.h
//Renderuje ekran Data, korzystając ze wskaźnika do obiektu klasy Screen

#ifndef DATA_PAGE_H
#define DATA_PAGE_H

#include "../screen.h"

class Data_Page {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

    public:
        //konstruktor
        Data_Page(Screen* screen_ptr);

        //KONSTRUKTOR KOPIUJĄCY
        Data_Page(const Data_Page& other);

        //destruktor
        ~Data_Page();

        void render() const;
};

#endif