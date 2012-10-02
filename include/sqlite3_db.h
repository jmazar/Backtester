#ifndef _DATABASE_H
#define _DATABASE_H

#include "../3rdparty/sqlite/sqlite3.h"
#include "isql_db.h"

class Sqlite3_DB : public ISql_DB {
	public:
		Sqlite3_DB();
		virtual ~Sqlite3_DB();
		virtual bool InsertSecurityInfo(SecurityInfo const & in_info);
		virtual std::vector<SecurityInfo> const & GetSecurityInfoAtDate(Date const & in_date);
		virtual std::vector<SecurityInfo> const & GetSecurityInfoForRange(Date const & in_begin, Date const & in_end);
	private:
		Sqlite3_DB(Sqlite3_DB const &);
		Sqlite3_DB const & operator=(Sqlite3_DB const &);
		bool ExecuteStatement(std::string const & in_statement);

		sqlite3 * m_pDatabase;
};

#endif
