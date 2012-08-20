#include "investor.h"

Investor::Investor() : 
    m_money(0) {
}
Investor::Investor(unsigned int in_money) : 
    m_money(in_money) {
}

Investor::~Investor() {
}

unsigned int Investor::GetCurrentMoney() {
    return m_money;
}

unsigned int Investor::SetMoney(unsigned int in_money) {
    m_money = in_money;
}

void Investor::ExecuteStrategy() {
}
