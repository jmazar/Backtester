#include "../include/simulator.h"
#include "../include/investor.h"
#include "../3rdparty/sqlite/sqlite3.h"

int main() {
    Simulator   simulation;
    Investor    investor;

    investor.SetMoney(100000);
    simulation.AddInvestor(investor);
    simulation.RunSimulation();

		sqlite3 * db;
		int rc;
		rc = sqlite3_open("test.db" ,&db);
		if(rc) {
			printf("That shit cray\n");
			sqlite3_close(db);
		}
		sqlite3_close(db);
    return 0;
}
