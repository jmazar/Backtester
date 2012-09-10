#ifndef _MARKET_H
#define _MARKET_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include "date.h"

class Market {
    public:
        typedef struct SecurityInfo {
			std::string		name;
            double          open;
            double          close;
            double          high;
            double          low;
            unsigned int    volume;
        } SecurityInfo;

        Market();
        virtual ~Market();
        void ReadInData(std::string in_fileName);
        std::vector<SecurityInfo> const & GetSecuritiesAtDate(Date const & in_date);
		std::set<Date> const & GetDates();
    private:
		std::set<Date>								m_dates;
		std::map<Date, std::vector<SecurityInfo> > 	m_securities;
};
#endif
