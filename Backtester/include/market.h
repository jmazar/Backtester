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
		std::list<Date> const & GetDates();
    private:
		std::list<Date>								m_dates;
		Database									m_database;
};
#endif
