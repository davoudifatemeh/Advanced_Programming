#include "command_handling.h"

using namespace std;

CommandHandling::CommandHandling(UsersHandling* _usershandling)
{
	usershandling = _usershandling;
}

void CommandHandling::check_request(string _command, bool has_questionmark)
{
	int not_found = 1;
	int bad_request = 1;
	int space_index = _command.find(" ");
	std::string check_commands = _command.substr(0,space_index);
	for (int i = 0; i < 23; i++)
	{
		if (check_commands == commands[i]) bad_request = 0;
	}
	if (has_questionmark)
	{
		int questionmark_index = _command.find("?");
		check_commands = _command.substr(0,questionmark_index - 1);
		for (int i = 0; i < 23; i++)
		{
			if (check_commands == commands[i]) not_found = 0;
		}
	}
	else if(_command.substr(0,13)=="GET followers"||_command.substr(0,10)=="POST money"||_command.substr(0,17)=="GET notifications")
		not_found = 0;
	if (bad_request == 1) throw BadRequestException();
	if (not_found == 1) throw NotFoundException();
}

void CommandHandling::check_id_format(string number)
{
	for (int i = 0; i < number.size(); i++)
	{
		if ((number[i]>='a' && number[i]<='z') || (number[i]>='A' && number[i]<='Z')) throw BadRequestException();
	}
	return;
}

string CommandHandling::find_value(string part_of_command,int start)
{
	string value;
	for (int i = start; i < part_of_command.size(); i++)
    {
    	if (part_of_command[i] != ' ')
        	value += part_of_command[i];
    	else if (value != "") break;
    }
    return value;
}

string CommandHandling::find_key_word(string key_word)
{
	int key_word_index = command.find(key_word);
	string temp = command.substr(key_word_index);
	if (find_value(temp,key_word.size()) == "") throw BadRequestException();
	else return find_value(temp,key_word.size());
}

string CommandHandling::find_email()
{
	int bad_format = 1;
    string email = find_key_word("email");
    if (email == "password" || email == "username" || email == "age" || email == "publisher") throw BadRequestException();
    else if (email.size() < 5) throw BadRequestException();
    else
    {
    	for (int i = 1; i < email.size() - 3; i++)
    	{
        	if (email[i] == '@')
      		{
        		for (int j = i + 2; j < email.size() - 1; j++)
          			if (email[j] == '.') bad_format = 0;
      		}
    	}
    	if (bad_format == 1) throw BadRequestException();
  	}
  	return email;
}

string CommandHandling::find_username()
{
	string username = find_key_word("username");
	if (username == "password" || username == "email" || username == "age" || username == "publisher") 
		throw BadRequestException();
	else return username;
}

string CommandHandling::find_password()
{
	string password = find_key_word("password");
	if (password == "email" || password == "username" || password == "age" || password == "publisher")
		throw BadRequestException();
	else return password;
}

string CommandHandling::find_age()
{
	string age = find_key_word("age");
	if (age == "email" || age == "username" || age == "password" || age == "publisher")
		throw BadRequestException();
	else return age;
}

bool CommandHandling::is_publisher()
{
	string publisher;
    string truefalse;
    for (int i = 0; i < command.size(); i++)  
    {
        if (command[i] != ' ')
        	publisher += command[i];
        else if (publisher == "publisher")
    	{
        	for(int j = i + 1; j < command.size(); j++)
      		{
        		if (command[j] != ' ')
            	truefalse += command[j];
        		else if (truefalse != "") break;
      		}
        	if (truefalse == "true") return true;
        	else if (truefalse == "false") return false;
        	else throw BadRequestException();
    	}
    	else publisher = "";
    }
    return false;
}

std::string CommandHandling::find_name()
{
	string name = find_key_word("name");
	if (name == "year" || name == "length" || name == "price" || name == "summary" || name == "directory")
		throw BadRequestException();
	else return name;
}

