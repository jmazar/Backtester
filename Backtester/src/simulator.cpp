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
}

