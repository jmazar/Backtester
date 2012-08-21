#include "investor.h"
#include <stdio.h>

Investor::Investor() : 
    m_startingMoney(0),
    m_currentMoney(0) {
}
Investor::Investor(unsigned int in_money) : 
    m_startingMoney(in_money),
    m_currentMoney(in_money) {
}

Investor::~Investor() {
}

unsigned int Investor::GetCurrentMoney() {
    return m_currentMoney;
}

void Investor::SetMoney(unsigned int in_money) {
    m_startingMoney = in_money;
    m_currentMoney = in_money;
}

void Investor::ExecuteStrategy(std::vector<Security> const & in_securities, unsigned int in_date) {
    std::vector<Security::SecurityInfo> info = in_securities[0].GetInfo(in_date, in_date);
    double open = info[0].open;
    unsigned int date = info[0].date;
    if(in_date % 2 == 1) {
        int canBuy = m_currentMoney / open;
        m_currentMoney -= open * canBuy;
        printf("%d: Bought %d at %f. $%f left.\n", date, canBuy, open, m_currentMoney);

        m_ownedSecurities["butts"] = canBuy;
    } 
    else {
        m_currentMoney += m_ownedSecurities["butts"] * open;
        printf("%d: Sold %d for %f. $%f left.\n", date, m_ownedSecurities["butts"], open, m_currentMoney);
        m_ownedSecurities["butts"] = 0;
    }
    m_currentMoney -= 10;
}

void Investor::ReportOut() {
    printf("Starting money: %f Current money: %f\n", m_startingMoney, m_currentMoney);
}
