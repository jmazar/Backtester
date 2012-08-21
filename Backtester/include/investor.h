#ifndef _INVESTOR_H
#define _INVESTOR_H

#include <map>
#include <vector>
#include "security.h"

class Investor {
    public:
        Investor();
        Investor(unsigned int in_money);
        virtual ~Investor();
        unsigned int GetCurrentMoney();
        void SetMoney(unsigned int in_money);
        void ReportOut();
        void ExecuteStrategy(std::vector<Security> const & in_securities, unsigned int in_date);
    private:
        typedef std::map<std::string, unsigned int>     OwnedSecuritiesMap;
        OwnedSecuritiesMap  m_ownedSecurities;
        double              m_startingMoney;
        double              m_currentMoney;

};
#endif
