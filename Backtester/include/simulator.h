#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "market.h"
#include "investor.h"

class Simulator {
    public:
        Simulator();
        virtual ~Simulator();
        void AddInvestor(Investor const & in_investor);
        void RunSimulation();
    private:
        Market                  m_market;
        std::vector<Investor>   m_investors;
};

#endif
