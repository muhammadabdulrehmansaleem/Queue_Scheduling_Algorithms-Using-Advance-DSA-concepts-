#include<iostream>
#include "Process.h"
#include<string>
using namespace std;
Process::Process(int id, string pname, int burstTime)
{
	processId = id;
	processName = pname;
	processExecTime = burstTime;
}
int Process:: getPid()
{
	return processId;
}
string Process::getProcessName()
{
	return processName;
}
int Process:: getProcessExecTime()
{
	return processExecTime;
}
void Process::setprocessInfo(int id, string name, int time)
{
	processId = id;
	processName = name;
	processExecTime = time;
}
void Process::setPtime(int t)
{
	processExecTime = t;
}
void Process::displayProcess()
{
	cout << "Name of the process is: " << processName << " and its id: " << processId << " it requires: " << processExecTime << " time for its execution\n";
}