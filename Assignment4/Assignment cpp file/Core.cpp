#include "Core.h"

using namespace std;

Core::Core(Process *p)
{
	process = p;
}

void Core::pushId()
{
	coreIds.push_back(coreIds.size() + 1);
}

void Core::addCore(int &cid)
{
	vector<int> temp;
	pushId();
	cout << "Core with core ID = " << coreIds[cid] << " successfully added!" << endl;
	coreThreads.push_back(temp);
	coreTimeSlices.push_back(temp);
	cid++;
}

void Core::addThreadToCore(int pid)
{
	for (int i = 0; i < process->getTids()[pid].size(); i++)
	{
		int index = 0;
		for (int j = 0; j < coreIds.size(); j++)
		{
			if (coreThreads[j].size() < coreThreads[index].size())
				index = j;
		}
		coreThreads[index].push_back((pid + 1) * 100 + process->getTids()[pid][i]);
		coreTimeSlices[index].push_back(process->getTimes()[pid][i]);
	}
}

void Core::showCoresStat ()
{
	for (int i = 0; i < coreIds.size(); i++)
  {
    cout << "Core number : " << coreIds[i] <<endl;
    for (int j = 0; j < coreThreads[i].size(); j++)
    {
      cout << "Process ID : " << coreThreads[i][j]/100 << " - " << "Thread ID : " << coreThreads[i][j]%100 << endl;
      cout << "Number of time slots : " << coreTimeSlices[i][j] << endl;
    }
  }
}

void Core::runCores ()
{
  for (int i = 0; i < coreIds.size(); i++)
  {
    if (coreThreads[i].size() != 0)
    {
      cout << "Core number : " << coreIds[i] <<endl;
      cout << "Process ID : " << coreThreads[i][0]/100 << " - " << "Thread ID : " << coreThreads[i][0]%100 << endl;
      if (coreTimeSlices[i][0] - 1 == 0)
      {
        coreThreads[i].erase(coreThreads[i].begin());
        coreTimeSlices[i].erase(coreTimeSlices[i].begin());
      }
      else
      {
        coreThreads[i].push_back(coreThreads[i][0]);
        coreThreads[i].erase(coreThreads[i].begin());
        coreTimeSlices[i].push_back(coreTimeSlices[i][0] - 1);
        coreTimeSlices[i].erase(coreTimeSlices[i].begin());
      }
    }
  }
}

void Core::finishTasks ()
{
  int maxTimeSlice = 0;
  for (int i = 0; i < coreTimeSlices.size(); i++)
  {
    int sum = 0;
    for (int j = 0; j < coreTimeSlices[i].size(); j++)
    {
      sum += coreTimeSlices[i][j];
    }
    if (sum > maxTimeSlice)
      maxTimeSlice = sum;
  }

  for (int i = 0; i < maxTimeSlice; i++)
  {
    cout << "Time Slice : " << i+1 << endl;
    for (int j = 0; j < coreIds.size(); j++)
    {
      if (coreThreads[j].size() != 0)
      {
        cout << "Core number : " << coreIds[j] <<endl;
        cout << "Process ID : " << coreThreads[j][0]/100 << " - " << "Thread ID : " << coreThreads[j][0]%100 << endl;
        if (coreTimeSlices[j][0] - 1 == 0)
        {
          coreThreads[j].erase(coreThreads[j].begin());
          coreTimeSlices[j].erase(coreTimeSlices[j].begin());
        }
        else
        {
          coreThreads[j].push_back(coreThreads[j][0]);
          coreThreads[j].erase(coreThreads[j].begin());
          coreTimeSlices[j].push_back(coreTimeSlices[j][0] - 1);
          coreTimeSlices[j].erase(coreTimeSlices[j].begin());
        }
      }
    }
  }
}
