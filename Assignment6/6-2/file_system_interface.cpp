#include "file_system_interface.h"

using namespace std;

FileSystemInterface::FileSystemInterface ()
{
	fsm = new FileSystemMethods;
	fsm->add_root();
}

void FileSystemInterface::add_directory(int id, std::string title, int parent_id)
{
	fsm->add_directory(id,title,parent_id);
}

void FileSystemInterface::add_file(int id, std::string title, std::string content, int parent_id)
{
	fsm->add_file(id,title,content,parent_id);
}

void FileSystemInterface::add_link(int id, std::string title, int element_id, int parent_id)
{
	fsm->add_link(id,title,element_id,parent_id);
}

void FileSystemInterface::view(int id)
{
	fsm->view(id);
}