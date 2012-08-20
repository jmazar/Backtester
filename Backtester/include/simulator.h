#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "market.h"

class Simulator {
    public:
        Simulator();
        virtual ~Simualator();
    private:
        Market m_market;
};

#endif
