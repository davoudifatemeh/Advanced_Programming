#ifndef BAD_LINKED_ELEMNT_H
#define BAD_LINKED_ELEMNT_H

#include <iostream>
#include <exception>

using namespace std;

class BadLinkedElement: public exception
{
public:
	virtual const char* what() const throw() { return "Invalid element type requested!\n";}
};

#endif