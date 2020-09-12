#include "user_handling.h"

using namespace std;

UsersHandling::UsersHandling()
{
	online_user_id = 0;
}

void UsersHandling::is_similar_username(string username)
{
	for(int i = 0; i < users.size(); i++)
	{
		if (users[i]->get_username() == username) throw BadRequestException();
	}
}

void UsersHandling::signup(string email,string username,string password,string age,bool publisher)
{
	try 
	{
		if (users.size() != 0) is_similar_username(username);
		if (publisher)
			users.push_back(new Publisher(email,username,password,age));
		else
			users.push_back(new Client(email,username,password,age)); 
		cout << "OK" << endl;
		online_user_id = users.size();
	}catch (BadRequestException br)
	{
		cout << br.what();
	}
}

void UsersHandling::valid_information(std::string username,std::string password)
{
	int invalid_username = 1;
	int invalid_password = 1;
	for (int i = 0; i < users.size(); i++)
	{
		if (username == users[i]->get_username()) invalid_username = 0;
		if (password == users[i]->get_password()) invalid_password = 0;
	}
	if (invalid_username == 1) throw BadRequestException();
	if (invalid_password == 1) throw BadRequestException();
}

void UsersHandling::login (std::string username,std::string password)
{
	try
	{
		valid_information(username,password);
		for (int i = 0; i < users.size(); i++)
		{
			if (username == users[i]->get_username())
				online_user_id = i + 1;
		}
		cout << "OK" << endl;
	}catch (BadRequestException br)
	{
		cout << br.what();
	}
}

void UsersHandling::check_id(int user_id)
{
	if (user_id == online_user_id) throw PermissionDeniedException();
	else
	{
		for (int i = 0; i < users.size(); i++)
		{
			if ((i + 1 == user_id) && (users[i]->get_type() == "Publisher")) return;
			else if ((i + 1 == user_id) && (users[i]->get_type() == "Client")) throw PermissionDeniedException();
			else throw NotFoundException();
		}
	}
}

void UsersHandling::post_follower(int user_id)
{
	try
	{
		int has_following = 0;
		check_id(user_id);
		for (int i = 0; i < users[online_user_id - 1]->get_followings().size(); i++)
		{
			if (users[online_user_id - 1]->get_followings()[i] == user_id) has_following = 1;
		}
		if (has_following == 0)
		{
			users[online_user_id - 1]->add_follower(user_id);
			Publisher* publisher = dynamic_cast<Publisher*>(users[user_id - 1]);
			publisher->add_following(online_user_id);
		}
		cout << "OK" << endl;
	}catch(PermissionDeniedException pd)
	{
		cout << pd.what();
	}catch(NotFoundException nf)
	{
		cout << nf.what();
	}
}

void UsersHandling::post_money(int amount)
{
	users[online_user_id - 1]->add_money(amount);
	cout << "OK" << endl;
}

void UsersHandling::register_film(string name,int year,int length,int price,string summary,string director)
{
	try
	{
		int is_registered = 0;
		Publisher* publisher = dynamic_cast<Publisher*>(users[online_user_id - 1]);
		if (publisher == NULL) throw PermissionDeniedException();
		for (int i = 0; i < publisher->get_published_films().size(); i ++)
		{
			if (publisher->get_published_films()[i]->get_name() == name) is_registered = 1;
		}
		if (is_registered == 0)
		{
			publisher->register_film(name,year,length,price,summary,director);
			registered_films.push_back(new Film(name,year,length,price,summary,director));
		}
		cout << "OK" << endl;
		cout << registered_films.size();
	}catch(PermissionDeniedException pd)
	{
		cout << pd.what();
	}
}

void UsersHandling::delete_film(int film_id)
{
	try
	{
		int has_film = 0;
		if (film_id > registered_films.size()) throw NotFoundException();
		Publisher* publisher = dynamic_cast<Publisher*>(users[online_user_id - 1]);
		if (publisher == NULL) throw PermissionDeniedException();
		for (int i = 0; i < publisher->get_published_films().size(); i++)
		{
			if (registered_films[film_id - 1]->get_name() == publisher->get_published_films()[i]->get_name())
			{
				has_film = 1;
				publisher->get_published_films()[i]->to_delete();
			}
		}
		if (has_film == 0) throw PermissionDeniedException();
		registered_films[film_id - 1]->to_delete();
		cout << "OK" << endl;
	}catch(PermissionDeniedException pd)
	{
		cout << pd.what();
	}catch(NotFoundException nf)
	{
		cout << nf.what();
	}
}

void UsersHandling::get_followers()
{
	try
	{
		Publisher* publisher = dynamic_cast<Publisher*>(users[online_user_id - 1]);
		if (publisher == NULL) throw PermissionDeniedException();
		cout << "List of Followers" << endl;
		for (int i = 0; i < publisher->get_followers().size(); i++)
		{
			cout << i + 1 << ". " << publisher->get_followers()[i];
			cout << " | " << users[publisher->get_followers()[i] - 1]->get_username();
			cout << " | " << users[publisher->get_followers()[i] - 1]->get_email() << endl;
		}
	}catch(PermissionDeniedException pd)
	{
		cout << pd.what();
	}
}

void UsersHandling::buy_film(int film_id)
{
	try
	{
		if (film_id > registered_films.size()) throw NotFoundException();
		int is_boughten = 0;
		if (registered_films[film_id - 1]->get_name() == "DELETED") throw NotFoundException();
		for(int i = 0; i < users[online_user_id - 1]->get_boughten_films().size(); i++)
		{
			if (users[online_user_id - 1]->get_boughten_films()[i]->get_name()==registered_films[film_id-1]->get_name()) is_boughten=1;
		}
		if (is_boughten == 0)
		{
			users[online_user_id - 1]->buy_film(registered_films[film_id - 1]);
		}
		cout << "OK" << endl;
	}catch(NotFoundException nf)
	{
		cout << nf.what();
	}
}

void UsersHandling::post_rate(string film_id,string score)
{
	try
	{
		int is_boughten = 0;
		if (film_id == "score" || score == "film_id") throw BadRequestException();
		if (stoi(film_id) > registered_films.size()) throw NotFoundException();
		if (stoi(score) < 0 || stoi(score) > 10) throw BadRequestException();
		if (registered_films[stoi(film_id) - 1]->get_name() == "DELETED") throw NotFoundException();
		for (int i = 0; i < users[online_user_id - 1]->get_boughten_films().size(); i++)
		{
			if (registered_films[stoi(film_id) - 1]->get_name() == users[online_user_id - 1]->get_boughten_films()[i]->get_name())
				is_boughten = 1;
		}
		if (is_boughten == 0) throw PermissionDeniedException();
		registered_films[stoi(film_id) - 1]->add_score(stoi(score),online_user_id);
		for (int i = 0; i < users[online_user_id - 1]->get_boughten_films().size(); i++)
		{
			if (registered_films[stoi(film_id) - 1]->get_name() == users[online_user_id - 1]->get_boughten_films()[i]->get_name())
				users[online_user_id - 1]->get_boughten_films()[i]->add_score(stoi(score),online_user_id);
		}
	}catch(BadRequestException br)
	{
		cout << br.what();
	}catch(NotFoundException nf)
	{
		cout << nf.what();
	}catch(PermissionDeniedException pd)
	{
		cout << pd.what();
	}
}