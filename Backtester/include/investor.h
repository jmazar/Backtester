#ifndef _INVESTOR_H
#define _INVESTOR_H

#include <map>
#include <vector>

class Investor {
    public:
        Investor();
        Investor(unsigned int in_money);
        virtual ~Investor();
        unsigned int GetCurrentMoney();
        void SetMoney(unsigned int in_money);
        void ReportOut();
        void ExecuteStrategy();
    private:
        double              m_startingMoney;
        double              m_currentMoney;

};
#endif
