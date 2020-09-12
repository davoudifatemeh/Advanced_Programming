#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

using namespace std;

class NotFoundException: public exception
{
public:
	virtual const char* what() const throw() { return "‫‪Not Found\n";}
};

class BadRequestException: public exception
{
public:
	virtual const char* what() const throw() { return "Bad Request\n";}
};

class PermissionDeniedException: public exception
{
public:
	virtual const char* what() const throw() { return "‫Permission Denied\n";}
};

#endif