#include "../include/market.h"
#include <fstream>
#include <sstream>

Market::Market() {
}

Market::~Market() {
}

void Market::ReadInData(std::string in_fileName) {
    std::ifstream file;
    file.open(in_fileName.c_str());

    SecurityInfo  newInfo;
    std::string             line;
	Date newDate;
    while(file.good()) {
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

        getline(file, line, ','); //Read open
        newInfo.open = atof(line.c_str());
		getline(file, line, ','); //Read high
        newInfo.high = atof(line.c_str());
        getline(file, line, ','); //Read low
        newInfo.low = atof(line.c_str());
        getline(file, line, ','); //Read close
        getline(file, line, ','); //Read volume
        newInfo.volume = atoi(line.c_str());
        getline(file, line, ','); //Read adj close
        newInfo.close = atof(line.c_str());
    }

	if(m_dates.find(newDate) != m_dates.end()) {
		m_dates.insert(newDate);
	}
    m_securities[newDate].push_back(newInfo);

    file.close();
}

std::vector<Market::SecurityInfo> const & Market::GetSecuritiesAtDate(Date const & in_date) {
    return m_securities[in_date];
}

std::set<Date> const & Market::GetDates() {
	return m_dates;
}
