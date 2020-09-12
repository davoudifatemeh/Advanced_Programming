#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "film.h"
#include "definitions.h"

class User
{
public:
	User(std::string _email,std::string _username,std::string _password,std::string _age);
	std::string get_username();
	std::string get_password();
	std::string get_email();
	int get_money();
	std::vector <int> get_followings();
	void add_follower(int user_id);
	void add_money(int amount);
	void buy_film(Film* film);
	std::vector <std::string> get_unread_notifications();
	std::vector <std::string> get_notifications();
	std::vector <Film*> get_boughten_films();
	virtual std::string get_type() = 0;
private:
	std::string email;
	std::string password;
	std::string username;
	std::string age;
	int money;
	std::vector <int> followings;
	std::vector <Film*> boughten_films;
	// vector <string> comments;
	std::vector <std::string> unread_notifications;
	std::vector <std::string> notifications;
};

class Publisher: public User
{
public:
	Publisher(std::string _email,std::string _username,std::string _password,std::string _age)
    	:User(_email,_username,_password,_age) {}
	std::string get_type();
	void add_following(int user_id);
	void register_film(std::string name,int year,int length,int price,std::string summary,std::string director);
	std::vector <int> get_followers();
	std::vector <Film*> get_published_films();
private:
	std::vector <int> followers;
	std::vector <Film*> published_films;
};

class Client: public User
{
public:
	Client (std::string _email,std::string _username,std::string _password,std::string _age)
    	:User(_email,_username,_password,_age) {}
	std::string get_type();
};

#endif