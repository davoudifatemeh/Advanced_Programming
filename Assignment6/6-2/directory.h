#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <string>
#include "parent.h"

class Directory : public Parent
{
public:
	Directory (int _id,std::string _title,int _parent_id): Parent (_id,_title,_parent_id) {}
	int get_id () {return id;}
	std::string get_title () {return title;}
	int get_parent_id () {return parent_id;}
	std::string get_type() {return "Directory";}
	void view ();
};

#endif