#pragma once
#include "screen.h"
#include "weather_req.h"

class Wx {
    private:
    Screen* screen;

    public:
    //podstrony
    Weather_req* weather_req;

    //konstruktor
    Wx(Screen* screen);

    //destruktor
    ~Wx();

    //renderowanie
    void render() const;

    void input_handler(int button_clicked, Active_Screen& current_page);
};

