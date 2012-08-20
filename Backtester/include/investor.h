#ifndef _INVESTOR_H
#define _INVESTOR_H

#include <map>

class Investor {
    public:
        Investor();
        Investor(unsigned int in_money);
        virtual ~Investor();
        unsigned int GetCurrentMoney();
        unsigned int SetMoney(unsigned int in_money);
        void ExecuteStrategy();
    private:
        typedef std::map<std::string, unsigned int>     OwnedSecuritiesMap;

        OwnedSecuritiesMap  m_ownedSecurities;
        double              m_money;

};
#endif
