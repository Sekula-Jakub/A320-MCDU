#pragma once

class Screen;

class Atsu {
    private:
        Screen* screen;    //wskaznik do obiektu klasy Screen

    public:
        //konstruktor
        Atsu(Screen* screen_ptr);

        void render() const;
};

