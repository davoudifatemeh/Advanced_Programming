#ifndef ID_ALREADY_EXISTS_H
#define ID_ALREADY_EXISTS_H

#include <iostream>
#include <exception>

using namespace std;

class IdAlreadyExists: public exception
{
public:
	virtual const char* what() const throw() {return "Requested ID already exists!\n";}
};

#endif