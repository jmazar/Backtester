#include "../include/simulator.h"

int main() {
    Simulator   simulation;
    Investor    investor;

    investor.SetMoney(100000);
    simulation.AddInvestor(investor);
    simulation.RunSimulation();

    return 0;
}
