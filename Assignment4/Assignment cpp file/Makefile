CC = g++ --std=c++11

all: Scheduler.out

Scheduler.out: main.o Process.o Core.o
	${CC} main.o Process.o Core.o -o Scheduler.out

main.o: main.cpp Process.h Core.h
	${CC} -c main.cpp

process.o: Process.cpp Process.h
	${CC} -c Process.cpp
Core.o: Core.cpp Core.h Process.h
	${CC} -c Core.cpp

.PHONY: clean
clean:
	rm *.o
	rm a.out
