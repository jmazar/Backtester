#include "../include/simulator.h"

Simulator::Simulator() {
    m_market.ReadInData("data/table.csv");
}

Simulator::~Simulator() {
}

void Simulator::AddInvestor(Investor const & in_investor) {
    m_investors.push_back(in_investor);
}

void Simulator::RunSimulation() {
    std::vector<Security> securities = m_market.GetSecurities(); 
    
    for(int i = 102; i > -1; i--) {
        for(std::vector<Investor>::iterator investorIter = m_investors.begin(); investorIter != m_investors.end();
                investorIter++) {
            investorIter->ExecuteStrategy(securities, i);
        }
    }

    for(std::vector<Investor>::iterator investorIter = m_investors.begin(); investorIter != m_investors.end();
            investorIter++) {
        investorIter->ReportOut();
    }

}

