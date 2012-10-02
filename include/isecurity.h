#ifndef _ISECURITY_H
#define _ISECURITY_H

#include "iindicator.h"
#include <vector>

class ISecurity {
	public:
	private:
		std::string				m_name;
		std::vector<IIndicator>	m_indicators;
};

#endif
