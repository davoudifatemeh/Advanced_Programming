#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
typedef vector<string> LINE;
vector <char> prog_line (275,'\0');
vector <vector <char> > lines(3,prog_line);

const string week[7] = {"## Saturday", "## Sunday", "## Monday", "## Tuesday", "## wednesday", "## Thursday", "## Friday"};
const string input_days[7] = {"SAT", "SUN", "MON", "TUE", "WED", "THE", "FRI"};
const string hhmm[28] = {"07:00", "07:30", "08:00", "08:30", "09:00", "09:30", "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "13:00", "13:30", "14:00", "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30", "18:00", "18:30", "19:00", "19:30", "20:00", "20:30"};

struct presentations_list
{
	vector<string> ids;
	vector<string> groups;
	vector<LINE> days;
	vector<LINE> times;
} List;

void save_presentations_list()
{
	LINE temp;
	string data;
	while (getline(cin, data))
	{
		List.ids.push_back(data.substr(0, 7));
		List.groups.push_back(data.substr(8, 2));
		for (int i = 11; i < data.size(); i += 16)
			temp.push_back(data.substr(i, 3));
		List.days.push_back(temp);
		temp.clear();
		for (int j = 15; j < data.size(); j += 16)
			temp.push_back(data.substr(j, 11));
		List.times.push_back(temp);
		temp.clear();
	}
}

void save_courses(string file_address, vector<LINE> &id_alias)
{
	string line;
	int comma_index;
	ifstream courses(file_address);
	while (getline(courses, line))
	{
		LINE temp;
		comma_index = line.find(',');
		string id = line.substr(0, comma_index);
		string alias = line.substr(comma_index + 1);
		temp.push_back(id);
		temp.push_back(alias);
		id_alias.push_back(temp);
	}
	courses.close();
}

void print_hhmm(int index)
{
	cout << week[index] << endl
		 << endl;
	for (int i = 0; i < 27; i++)
		cout << setw(10) << left << hhmm[i];
	cout << hhmm[27] << endl;
	for (int j = 0; j < 275; j++)
		cout << char(95);
	cout << endl;
}

bool is_presentation(int index)
{
	for (int i = 0; i < List.days.size(); i++)
	{
		for (int j = 0; j < List.days[i].size(); j++)
		{
			if (List.days[i][j] == input_days[index])
				return true;
		}
	}
	return false;
}

string find_alias(int n,vector <LINE> id_alias)
{
	for (int i=1;i<id_alias.size();i++)
	{
		if (id_alias[i][0] == List.ids[n])
			return id_alias[i][1];
	}
}

int find_hhmm (int i,int j,int n)
{
	if (n == 0)
	{
		for (int k = 0; k < 28; k++)
		{
			if (hhmm[k] == List.times[i][j].substr(0,5))
				return ((10*k)+2);
		}
	}
	if (n == 1)
	{
		for (int k = 0; k < 28; k++)
		{
			if (hhmm[k] == List.times[i][j].substr(6))
				return ((10*k)+1);
		}
	}
}

bool can_fill (int row,int start_cell,int end_cell)
{
	for (int i = start_cell; i < end_cell; i++)
	{
		if ((lines[row][i] != '\0') && (lines[row][i] != ' ')) return false;
	}
	return true;
}

int find_line (int row,int start_cell,int end_cell)
{
	if (row <= 0)
		return 0;
	if (!can_fill(row,start_cell,end_cell))
		return row+1;
	find_line (row-3,start_cell,end_cell);
}

void make_frame(int row,int start_cell,int end_cell,string alias_group)
{
	int line = find_line(row,start_cell,end_cell);
	if (line>=lines.size())
	{
		lines.push_back(prog_line);
		lines.push_back(prog_line);
		lines.push_back(prog_line);
	}
	for (int j=0;j<start_cell;j++)
	{
		if (lines[line][j] == '\0')
		{
			lines[line][j]=' ';
			lines[line+1][j]=' ';
			lines[line+2][j]=' ';
		}
	}
	lines[line][start_cell]='+';
	lines[line][end_cell]='+';

	for (int i=start_cell+1;i<end_cell;i++)
		lines[line][i]='-';

	lines[line+1][start_cell]=char(124);
	lines[line+1][end_cell]=char(124);

	for (int i=start_cell+1;i<end_cell;i++)
		lines[line+1][i]=' ';

	lines[line+2][start_cell]='+';
	lines[line+2][end_cell]='+';

	for (int i=start_cell+1;i<end_cell;i++)
		lines[line+2][i]='-';
}

void print_line(int index,vector <LINE> id_alias)
{
	string alias_group;
	int start_cell,end_cell;
	for (int i=0; i<List.days.size();i++)
	{
		for (int j=0;j<List.days[i].size();j++)
		{
			if (List.days[i][j]==input_days[index])
			{
				alias_group = find_alias(i,id_alias) + " (" + List.groups[i][1] + ")";
				start_cell = find_hhmm(i,j,0);
				end_cell = find_hhmm(i,j,1);
				make_frame(lines.size()-1,start_cell,end_cell,alias_group);
			}
		}
	}
}

void print_timetable(int index,vector <LINE> id_alias)
{
	if (index == 7)
		return;
	print_hhmm(index);
	if (is_presentation(index))
		print_line(index,id_alias);
	if (is_presentation(index))
	{
		for (int i=0;i<lines.size();i++)
		{
			for (int j=0;j<lines[i].size();j++)
			{
				if (lines[i][j] != '\0')
					cout<<lines[i][j];
			}
			cout<<endl;
		}
	}
	if (index != 6)
		cout<<endl;
		lines.clear();
		lines.push_back(prog_line);
		lines.push_back(prog_line);
		lines.push_back(prog_line);
	return print_timetable(index + 1,id_alias);
}

int main(int argc, char *argv[])
{
	vector<LINE> id_alias;
	save_courses(argv[1], id_alias);
	save_presentations_list();
	cout<<"# "<<argv[2]<<endl<<endl;
	print_timetable(0,id_alias);
	return 0;
}
