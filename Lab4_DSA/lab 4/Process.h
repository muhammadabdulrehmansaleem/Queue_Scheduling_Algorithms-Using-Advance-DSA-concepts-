#ifndef PROCESS_H
#define	PROCESS_H
#include<string>
using namespace std;
class Process
{
	int processId;
	string processName;
	int processExecTime;
public:
	Process(int id = 1, string pname = "notepad", int burstTime = 10);
	int getPid();
	string getProcessName();
	int getProcessExecTime();
	void setprocessInfo(int, string, int);
	void setPtime(int);
	void displayProcess();
};
#endif // !PROCESS_H
