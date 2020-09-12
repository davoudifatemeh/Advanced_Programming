#ifndef COMMAND_HANDLING_H
#define COMMAND_HANDLING_H

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include "exceptions.h"
#include "definitions.h"
#include "user_handling.h"
#include "MD5.h"

class CommandHandling
{
public:
	CommandHandling(UsersHandling* _usershandling);
	void check_request(std::string _command,bool has_questionmark);
	void check_id_format(std::string numder);
	std::string find_key_word(std::string key_word);
	std::string find_email();
	std::string find_username();
	std::string find_password();
	std::string find_age();
	bool is_publisher();
	std::string find_name();
	int find_year();
	int find_length();
	int find_price();
	std::string find_summary();
	std::string find_director();
	std::string find_value(std::string part_of_command,int start);
	void signup ();
	void login ();
	void post_follower();
	void post_money();
	bool questionmark(std::string _command);
	void register_film();
	void delete_film();
	void buy_film();
	void post_rate();
	void emplement_command();
	void read_command(std::string _command);
private:
	std::string command;
	UsersHandling* usershandling;
};

#endif