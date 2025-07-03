#include "data_base_manager.h"
#include <iostream>
#include "database_sqlite3_files/sqlite3.h"

//konstruktor
DatabaseManager::DatabaseManager() {
    //Ścieżka do pliku bazy danych
    const std::string dbPath = "database.db";

    //
    if (sqlite3_open(dbPath.c_str(), &db)) {        // .c_str -> metoda zwracająca wskaźnik na tablicę znaków zakończoną znakiem '\0'
        std::cout<<"Can't open database "<<std::endl;
        std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr; //wskaznik na null w razie niepowodzenia otwarcia
    }
}

//desktruktor
DatabaseManager::~DatabaseManager() {
    if (db) {
        sqlite3_close(db);  //zamkniecie bazy
    }
}

//czy lotnisko w bazie danych
bool DatabaseManager::airport_in_data_base(const std::string& icaoCode) const {

    //sprawdzenie czy baza danych jest poprawnie otwarta
    if (!db) {
        return false;
    }

    //wskaznik na zapytanie SQL
    sqlite3_stmt* stmt = nullptr;

    //zapytanie SQL: Ilosc rekordow z tabeli airports gdzie code = podany kod
    const char* sql = "SELECT COUNT(*) FROM airports WHERE code = ?";

    //Przygotowanie zapytania SQL
    //argument -1 oznacza, że SQlite ma sam obliczyć długośc zapytania
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        //w razie niepowodzenia przygotowania zapytania
        return false;
    }

    //Podstawienie wartości kodu lotniska do zapytania
    //stmt - przygotowany wskaznik na zapytanie
    //1 - numer parametru (pierwszy ? w zapytaniu)
    ///icaoCode.c_str() - C-string z kodem lotniska
    //-1 - dlugosc tekstu. -1 oznacza, ze SQlite sam obliczy dlugosc (tekst konczy sie '\0')
    //SQLITE_TRANSIENT - SQlite robi sobie kopie danych
    sqlite3_bind_text(stmt, 1, icaoCode.c_str(), -1, SQLITE_TRANSIENT);

    //czy istnieje rekord
    bool exists = false;

    if (sqlite3_step(stmt) == SQLITE_ROW) {             //wykonanie zapytania SELECT
        if ( sqlite3_column_int(stmt, 0) > 0) {     //odczytanie pierwszej kolumny
            exists = true;                              //Jesli > 0 to lotnisko istnieje
        }
    }

    //zwolnienie zasobów związanych z zapytaniem
    sqlite3_finalize(stmt);

    //zwrócić wynik
    return exists;
}
