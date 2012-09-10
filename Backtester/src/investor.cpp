#include "../include/investor.h"
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

void Investor::ExecuteStrategy(std::vector<Market::SecurityInfo> const & in_securities) {
}

void Investor::ReportOut() {
    printf("Starting money: %f Current money: %f\n", m_startingMoney, m_currentMoney);
}
