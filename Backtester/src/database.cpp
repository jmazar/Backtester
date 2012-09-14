#include "../include/database.h"
#include <stdio.h>

Database::Database() {
	
	if( SQLITE_OK == sqlite3_open("securities.db", &m_pDatabase) ) {
		printf("Database opened!\n");
	}

	ExecuteStatement("CREATE TABLE IF NOT EXISTS security_names ( id INTEGER PRIMARY KEY, name TEXT);");

	ExecuteStatement("CREATE TABLE IF NOT EXISTS securities ( id INTEGER PRIMARY KEY, name_id INTEGER, date TEXT, open REAL, close REAL, high REAL, low REAL, volume INTEGER);");
}

Database::~Database() {
	sqlite3_close(m_pDatabase);
}

int Database::ExecuteStatement(std::string const & in_statement) {
	int returnCode;

	sqlite3_stmt * statement = NULL;

	returnCode = sqlite3_prepare_v2(m_pDatabase, in_statement.c_str(), -1, &statement, 0);
	if(returnCode != SQLITE_OK)
	{
		printf("Return code %d\n", returnCode);
	}

	sqlite3_finalize(statement);

	return returnCode;
}
