#include "../include/dbmarket.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>

DBMarket::DBMarket() {
}

DBMarket::~DBMarket() {
}

void DBMarket::ReadInData(std::string in_fileName, unsigned int in_id) {
    std::ifstream file;
    file.open(in_fileName.c_str());

    std::string             line;

	if(file.good()) {
		getline(file, line, ',');
		// Add to security name database
		std::string statement("INSERT INTO security_names (name) VALUES ( '");
		statement += line;
		statement += "' );";
		//m_database.ExecuteStatement(statement);
	}

	std::list<SecurityInfo> trailingMonth;

    while(file.good()) {
		SecurityInfo newInfo;

		//Set date
        getline(file, line, ','); //Read date
        //Do some stuff to get rid of -
		Date newDate(line);
		newInfo.date = newDate;

		//Set open
        getline(file, line, ','); //Read open
		newInfo.open = atoi(line.c_str());
		
		//Set high
		getline(file, line, ','); //Read high
		newInfo.high = atoi(line.c_str());

		//Set low
        getline(file, line, ','); //Read low
		newInfo.low = atoi(line.c_str());
		
		//Eat close, we don't care about it
        getline(file, line, ','); //Read close

		//Set volume
        getline(file, line, ','); //Read volume
		newInfo.volume = atoi(line.c_str());

		//Set adj close
        getline(file, line, ','); //Read adj close
		newInfo.close = atoi(line.c_str());

		trailingMonth.push_front(newInfo);
		if(trailingMonth.size() > 31)
			trailingMonth.pop_back();

		newInfo.macd = _CalculateMACD(trailingMonth);

		newInfo.stochasticOscillator = _CalculateStochasticOscillator(trailingMonth);

		m_dates.push_back(newDate);
		m_database->InsertSecurityInfo(newInfo);
    }
	
	m_dates.sort();
	m_dates.unique();

    file.close();
}

std::vector<SecurityInfo> const & DBMarket::GetSecurityInfoAtDate(Date const & in_date) {
	return m_database->GetSecurityInfoAtDate(in_date);
}

std::vector<SecurityInfo> const & DBMarket::GetSecurityInfoForRange(Date const & in_begin, Date const & in_end) {
	std::vector<SecurityInfo> infos;

	return infos;
}
std::list<Date> const & DBMarket::GetAvailableDates() {
	return m_dates;
}

double DBMarket::_CalculateMACD(std::list<SecurityInfo> const & in_securities) {
	return 10;
}

double DBMarket::_CalculateStochasticOscillator(std::list<SecurityInfo> const & in_securities) {
	return 10;
}
