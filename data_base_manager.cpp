#include "data_base_manager.h"
#include <iostream>
#include "database_sqlite3_files/sqlite3.h"

DatabaseManager::DatabaseManager() {
    const std::string dbPath = "database.db";
    if (sqlite3_open(dbPath.c_str(), &db)) {
          std::cout<<"Can't open database "<<std::endl;
        std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
}

DatabaseManager::~DatabaseManager() {
    if (db) {
        sqlite3_close(db);
    }
}

bool DatabaseManager::airport_in_data_base(const std::string& icaoCode) {

    //sprawdzenie czy baza jest otwarta
    if (!db) {
        return false;
    }

    //wskaznik na zapytanie SQL
    sqlite3_stmt* stmt = nullptr;
    const char* sql = "SELECT COUNT(*) FROM airports WHERE code = ?";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt, 1, icaoCode.c_str(), -1, SQLITE_TRANSIENT);

    bool exists = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        exists = sqlite3_column_int(stmt, 0) > 0;
    }

    sqlite3_finalize(stmt);
    return exists;

}
