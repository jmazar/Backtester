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
		_InsertSecurityInfoIntoDB(newInfo);
    }
	
	m_dates.sort();
	m_dates.unique();

    file.close();
}

std::vector<SecurityInfo> Market::GetSecurityInfoAtDate(Date const & in_date) {
	std::string statement("SELECT date, open, high, low, close, volume FROM securities WHERE date='");
	char date[20];
	sprintf(date, "%d-%02d-%d", in_date.GetYear(), in_date.GetMonth(), in_date.GetDay());

	statement += date;
	statement += "';";
	std::vector< std::vector<std::string> > results = m_database.ExecuteStatement(statement);
	std::vector<SecurityInfo> infoList;
	std::vector< std::vector<std::string> >::const_iterator rowIter;
	for(rowIter = results.begin(); rowIter != results.end(); rowIter++) {
		std::vector<std::string>::const_iterator columnIter = rowIter->begin();
		SecurityInfo info;
		columnIter++;
		info.open = atoi(columnIter++->c_str());
		info.close = atoi(columnIter++->c_str());
		info.high = atoi(columnIter++->c_str());
		info.low = atoi(columnIter++->c_str());
		info.volume = atoi(columnIter++->c_str());
		infoList.push_back(info);
	}
	//todo fill info
	return infoList;
}

std::list<Date> const & Market::GetDates() {
	return m_dates;
}

void Market::_InsertSecurityInfoIntoDB(SecurityInfo const & in_info) {
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

	m_database.ExecuteStatement(statement);
}

double Market::_CalculateMACD(std::list<SecurityInfo> const & in_securities) {
	return 10;
}

double Market::_CalculateStochasticOscillator(std::list<SecurityInfo> const & in_securities) {
	return 10;
}
