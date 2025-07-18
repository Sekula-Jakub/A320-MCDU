//input.h
//Klasa obslugujaca wprowadzanie inputu przez użytkownika

#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

//pobieranie i dodawanie do wektora
void get_input(int &button_clicked, std::vector<char> &vector);

//konwersja wektora na string
std::string vector_to_string(const std::vector<char> &vector);

#endif