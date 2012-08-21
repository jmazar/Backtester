#include "simulator.h"

int main() {
    Simulator   simulation;
    Investor    investor;

    investor.SetMoney(100000);
    simulation.AddInvestor(investor);
    simulation.RunSimulation();

    system("pause");
    return 0;
}
