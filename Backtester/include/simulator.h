#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "market.h"
#include "investor.h"

class Simulator {
    public:
        Simulator();
        virtual ~Simualator();
    private:
        Market                  m_market;
        std::vector<Investor>   m_investors;
        unsigned int            m_year;
        unsigned int            m_month;
        unsigned int            m_day;
};

#endif
