#include "Process.h"

using namespace std;

void Process::pushPid()
{
	pids.push_back(pids.size() + 1);
}

void Process::pushTid(string command)
{
	vector<int> temp;
	int spaceIndex = command.find(' ');
	command = command.substr(spaceIndex + 1);
	spaceIndex = command.find(' ');
	int threadNo = atoi(command.substr(0, spaceIndex).c_str());
	for (int i = 0; i < threadNo; i++)
		temp.push_back(i + 1);
	tids.push_back(temp);
	temp.clear();
}

void Process::pushTimeSlice(string command)
{
	vector<int> temp;
	int spaceIndex = command.find(' ');
	command = command.substr(spaceIndex + 1);
	spaceIndex = command.find(' ');
	int threadNo = atoi(command.substr(0, spaceIndex).c_str());
	command = command.substr(spaceIndex + 1);
	for (int i = 0; i < threadNo - 1; i++)
	{
		spaceIndex = command.find(' ');
		temp.push_back(atoi(command.substr(0, spaceIndex).c_str()));
		command = command.substr(spaceIndex + 1);
	}
	temp.push_back(atoi(command.c_str()));
	timeSlices.push_back(temp);
	temp.clear();
}

void Process::addProcess(int &pid, string c)
{
	pushPid();
	cout << "Process with pid = " << pids[pid] << " added!" << endl;
	pushTid(c);
	pushTimeSlice(c);
	pid++;
}

vector<vector<int>>  Process::getTids() { return tids; }

vector<vector<int>> Process::getTimes() { return timeSlices; }
