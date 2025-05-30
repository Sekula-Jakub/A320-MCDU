#pragma once
#include <string>
#include <../database_sqlite3_files/sqlite3.h>

class DatabaseManager {
    public:
        //konstruktor - otwieranie bazy
        DatabaseManager();

        //destruktor - zamykanie bazy
        ~DatabaseManager();

        //czy lotnisko jest w bazie
        bool airport_in_data_base(const std::string& icao_Code);

    private:
        sqlite3* db;  //wskaznik na baze danych
};
