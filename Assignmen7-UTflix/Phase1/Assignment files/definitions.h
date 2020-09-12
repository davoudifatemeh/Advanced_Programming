#ifndef DEFINITIONS_H
#define DEFINITIONS_H

const std::string commands[23] = {"POST","PUT","DELETE","GET","POST signup","POST login","POST films","PUT films","DELETE films",
	"GET followers","POST money","GET published","POST replies","DELETE comments","POST followers","POST money","GET films",
	"POST buy","POST rate","POST comments","GET purchased","GET notifications","GET notifications read"};
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

#define REPLY 1
#define REGISTER_NEW_FILM 2
#define FOLLOW 3
#define BUY_FILM 4
#define RATE 5
#define COMMENT 6

#endif