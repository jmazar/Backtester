#ifndef _MARKET_H
#define _MARKET_H

#include <map>
#include <string>
#include <vector>

class Market {
    public:
		typedef struct Date {
			unsigned int year;
			unsigned int month;
			unsigned int day;

			Date() : year(0), month(0), day(0) {}
			Date(	unsigned int in_year,
					unsigned int in_month,
					unsigned int in_day) :
					year(in_year),
					month(in_month),
					day(in_day) {}

			bool operator<(Date const & in_date) {
				if(this->year != in_date.year) {
					return this->year < in_date.year;
				}
				else if(this->month != in_date.month) {
					return this->month < in_date.month;
				}
				return this->year < in_date.year;
			}
		} Date;

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
    private:
		std::map<Date, std::vector<SecurityInfo> > m_securities;
};
#endif
