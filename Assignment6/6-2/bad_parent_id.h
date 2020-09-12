#ifndef BAD_PARENT_ID_H
#define BAD_PARENT_ID_H

#include <iostream>
#include <exception>

using namespace std;

class BadParentId: public exception
{
public:
	virtual const char* what() const throw() { return "Parent ID is not referring to a directory!\n";}
};

#endif