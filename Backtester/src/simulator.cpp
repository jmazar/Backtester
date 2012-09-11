#include "../include/simulator.h"

Simulator::Simulator() {
    m_market.ReadInData("data/table.csv", 0);
}

Simulator::~Simulator() {
}

void Simulator::AddInvestor(Investor const & in_investor) {
    m_investors.push_back(in_investor);
}

void Simulator::RunSimulation() {
	std::list<Date> dates = m_market.GetDates();

	std::list<Date>::const_iterator iter;
	for(iter = dates.begin(); iter != dates.end(); iter++) {
		std::vector<SecurityInfo> securities = m_market.GetSecuritiesAtDate(*iter);

		std::vector<Investor>::iterator investorIter;
		for(investorIter = m_investors.begin(); investorIter != m_investors.end(); investorIter++){
			investorIter->ExecuteStrategy(securities);
			investorIter->ReportOut();
		}
	}
}

