#ifndef _INVESTOR_H
#define _INVESTOR_H

#include <map>
#include <vector>
#include "market.h"
#include "security_info.h"

class Investor {
    public:
        Investor();
        Investor(unsigned int in_money);
        virtual ~Investor();
        unsigned int GetCurrentMoney();
        void SetMoney(unsigned int in_money);
        void ReportOut();
        void ExecuteStrategy(std::vector<SecurityInfo> const & in_securities);
    private:
        double              m_startingMoney;
        double              m_currentMoney;

};
#endif
