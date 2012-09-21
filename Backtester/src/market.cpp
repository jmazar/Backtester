#include "../include/market.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>

Market::Market() {
}

Market::~Market() {
}

void Market::ReadInData(std::string in_fileName, unsigned int in_id) {
    std::ifstream file;
    file.open(in_fileName.c_str());

    std::string             line;

	if(file.good()) {
		getline(file, line, ',');
		// Add to security name database
		std::string statement("INSERT INTO security_names (name) VALUES ( '");
		statement += line;
		statement += "' );";
		m_database.ExecuteStatement(statement);
	}

    while(file.good()) {
		std::string statement("INSERT INTO securities (date, open, high, low, volume, close) VALUES (");
		//Set date
        getline(file, line, ','); //Read date
		statement += line + ",";
        //Do some stuff to get rid of -
		Date newDate(line);

		//Set open
        getline(file, line, ','); //Read open
		statement += line + ",";
		//Set high
		getline(file, line, ','); //Read high
		statement += line + ",";
		//Set low
        getline(file, line, ','); //Read low
		statement += line + ",";
		//Eat close, we don't care about it
        getline(file, line, ','); //Read close

		//Set volume
        getline(file, line, ','); //Read volume
		statement += line + ",";
		//Set adj close
        getline(file, line, ','); //Read adj close
		statement += line + ");";

		m_dates.push_back(newDate);
		m_database.ExecuteStatement(statement);
    }
	
	m_dates.sort();
	m_dates.unique();

    file.close();
}
std::vector<SecurityInfo> Market::GetSecurityInfoAtDate(Date const & in_date) {
	std::string statement("SELECT date, open, high, low, volume, close FROM securities WHERE date=");
	char date[20];
	sprintf(date, "%d-%d-%d", in_date.GetYear(), in_date.GetMonth(), in_date.GetDay());

	statement += date;
	statement += ";";
	printf("%s\n", statement.c_str());
	m_database.ExecuteStatement(statement);
	std::vector<SecurityInfo> info;
	//todo fill info
	return info;
}

std::list<Date> const & Market::GetDates() {
	return m_dates;
}
