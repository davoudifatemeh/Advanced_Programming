#ifndef RATE_H
#define RATE_H

#include <iostream>
#include <string>

class Rate
{
public:
	Rate(int _score,int _user_id) : score(_score), user_id(_user_id) {}
	int get_score() {return score;}
	int get_user_id() {return user_id;}
private:
	int score;
	int user_id;
};

#endif