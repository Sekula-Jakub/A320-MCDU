# ifndef DBMANAGER_H
# define DBMANAGER_H

#include <string>
#include <../database_sqlite3_files/sqlite3.h>
#include <vector>

class DatabaseManager {
    public:
        //konstruktor - otwieranie bazy
        DatabaseManager();

        //destruktor - zamykanie bazy
        ~DatabaseManager();

        //czy lotnisko jest w bazie
        bool airport_in_data_base(const std::string& icao_Code) const;

        //znajdź koordynaty lotniska
        std::string get_coordinates_from_data_base(const std::string& icao_Code) const;

        //wyszukaj dostepne pasy startowe
        std::vector<std::string> get_runway_numbers_from_data_base(const std::string& icao_Code) const;

    private:
        sqlite3* db;  //wskaznik na baze danych
};

#endif