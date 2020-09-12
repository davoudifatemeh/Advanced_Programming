#ifndef USER_HANDLING_H
#define USER_HANDLING_H

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include "exceptions.h"
#include "user.h"
#include "film.h"

class UsersHandling
{
public:
	UsersHandling();
	void signup (std::string email,std::string username,std::string password,std::string age,bool publisher);
	void is_similar_username(std::string username);
	void valid_information(std::string username,std::string password);
	void login (std::string username,std::string password);
	void check_id(int user_id);
	void post_follower(int user_id);
	void post_money(int amount);
	void register_film(std::string name,int year,int length,int price,std::string summary,std::string director);
	void delete_film(int film_id);
	void get_followers();
	void buy_film(int film_id);
	void post_rate(std::string film_id,std::string score);

	int get_online_user_id() {return online_user_id;}
private:
	std::vector <User*> users;
	int online_user_id;
	std::vector <Film*> registered_films;
};

#endif