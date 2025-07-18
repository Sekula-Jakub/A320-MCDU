//fmgc.h
//Renderuje ekran Fmgc

#ifndef FMGC_H
#define FMGC_H

#include "../screen.h"

class Fmgc {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

    public:
        //konstruktor
        Fmgc(Screen* screen_ptr);

        //destruktor
        ~Fmgc();

        //renderowanie
        void render() const;
};

#endif
