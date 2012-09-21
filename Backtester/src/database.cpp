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

std::vector<std::vector<std::string> > Database::ExecuteStatement(std::string const & in_statement) {
	int returnCode;
	std::vector<std::vector<std::string> > results;

	sqlite3_stmt * statement = NULL;

	returnCode = sqlite3_prepare_v2(m_pDatabase, in_statement.c_str(), -1, &statement, 0);
	if(SQLITE_OK == returnCode) {
		int cols = sqlite3_column_count(statement);
		while(true) {
			returnCode = sqlite3_step(statement);
			if(SQLITE_ROW == returnCode) {
				std::vector<std::string> values;
                for(int col = 0; col < cols; col++) {
                    values.push_back((char*)sqlite3_column_text(statement, col));
                }
                results.push_back(values);
			}
			else {
				break;
			}
		}

	}
	else {
		std::string error = sqlite3_errmsg(m_pDatabase);
		if(error != "not an error") 
			printf("%s\n", error.c_str());
	}

	sqlite3_finalize(statement);

	return results;
}
