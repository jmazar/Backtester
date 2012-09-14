#ifndef _MARKET_H
#define _MARKET_H

#include <map>
#include <string>
#include <vector>
#include <list>
#include "date.h"
#include "security_info.h"
#include "database.h"

class Market {
    public:
        Market();
        virtual ~Market();
        void ReadInData(std::string in_fileName, unsigned int in_id);
        std::vector<SecurityInfo> const & GetSecuritiesAtDate(Date const & in_date);
		std::list<Date> const & GetDates();
    private:
		std::list<Date>								m_dates;
		std::map<Date, std::vector<SecurityInfo> > 	m_securities;
		std::map<unsigned int, std::string>			m_names;
		Database									m_database;
};
#endif
