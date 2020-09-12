#include "film.h"

using namespace std;

Film::Film(string _name,int _year,int _length,int _price,string _summary,string _director)
	:name(_name), year(_year), length(_length), price(_price),summary(_summary), director(_director)
{
	rate = 0;
}

string Film::get_name()
{
	return name;
}

int Film::get_year()
{
	return year;
}

int Film::get_length()
{
	return length;
}

int Film::get_price()
{
	return price;
}

string Film::get_summary()
{
	return summary;
}

string Film::get_director()
{
	return director;
}

void Film::to_delete()
{
	name = "DELETED";
}

void Film::change_name(string new_name)
{
	name = new_name;
}

void Film::change_year(int new_year)
{
	year = new_year;
}

void Film::change_length(int new_length)
{
	length = new_length;
}

void Film::change_summary(string new_summary)
{
	summary = new_summary;
}

void Film::change_director(string new_director)
{
	director = new_director;
}

void Film::calculate_rate()
{
	float scores = 0;
	for (int i = 0; i < rates.size(); i++)
		scores += rates[i]->get_score();
	rate = scores/rates.size();
}

void Film::add_score(int score,int user_id)
{
	for(int i = 0; i < rates.size(); i++)
	{
		if (rates[i]->get_user_id() == user_id) rates.erase(rates.begin() + i);
	}
	rates.push_back(new Rate(score,user_id));
	calculate_rate();
}