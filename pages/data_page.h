//data_page.h
//Renderuje ekran Data, korzystając ze wskaźnika do obiektu klasy Screen

#ifndef DATA_PAGE_H
#define DATA_PAGE_H

#include "../screen.h"

class Data_Page {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

        friend class Screen;

    public:
        //konstruktor
        Data_Page(Screen* screen_ptr);

        //destruktor
        ~Data_Page();

        void render() const;
};

#endif