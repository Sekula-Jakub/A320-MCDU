#pragma once

class Screen;

class Atsu {
private:
    Screen* screen;    //wskaznik do obiektu klasy Screen

public:

    bool active = false;

    //konstruktor
    explicit Atsu(Screen* screen_ptr);

    //destruktor
    ~Atsu();

    //renderowanie
    void render() const;
};

