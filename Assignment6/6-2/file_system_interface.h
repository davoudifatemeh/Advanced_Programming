#ifndef FILE_SYSTEM_INTERFACE_H
#define FILE_SYSTEM_INTERFACE_H

#include "file_system_methods.h"
#include <iostream>
#include <string>

class FileSystemInterface
{
public:
	FileSystemInterface ();
    void add_directory(int id, std::string title, int parent_id);
    void add_file(int id, std::string title, std::string content, int parent_id);
    void add_link(int id, std::string title, int element_id, int parent_id);
    void view(int id);
private:
	FileSystemMethods* fsm;
};

#endif