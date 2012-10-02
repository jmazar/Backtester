#ifndef _IDATAPROVIDER_H
#define _IDATAPROVIDER_H

#include "isecurity.h"

class IDataProvider {
	public:
	private:
		std::string				m_name;
		std::vector<ISecurity>	m_securities;
};

#endif
