#ifndef _DATABASE_H
#define _DATABASE_H

#include "../3rdparty/sqlite/sqlite3.h"

class Database {
	public:
		Database();
		virtual ~Database();
	private:
		Database(Database const &);
		Database const & operator=(Database const &);

		sqlite3 * m_pDatabase;
};

#endif
