#ifndef LINK_H
#define LINK_H

#include <iostream>
#include <string>
#include "parent.h"

class Link: public Parent
{
public:
	Link (int _id, std::string _title,int _element_id,int _parent_id): Parent (_id,_title,_parent_id),element_id(_element_id) {}
	int get_id () {return id;}
	std::string get_title () {return title;}
	int get_parent_id () {return parent_id;}
	int get_element_id () {return element_id;}
	std::string get_type() {return "Link";}
	void view ();
private:
	int element_id;
};

#endif