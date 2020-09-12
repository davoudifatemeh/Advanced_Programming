#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Process
{
  private:
	vector<int> pids;
	vector<vector<int>> tids;
	vector<vector<int>> timeSlices;

  public:
	void pushPid();
	void pushTid(string c);
	void pushTimeSlice(string c);
	void addProcess(int &pid, string c);
	vector<vector<int>> getTids();
	vector<vector<int>> getTimes();
};

#endif
