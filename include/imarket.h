#ifndef _IMARKET_H
#define _IMARKET_H

#include <vector>
#include <list>
#include "security_info.h"
#include "date.h"

class IMarket {
	public:
		virtual std::list<Date> const & GetAvailableDates() = 0;
		virtual std::vector<SecurityInfo> const & GetSecurityInfoAtDate(Date const & in_date) = 0;
		virtual std::vector<SecurityInfo> const & GetSecurityInfoForRange(Date const & in_begin, Date const & in_end) = 0;
};

#endif
