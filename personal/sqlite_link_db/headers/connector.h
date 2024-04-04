#pragma once

#include "../lib/sqlite3.h"

namespace dbConnector {
sqlite3 *openDB(const char *dbPath);
}
