all: backtester

backtester: main.o investor.o market.o security.o simulator.o
	g++ main.o investor.o market.o security.o simulator.o -o backtester

investor.o: ../include/investor.h ../src/investor.cpp
	g++ -c ../src/investor.cpp -o investor.o

market.o: ../include/market.h ../src/market.cpp
	g++ -c ../src/market.cpp -o market.o

simulator.o: ../include/simulator.h ../src/simulator.cpp
	g++ -c ../src/simulator.cpp -o simulator.o

main.o: ../src/main.cpp 
	g++ -c ../src/main.cpp -o main.o

