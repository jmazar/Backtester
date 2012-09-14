all: backtester

clean: 
	rm -rf bin/*

backtester: main.o investor.o market.o simulator.o database.o sqlite.o
	g++ bin/sqlite.o bin/main.o bin/database.o bin/investor.o bin/market.o bin/simulator.o -o bin/backtester

investor.o: ../include/market.h ../include/security_info.h ../include/investor.h ../src/investor.cpp
	g++ -c ../src/investor.cpp -o bin/investor.o

market.o: ../include/security_info.h ../include/date.h ../include/market.h ../src/market.cpp
	g++ -c ../src/market.cpp -o bin/market.o

simulator.o: ../include/market.h ../include/investor.h ../include/simulator.h ../src/simulator.cpp
	g++ -c ../src/simulator.cpp -o bin/simulator.o

database.o: ../3rdparty/sqlite/sqlite3.h ../include/database.h ../src/database.cpp
	g++ -c ../src/database.cpp -o bin/database.o

sqlite.o: ../3rdparty/sqlite/sqlite3.h ../3rdparty/sqlite/sqlite3.c
	gcc -c ../3rdparty/sqlite/sqlite3.c -o bin/sqlite.o

main.o: ../include/simulator.h ../include/database.h ../include/investor.h ../src/main.cpp 
	g++ -c ../src/main.cpp -o bin/main.o

