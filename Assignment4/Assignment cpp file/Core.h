#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <vector>
#include <string>
#include "Process.h"

using namespace std;

class Process;

class Core
{
  private:
	vector<int> coreIds;
	vector<vector<int>> coreThreads;
	vector<vector<int>> coreTimeSlices;
	Process *process;

  public:
	Core(Process *p);
	void pushId();
	void addCore(int &cid);
	void addThreadToCore(int pid);
	void showCoresStat ();
  void runCores ();
  void finishTasks ();
};

#endif
