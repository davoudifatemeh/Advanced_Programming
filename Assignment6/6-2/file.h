#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include "parent.h"

class File: public Parent
{
public:
	File (int _id,std::string _title,std::string _content,int _parent_id): Parent(_id,_title,_parent_id),content(_content) {}
	int get_id () {return id;}
	std::string get_title () {return title;}
	int get_parent_id () {return parent_id;}
	std::string get_type() {return "File";}
	virtual void view ();
private:
	std::string content;
};

#endif