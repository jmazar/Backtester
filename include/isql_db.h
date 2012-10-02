#ifndef _ISQL_DB
#define _ISQL_DB

#include <vector>
#include "security_info.h"
#include "date.h"

class ISql_DB {
	public:
		virtual bool InsertSecurityInfo(SecurityInfo const & in_info) = 0;
		virtual std::vector<SecurityInfo> const & GetSecurityInfoAtDate(Date const & in_date) = 0;
		virtual std::vector<SecurityInfo> const & GetSecurityInfoForRange(Date const & in_begin, Date const & in_end) = 0;
};

#endif
