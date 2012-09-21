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
	std::list<Date> dates = m_market.GetDates();

}

