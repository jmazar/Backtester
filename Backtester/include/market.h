#ifndef _MARKET_H
#define _MARKET_H

#include "security.h"

class Market {
    public:
        Market();
        virtual ~Market();
        void ReadInData(std::string in_fileName);
        std::vector<Security> const & GetSecurities();
    private:
        std::vector<Security> m_securities;
};
#endif
