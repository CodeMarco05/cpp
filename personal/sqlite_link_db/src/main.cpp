#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>

#include "../headers/connector.h"
#include "../lib/sqlite3.h"

void createTable(sqlite3 *db, const char *tableName,
                 const char *specification) {
  char *errMsg = nullptr;
  int rc;

  char sql[256];
  snprintf(sql, 256, "CREATE TABLE IF NOT EXISTS %s (%s)", tableName,
           specification);

  // Execute SQL statement
  rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

  // handle error
  if (rc != SQLITE_OK) {
    std::cerr << "Error creating table: " << errMsg << std::endl;
    sqlite3_free(errMsg);
    sqlite3_close(db);
    exit(EXIT_FAILURE);
  }
}

int main() {

  const char *dbFilePath = "../db/database.db"; // Path to the database file
  sqlite3 *db = dbConnector::openDB(dbFilePath);

  const char *sqlString =
      "\"ID\" INTEGER NOT NULL UNIQUE, \"Name\" TEXT NOT NULL, \"Link\" TEXT "
      "NOT NULL, PRIMARY KEY(\"ID\" AUTOINCREMENT)";

  if (db == nullptr) {
    std::cerr << "Error opening database" << std::endl;
    return 1;
  }

  // why is this not working?
  const char *tableName = "Links";
  createTable(db, tableName, sqlString);

  // Close SQLite database connection
  sqlite3_close(db);

  return 0;
}