int CommandHandling::find_year()
{
	string year = find_key_word("year");
	if (year == "name" || year == "length" || year == "price" || year == "summary" || year == "directory")
		throw BadRequestException();
	else return stoi(year);
}

int CommandHandling::find_length()
{
	string length = find_key_word("length");
	if (length == "name" || length == "year" || length == "price" || length == "summary" || length == "directory")
		throw BadRequestException();
	else return stoi(length);
}

int CommandHandling::find_price()
{
	string price = find_key_word("price");
	if (price == "name" || price == "length" || price == "year" || price == "summary" || price == "directory")
		throw BadRequestException();
	else return stoi(price);
}
std::string CommandHandling::find_summary()
{
	string summary = find_key_word("summary");
	if (summary == "name" || summary == "length" || summary == "price" || summary == "year" || summary == "directory")
		throw BadRequestException();
	else return summary;
}

std::string CommandHandling::find_director()
{
	string director = find_key_word("director");
	if (director == "name" || director == "length" || director == "price" || director == "summary" || director == "year")
		throw BadRequestException();
	else return director;
}

void CommandHandling::signup()
{
	try
	{
		usershandling->signup(find_email(),find_username(),md5(find_password()),find_age(),is_publisher());
	}catch(BadRequestException br)
	{
		cout << br.what();
	}

}

void CommandHandling::login()
{
	try
	{
		usershandling->login(find_username(),md5(find_password()));
	}catch(BadRequestException br)
	{
		std::cout << br.what();
	}
}

void CommandHandling::post_follower()
{
	try
	{
		check_id_format(find_key_word("user_id"));
		usershandling->post_follower(stoi(find_key_word("user_id")));
	}catch(BadRequestException br)
	{
		cout << br.what();
	}
}

void CommandHandling::post_money()
{
	try
	{
		string money = find_value(command.substr(command.find("amount")), 6);
		if (money == "") throw BadRequestException();
		int amount = stoi(money);
		usershandling->post_money(amount);
	}catch(BadRequestException br)
	{
		cout << br.what();
	}
}

bool CommandHandling::questionmark(string _command)
{
	for (int i = 0; i < _command.size(); i++)
	{
		if (_command[i] == '?') return true;
	}
	return false;
}

void CommandHandling::register_film()
{
	try
	{
		usershandling->register_film(find_name(),find_year(),find_length(),find_price(),find_summary(),find_director()); 
	}catch(BadRequestException br)
	{
		cout << br.what();
	}
}

void CommandHandling::delete_film()
{
	try
	{
		check_id_format(find_key_word("film_id"));
		usershandling->delete_film(stoi(find_key_word("film_id")));
	}catch(BadRequestException br)
	{
		cout << br.what();
	}
}

void CommandHandling::buy_film()
{
	try
	{
		check_id_format(find_key_word("film_id"));
		usershandling->buy_film(stoi(find_key_word("film_id")));
	}catch(BadRequestException br)
	{
		cout << br.what();
	}
}

void CommandHandling::post_rate()
{
	try
	{
		check_id_format(find_key_word("film_id"));
		usershandling->post_rate(find_key_word("film_id"),find_key_word("score"));
	}catch(BadRequestException br)
	{
		cout << br.what();
	}
}

void CommandHandling::emplement_command()
{
	if (questionmark(command))
	{
		std::string c = command.substr(0,command.find('?') - 1);
		if (c == "POST signup") signup();
		if (c == "POST login") login();
		if (c == "POST followers") post_follower();
		if (c == "POST money") post_money();
		if (c == "POST films") register_film();
		if (c == "DELETE films") delete_film();
		if (c == "POST buy") buy_film();
		if (c == "POST rate") post_rate();
	}
	else
	{
		if (command.substr(0,13) == "GET followers") usershandling->get_followers();
	}
}

void CommandHandling::read_command(string _command)
{
	try
	{
		check_request(_command,questionmark(_command));
		command = _command;
		emplement_command();

	}catch(BadRequestException br)
	{
		cout << br.what();
	}catch(NotFoundException nf)
	{
		cout << nf.what();
	}
}