all: backtester

clean: 
	rm -rf bin/*

backtester: main.o investor.o dbmarket.o simulator.o sqlite3_db.o sqlite.o
	g++ bin/sqlite.o bin/main.o bin/sqlite3_db.o bin/investor.o bin/dbmarket.o bin/simulator.o -o bin/backtester
	rm securities.db

investor.o: ../../include/dbmarket.h ../../include/security_info.h ../../include/investor.h ../../src/investor.cpp
	g++ -c ../../src/investor.cpp -o bin/investor.o

dbmarket.o: ../../include/isql_db.h ../../include/imarket.h ../../include/dbmarket.h ../../src/dbmarket.cpp
	g++ -c ../../src/dbmarket.cpp -o bin/dbmarket.o

simulator.o: ../../include/dbmarket.h ../../include/investor.h ../../include/simulator.h ../../src/simulator.cpp
	g++ -c ../../src/simulator.cpp -o bin/simulator.o

sqlite3_db.o: ../../3rdparty/sqlite/sqlite3.h ../../include/sqlite3_db.h ../../include/isql_db.h ../../src/sqlite3_db.cpp
	g++ -c ../../src/sqlite3_db.cpp -o bin/sqlite3_db.o

sqlite.o: ../../3rdparty/sqlite/sqlite3.h ../../3rdparty/sqlite/sqlite3.c
	gcc -c ../../3rdparty/sqlite/sqlite3.c -o bin/sqlite.o

main.o: ../../include/simulator.h ../../include/sqlite3_db.h ../../include/investor.h ../../src/main.cpp 
	g++ -c ../../src/main.cpp -o bin/main.o

