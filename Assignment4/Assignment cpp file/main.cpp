#include "Process.h"
#include "Core.h"

using namespace std;

int main()
{
	string command;
	Process p;
	Core c(&p);
	int cid = 0;
	int pid = 0;
	while (getline(cin, command))
	{
		if (command == "add_core")
			c.addCore(cid);
		if (command.substr(0, 11) == "add_process")
		{
			p.addProcess(pid, command);
			c.addThreadToCore(pid - 1);
		}
    if (command == "show_cores_stat")
       c.showCoresStat();
    if (command == "run_cores")
      c.runCores();
    if (command == "finish_tasks")
      c.finishTasks();
	}
	return 0;
}
