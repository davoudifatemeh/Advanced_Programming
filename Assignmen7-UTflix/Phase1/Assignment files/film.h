#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
#include <vector>
#include "rate.h"

class Film
{
public:
	Film(std::string _name,int _year,int _length,int _price,std::string _summary,std::string _director);
	void calculate_rate();
	std::string get_name();
	void to_delete();
	void change_name(std::string new_name);
	void change_year(int new_year);
	void change_length(int new_length);
	void change_summary(std::string new_summary);
	void change_director(std::string new_director);
	void add_score(int score,int user_id);
	int get_year();
	int get_length();
	int get_price();
	std::string get_summary();
	std::string get_director();
private:
	std::string name;
	int year;
	int length;
	int price;
	float rate;
	std::string summary;
	std::string director;
	std::vector <Rate*> rates;
};

#endif