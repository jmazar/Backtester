#include "../include/simulator.h"
#include "../include/investor.h"
#include "../include/database.h"

int main() {
    Simulator   simulation;
    Investor    investor;
	Database	database;

    investor.SetMoney(100000);
    simulation.AddInvestor(investor);
    //simulation.RunSimulation();
    return 0;
}
