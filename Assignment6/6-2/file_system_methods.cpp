#include "file_system_methods.h"

using namespace std;

void FileSystemMethods::add_root()
{
	parents.push_back(new Directory(0,"root",0));
}

void FileSystemMethods::find_error(int id,string title,int parent_id,int& bad_parent_id)
{
	for (int i = 0; i < parents.size(); i++)
	{
		if (id == parents[i]->get_id())
			throw IdAlreadyExists();
		else if ((parent_id == parents[i]->get_parent_id()) && (title == parents[i]->get_title()))
			throw BadTitle();
		else if ((parents[i]->get_type() == "Directory") && (parent_id == parents[i]->get_id()))
			bad_parent_id = 0;
	}
	if (bad_parent_id == 1) throw BadParentId();
}

void FileSystemMethods::add_directory(int id, std::string title, int parent_id)
{
	try 
	{
		int bad_parent_id = 1;
		find_error(id,title,parent_id,bad_parent_id);
		parents.push_back(new Directory(id,title,parent_id));
	}catch (IdAlreadyExists i)
	{
		cerr << i.what();
	}catch (BadTitle bt)
	{
		cerr << bt.what();
	}catch (BadParentId bp)
	{
		cerr << bp.what();
	}
}

void FileSystemMethods::add_file(int id, std::string title, std::string content, int parent_id)
{
	try 
	{
		int bad_parent_id = 1;
		find_error(id,title,parent_id,bad_parent_id);
		parents.push_back(new File(id,title,content,parent_id));
	}catch (IdAlreadyExists i)
	{
		cerr << i.what();
	}catch (BadTitle bt)
	{
		cerr << bt.what();
	}catch (BadParentId bp)
	{
		cerr << bp.what();
	}
}

void FileSystemMethods::add_link(int id, std::string title, int element_id, int parent_id)
{
   	try 
	{
		int bad_parent_id = 1;
		int bad_linked_element = 1;
		find_error(id,title,parent_id,bad_parent_id);
		Link l (id,title,element_id,parent_id);
		for (int i = 0; i < parents.size(); i++)
		{
			if ((parents[i]->get_type() == "Directory" || parents[i]->get_type() == "File") 
				&& (l.get_element_id() == parents[i]->get_id()))
				bad_linked_element = 0;
		}
		if (bad_linked_element == 1) throw BadLinkedElement();
		parents.push_back(new Link(id,title,element_id,parent_id));
		links.push_back(new Link(id,title,element_id,parent_id));
	}catch (IdAlreadyExists i)
	{
		cerr << i.what();
	}catch (BadTitle bt)
	{
		cerr << bt.what();
	}catch (BadParentId bp)
	{
		cerr << bp.what();
	}catch (BadLinkedElement bl)
	{
		cerr << bl.what();
	}
}

int FileSystemMethods::find_parents_index(int id)
{
	for (int i = 0; i < parents.size(); i++)
	{
		if (parents[i]->get_id() == id)
			return i;
	}
	throw BadElementId();
}

int FileSystemMethods::find_links_index (int id)
{
	for (int i = 0; i < links.size(); i++)
	{
		if (links[i]->get_id() == id)
			return i;
	}
}

void FileSystemMethods::view_link_ingredient (int parents_index,int links_index)
{
	for (int i = 0; i < parents.size(); i++)
	{
		if (parents[i]->get_id() == links[links_index]->get_element_id())
			parents[i]->view();
		if (parents[i]->get_parent_id() == links[links_index]->get_element_id())
			cout << "Title: " << parents[i]->get_title() << ", Type: " << parents[i]->get_type() << endl;
	}
}

void FileSystemMethods::view(int id)
{
	try
	{
		int parents_index = find_parents_index(id);
		parents[parents_index]->view();
		int links_index;
		if (parents[parents_index]->get_type() == "Directory")
		{
			for (int i = 0; i < parents.size(); i++)
			{
				if (parents[i]->get_parent_id() == id && parents[i]->get_id() != 0)
					cout << "Title: " << parents[i]->get_title() << ", Type: " << parents[i]->get_type() << endl;
			}
		}
		if (parents[parents_index]->get_type() == "Link")
		{
			links_index = find_links_index(id);	
			view_link_ingredient(parents_index,links_index);
		}
	}catch (BadElementId bei)
	{
		cerr << bei.what();
	}
}