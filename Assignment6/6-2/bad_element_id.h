#ifndef BAD_ELEMNT_ID_H
#define BAD_ELEMNT_ID_H


#include <iostream>
#include <exception>

using namespace std;

class BadElementId: public exception
{
public:
	virtual const char* what() const throw() { return "‫‪Invalid‬‬ element ID requested‬‬‫!\n";}
};

#endif