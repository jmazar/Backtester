#include "market.h"
#include <fstream>
#include <sstream>

Market::Market() {
}

Market::~Market() {
}

void Market::ReadInData(std::string in_fileName) {
    std::ifstream file;
    file.open(in_fileName);

    Security                newSecurity;
    Security::SecurityInfo  newInfo;
    std::string             line;
    while(file.good()) {
        getline(file, line, ','); //Read date
        //Do some stuff to get rid of -
        std::stringstream date(line);
        std::string partofdate = "";
        std::string finaldate = "";
        for(int i = 0; i < 3; i++) {
            getline(date, partofdate, '-');
            finaldate += partofdate;
        }
        newInfo.date = atoi(finaldate.c_str());

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
        newSecurity.AddInfo(newInfo);
    }

    m_securities.push_back(newSecurity);

    file.close();
}

std::vector<Security> const & Market::GetSecurities() {
    return m_securities;
}
