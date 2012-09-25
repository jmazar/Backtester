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
		std::vector<SecurityInfo> GetSecurityInfoAtDate(Date const & in_date);
    private:
		std::list<Date>								m_dates;
		Database									m_database;

		double _CalculateMACD(std::list<SecurityInfo> const & in_securities);
		double _CalculateStochasticOscillator(std::list<SecurityInfo> const & in_securities);
		void _InsertSecurityInfoIntoDB(SecurityInfo const & in_info);
};
#endif
