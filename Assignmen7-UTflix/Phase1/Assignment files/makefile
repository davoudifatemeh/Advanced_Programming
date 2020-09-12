CC = g++ -std=c++11

all: a.out

a.out: main.o MD5.o film.o user.o user_handling.o command_handling.o 
	${CC} main.o MD5.o film.o user.o user_handling.o command_handling.o -o a.out

main.o: main.cpp film.h definitions.h user.h user_handling.h command_handling.h exceptions.h MD5.h
	${CC} -c main.cpp

MD5.o: MD5.cpp MD5.h
	${CC} -c MD5.cpp

film.o: film.cpp film.h rate.h
	${CC} -c film.cpp

user.o: user.cpp user.h film.h definitions.h
	${CC} -c user.cpp

user_handling.o: user_handling.cpp user_handling.h user.h definitions.h film.h exceptions.h
	${CC} -c user_handling.cpp

command_handling.o: command_handling.cpp command_handling.h user_handling.h definitions.h exceptions.h MD5.h
	${CC} -c command_handling.cpp	

.PHONY: clean
clean:
	rm *.o
	rm a.out