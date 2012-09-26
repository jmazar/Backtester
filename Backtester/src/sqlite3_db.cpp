#include "../include/sqlite3_db.h"
#include <stdio.h>

/// PUBLIC INTERFACE 

Sqlite3_DB::Sqlite3_DB() {
	
	if( SQLITE_OK == sqlite3_open("securities.db", &m_pDatabase) ) {
		printf("Sqlite3_DB opened!\n");
	}

	ExecuteStatement("CREATE TABLE IF NOT EXISTS security_names ( id INTEGER PRIMARY KEY, name TEXT);");

	ExecuteStatement("CREATE TABLE IF NOT EXISTS securities ( id INTEGER PRIMARY KEY, name_id INTEGER, date TEXT, open REAL, close REAL, high REAL, low REAL, volume INTEGER, macd REAL, stochastic REALL);");
}

Sqlite3_DB::~Sqlite3_DB() {
	sqlite3_close(m_pDatabase);
}

bool Sqlite3_DB::InsertSecurityInfo(SecurityInfo const & in_info) {
	char numberConverter[20];
	std::string statement("INSERT INTO securities (date, open, high, low, volume, close, macd, stochastic) VALUES ('");

	sprintf(numberConverter, "%d-%02d-%d", in_info.date.GetYear(), in_info.date.GetMonth(), in_info.date.GetDay());
	statement += numberConverter;
	statement += "',";

	sprintf(numberConverter, "%f", in_info.open);
	statement += numberConverter;
	statement += ",";

	sprintf(numberConverter, "%f", in_info.high);
	statement += numberConverter;
	statement += ",";

	sprintf(numberConverter, "%f", in_info.low);
	statement += numberConverter;
	statement += ",";

	sprintf(numberConverter, "%d", in_info.volume);
	statement += numberConverter;
	statement += ",";

	sprintf(numberConverter, "%f", in_info.close);
	statement += numberConverter;
	statement += ",";

	sprintf(numberConverter, "%f", in_info.macd);
	statement += numberConverter;
	statement += ",";

	sprintf(numberConverter, "%f", in_info.stochasticOscillator);
	statement += numberConverter;
	statement += ");";

	return ExecuteStatement(statement);
}

std::vector<SecurityInfo> const & Sqlite3_DB::GetSecurityInfoAtDate(Date const & in_date) {
	std::string statement("SELECT date, open, high, low, close, volume FROM securities WHERE date='");
	char date[20];
	sprintf(date, "%d-%02d-%d", in_date.GetYear(), in_date.GetMonth(), in_date.GetDay());

	statement += date;
	statement += "';";
	std::vector<SecurityInfo> infoList;

	return infoList;
}

std::vector<SecurityInfo> const & Sqlite3_DB::GetSecurityInfoForRange(Date const & in_begin, Date const & in_end) {
	std::vector<SecurityInfo> infoList;

	return infoList;
}

/// PRIVATE INTERFACE

bool Sqlite3_DB::ExecuteStatement(std::string const & in_statement) {
	int returnCode;
	std::vector<std::vector<std::string> > results;

	sqlite3_stmt * statement = NULL;

	returnCode = sqlite3_prepare_v2(m_pDatabase, in_statement.c_str(), -1, &statement, 0);
	if(SQLITE_OK == returnCode) {
		sqlite3_step(statement);
	}
	else {
		std::string error = sqlite3_errmsg(m_pDatabase);
		if(error != "not an error") {
			printf("%s\n", error.c_str());
			return false;
		}
	}

	sqlite3_finalize(statement);

	return true;
}
