#ifndef PARENT_H
#define PARENT_H

#include <iostream>
#include <string>

class Parent
{
public:
	Parent (int _id, std::string _title, int _parent_id): id(_id), title(_title), parent_id(_parent_id) {}
	virtual int get_id () = 0;
	virtual std::string get_title () = 0;
	virtual int get_parent_id () = 0;
	virtual std::string get_type() = 0;
	virtual void view () = 0;
protected:
	int id;
	std::string title;
	int parent_id;
};

#endif