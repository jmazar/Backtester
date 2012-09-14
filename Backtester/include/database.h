#ifndef _DATABASE_H
#define _DATABASE_H

#include "../3rdparty/sqlite/sqlite3.h"
#include <string>

class Database {
	public:
		Database();
		virtual ~Database();
		int ExecuteStatement(std::string const & in_statement);
	private:
		Database(Database const &);
		Database const & operator=(Database const &);

		sqlite3 * m_pDatabase;
};

#endif
