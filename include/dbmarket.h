#ifndef _DBMARKET_H
#define _DBMARKET_H

#include "imarket.h"
#include "isql_db.h"

class DBMarket : public IMarket {
    public:
        DBMarket();
        virtual ~DBMarket();
        void ReadInData(std::string in_fileName, unsigned int in_id);
		virtual std::list<Date> const & GetAvailableDates();
		virtual std::vector<SecurityInfo> const & GetSecurityInfoAtDate(Date const & in_date);
		virtual std::vector<SecurityInfo> const & GetSecurityInfoForRange(Date const & in_begin, Date const & in_end);

    private:
		std::list<Date>								m_dates;
		ISql_DB *									m_database;

		double _CalculateMACD(std::list<SecurityInfo> const & in_securities);
		double _CalculateStochasticOscillator(std::list<SecurityInfo> const & in_securities);
};

#endif
