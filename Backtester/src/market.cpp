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

    SecurityInfo  			newInfo;
    std::string             line;
	Date 					newDate;

	if(file.good()) {
		getline(file, line, ',');
		m_names[in_id] = line;
	}

    while(file.good()) {
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
        newInfo.open = atof(line.c_str());
		//Set high
		getline(file, line, ','); //Read high
        newInfo.high = atof(line.c_str());
		//Set low
        getline(file, line, ','); //Read low
        newInfo.low = atof(line.c_str());
		//Eat close, we don't care about it
        getline(file, line, ','); //Read close
		//Set volume
        getline(file, line, ','); //Read volume
        newInfo.volume = atoi(line.c_str());
		//Set adj close
        getline(file, line, ','); //Read adj close
        newInfo.close = atof(line.c_str());

		m_dates.push_back(newDate);
		m_securities[newDate].push_back(newInfo);
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
