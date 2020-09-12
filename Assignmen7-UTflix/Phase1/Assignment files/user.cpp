#include "user.h"

using namespace std;

User::User(string _email,string _username,string _password,string _age)
	: email(_email), username(_username), password(_password), age(_age)
{
	money = 0;
}

string User::get_username()
{
	return username;
}

string User::get_password()
{
	return password;
}

string User::get_email()
{
	return email;
}

int User::get_money()
{
	return money;
}

vector <int> User::get_followings()
{
	return followings;
}

void User::add_follower(int user_id)
{
	followings.push_back(user_id);
}

void User::add_money(int amount)
{
	money += amount;
}

void User::buy_film(Film* film)
{
	boughten_films.push_back(film);
}

vector <string> User::get_unread_notifications()
{
	return unread_notifications;
}

vector <string> User::get_notifications()
{
	return notifications;
}

vector <Film*> User::get_boughten_films()
{
	return boughten_films;
}

string Publisher::get_type()
{
	return "Publisher";
}

void Publisher::add_following(int user_id)
{
	followers.push_back(user_id);
}

void Publisher::register_film(std::string name,int year,int length,int price,std::string summary,std::string director)
{
	published_films.push_back(new Film(name,year,length,price,summary,director));
}

vector <int> Publisher::get_followers()
{
	return followers;
}

vector <Film*> Publisher::get_published_films()
{
	return published_films;
}

string Client::get_type()
{
	return "Client";
}