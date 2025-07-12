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
bool DatabaseManager::airport_in_data_base(const std::string& icao_code) const {

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
    sqlite3_bind_text(stmt, 1, icao_code.c_str(), -1, SQLITE_TRANSIENT);

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

std::string DatabaseManager::get_coordinates_from_data_base(const std::string& icao_code) const {
    //sprawdzenie czy baza danych jest otwarta
    if (!db) {
        return "";
    }

    //Przygotowanie wskaźnika na zapytanie SQL
    sqlite3_stmt* stmt = nullptr;

    //Przygotowanie zapytanie: Pobranie kolumny 'coordinates' dla danego kodu lotniska
    //argument -1 oznacza, że SQlite ma sam obliczyć długośc zapytania
    if (sqlite3_prepare_v2(db, "SELECT coordinates FROM airports WHERE code = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        //w razie niepowodzenia przygotowania zapytania
        return "";
    }

    //podstawienie kodu lotniska do zapytania w miejsce '?'
    sqlite3_bind_text(stmt, 1, icao_code.c_str(), -1, SQLITE_TRANSIENT);

    std::string coordinates;

    //wykonanie zapytanie i sprawdzenie czy istnieje rekord
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        coordinates = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }

    //zwolnienie zasobów związanych z zapytaniem
    sqlite3_finalize(stmt);

    return coordinates;
}

std::vector<std::string> DatabaseManager::get_runway_numbers_from_data_base(const std::string& icao_code) const {
    //pusty wektor na wyniki
    std::vector<std::string> runway_numbers = {};

    //sprawdzanie czy baza danych jest otwarta
    if (!db) {
        //jesli nie zwrocenie pustego wektora
        return runway_numbers;
    }

    //wskaźnik do przygotowanego zapytania
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "SELECT runways.runway_number FROM runways JOIN airports ON runways.airport_id = airports.id WHERE airports.code = ?";

    // Przygotowanie zapytania SQL:
    // sqlite3_prepare_v2 kompiluje zapytanie do postaci binarnej
    // - db: połączenie z bazą
    // - sql: tekst zapytania
    // - -1: automatyczne obliczenie długości zapytania
    // - &stmt: wskaźnik do przygotowanego wyrażenia
    // - nullptr: nieużywany wskaźnik do nieprzetworzonej części zapytania
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        //zwrocenie pustego wektora
        return runway_numbers;
    }

    // Wiążemy parametr zapytania (?) z wartością:
    // - stmt: przygotowane wyrażenie
    // - 1: indeks parametru (pierwszy i jedyny ? w naszym zapytaniu)
    // - icao_code.c_str(): wartość kodu ICAO jako C-string
    // - -1: długość stringa (automatyczna)
    // - SQLITE_TRANSIENT: SQLite musi skopiować wartość
    sqlite3_bind_text(stmt, 1, icao_code.c_str(), -1, SQLITE_TRANSIENT);

    //zapytanie w pętli dla każdego wiersza wyniku
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        //pobranie tekstu z 1 kolumny wyniku, czyli o indeksie 0
        const unsigned char *result = sqlite3_column_text(stmt, 0);

        //jesli wynik nie jest null
        if (result != nullptr) {
            runway_numbers.emplace_back(reinterpret_cast<const char*>(result));
        }
    }
    sqlite3_finalize(stmt);

    //zwrocenie numerow pasów
    return runway_numbers;
}
