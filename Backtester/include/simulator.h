#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "dbmarket.h"
#include "investor.h"

class Simulator {
    public:
        Simulator();
        virtual ~Simulator();
        void AddInvestor(Investor const & in_investor);
        void RunSimulation();
    private:
        DBMarket                m_market;
        std::vector<Investor>   m_investors;
};

#endif
