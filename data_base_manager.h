# ifndef DBMANAGER_H
# define DBMANAGER_H

#include <string>
#include <../database_sqlite3_files/sqlite3.h>
#include <vector>

struct Runway_Data {
    std::string number;
    std::string length;
};

class DatabaseManager {
    private:
        sqlite3* db;  //wskaznik na baze danych

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
        std::vector<Runway_Data> get_runway_data_from_data_base(const std::string& icao_Code) const;

};

#endif