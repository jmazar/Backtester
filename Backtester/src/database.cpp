#include "../include/database.h"
#include <stdio.h>

Database::Database() {
	
	if( SQLITE_OK == sqlite3_open("securities.db", &m_pDatabase) ) {
		printf("Database opened!\n");
	}
	sqlite3_stmt * statement;

	int rc = sqlite3_prepare_v2(m_pDatabase, "CREATE TABLE IF NOT EXISTS security_names ( id INT AUTO_INCREMENT, name TEXT);", -1, &statement, 0);

	printf("Return id %d\n", rc);
}

Database::~Database() {
	sqlite3_close(m_pDatabase);
}
