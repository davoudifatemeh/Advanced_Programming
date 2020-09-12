#ifndef FILE_SYSTEM_METHODS_H
#define FILE_SYSTEM_METHODS_H

#include <iostream>
#include <vector>
#include "parent.h"
#include "directory.h"
#include "file.h"
#include "link.h"
#include "bad_element_id.h"
#include "bad_parent_id.h"
#include "bad_title.h"
#include "bad_linked_element.h"
#include "id_already_exists.h"

class FileSystemMethods
{
public:
	void add_root();
	void find_error(int id,string title,int parent_id,int& bad_parent_id);
	void add_directory(int id, std::string title,int parent_id);
	void add_file(int id, std::string title, std::string content, int parent_id);
    void add_link(int id, std::string title, int element_id, int parent_id);
    int find_parents_index (int id);
    int find_links_index (int id);
    void view_link_ingredient (int parents_index,int links_index);
    void view(int id);

private:
	std::vector<Parent*> parents;
	std::vector<Link*> links;
};

#endif