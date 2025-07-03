#include "input.h"
#include <vector>
#include <iostream>

char letters[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '/'};

char numbers[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '0'};

std::vector<char> error_msg = {'F', 'O', 'R', 'M', 'A', 'T', ' ', 'E', 'R', 'R', 'O', 'R', '!'};

std::vector<char> not_in_data_base_msg = {'N', 'O', 'T', ' ', 'I', 'N', ' ', 'D', 'A', 'T', 'A', ' ', 'B', 'A', 'S', 'E', '!'};

void get_input(int &button_clicked, std::vector<char> &vector) {

    //sprawdzenie bledu
    if(button_clicked >= 30 && button_clicked <= 56) {
        vector.emplace_back(letters[button_clicked - 30]);
        std::cout<<"dodano znak "<<letters[button_clicked - 30] << " do input\n";
    }

    else if(button_clicked >= 60 && button_clicked <= 70) {
        vector.emplace_back(numbers[button_clicked - 60]);
        std::cout<<"dodano znak "<<numbers[button_clicked - 60] << " do input\n";
    }

    else if (button_clicked == 59) {
        if (vector == error_msg) {
            for (int i = 0; i < 13; i++) vector.pop_back();
        }
        else if (vector == not_in_data_base_msg) {
            for (int i = 0; i < 17; i++) vector.pop_back();
        }
        else if (!vector.empty()) {
            vector.pop_back();
        }
    }

    //button_clicked = -1;
}

std::string vector_to_string(const std::vector<char> &vector) {
    return std::string (vector.begin(), vector.end());
}
