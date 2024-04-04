#include "sqlite/sqlite3.h"
#include <iostream>

int main() {

  sqlite3 *db;
  char *errMsg = nullptr;
  const char *dbFilePath = "db/example.db"; // Path to the database file

  // Open SQLite database connection
  int rc = sqlite3_open(dbFilePath, &db);
  if (rc != SQLITE_OK) {
    std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db)
              << std::endl;
    sqlite3_close(db);
    return 1;
  }

  // Create a table (if not exists)
  const char *sqlCreateTable =
      "CREATE TABLE IF NOT EXISTS MyTable (ID INTEGER PRIMARY KEY, Name TEXT);";
  rc = sqlite3_exec(db, sqlCreateTable, nullptr, nullptr, &errMsg);
  if (rc != SQLITE_OK) {
    std::cerr << "Error creating table: " << errMsg << std::endl;
    sqlite3_free(errMsg);
    sqlite3_close(db);
    return 1;
  }

  std::cout << "SQLite database created successfully in ./db" << std::endl;

  // Close SQLite database connection
  sqlite3_close(db);

  return 0;
}
