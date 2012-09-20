#include "../include/market.h"
#include <fstream>
#include <sstream>

Market::Market() {
}

Market::~Market() {
}

void Market::ReadInData(std::string in_fileName, unsigned int in_id) {
    std::ifstream file;
    file.open(in_fileName.c_str());

    std::string             line;
	Date 					newDate;

	if(file.good()) {
		getline(file, line, ',');
		m_names[in_id] = line;
	}

    while(file.good()) {
		std::string statement("INSERT INTO securities (open, high, low, volume, close) VALUES (");
		//Set date
        getline(file, line, ','); //Read date
        //Do some stuff to get rid of -
        std::stringstream date(line);
        std::string partofdate = "";
		getline(date, partofdate, '-');
		newDate.SetYear(atoi(partofdate.c_str()));
		getline(date, partofdate, '-');
		newDate.SetMonth(atoi(partofdate.c_str()));
		getline(date, partofdate, '-');
		newDate.SetDay(atoi(partofdate.c_str()));
		newInfo.date = newDate;

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
		m_securities[newDate].push_back(newInfo);
		m_database.ExecuteStatement(statement);
    }
	
	m_dates.sort();
	m_dates.unique();

    file.close();
}

std::vector<SecurityInfo> const & Market::GetSecuritiesAtDate(Date const & in_date) {
    return m_securities[in_date];
}

std::list<Date> const & Market::GetDates() {
	return m_dates;
}
