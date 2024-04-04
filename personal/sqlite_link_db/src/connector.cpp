#include "../headers/connector.h"

#include "../lib/sqlite3.h"
#include <iostream>

namespace dbConnector {
sqlite3 *openDB(const char *dbPath) {

  sqlite3 *db;
  int rc = sqlite3_open(dbPath, &db);

  if (rc) {
    std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    return nullptr;
  }

  return db;
}
} // namespace dbConnector
