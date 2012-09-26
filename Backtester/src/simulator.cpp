#include "../include/simulator.h"

Simulator::Simulator() {
    m_market.ReadInData("../data/table.csv", 0);
}

Simulator::~Simulator() {
}

void Simulator::AddInvestor(Investor const & in_investor) {
    m_investors.push_back(in_investor);
}

void Simulator::RunSimulation() {
	std::list<Date> dates = m_market.GetAvailableDates();
	
	std::vector<SecurityInfo> info = m_market.GetSecurityInfoAtDate(dates.front());
	for(std::vector<SecurityInfo>::const_iterator iter = info.begin(); iter != info.end(); iter++){
	}


}

