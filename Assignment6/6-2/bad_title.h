#ifndef BAD_TITLE_H
#define BAD_TITLE_H

#include <iostream>
#include <exception>

using namespace std;

class BadTitle: public exception
{
public:
	virtual const char* what() const throw() { return "Parent directory has the same child!\n";}
};

#endif