#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "definitions.h"
#include "exceptions.h"
#include "film.h"
#include "user.h"
#include "user_handling.h"
#include "command_handling.h"

using namespace std;

int main ()
{
	UsersHandling* usershandling = new UsersHandling();
	CommandHandling commandhandling(usershandling);
    /*string a = "POST signup ? email  df@g.ff password   1111 age 251 username    fff8 publisher true";
    string b = "POST signup ? email  df@g.ff password  222 username lklk age 26 ";
    string c = "POST signup ? username fati password 444 age 47 email ffff@t.o publisher true";
    string d = "POST followers ? user_id 1";
    string e = "POST films ? name ffdfd year 1999 length 180 summary dssdfsdf director sdfsd price 1800";
    string f = "POST login ? password   1111 username fff8";
    string g = "GET followers";
    t.read_command(a);
    t.read_command(b);
    t.read_command(c);
    t.read_command(d);
    t.read_command(e);
    t.read_command(f);
    t.read_command(g);
    cout << u->get_online_user_id() << endl;*/
    string input;
    while(getline(cin,input))
    {
        commandhandling.read_command(input);
    }
	return 0;
}