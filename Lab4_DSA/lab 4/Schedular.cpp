#include<iostream>
#include"Schedular.h"
#include"Queue.h"
using namespace std;
Schedular::Schedular(Process* p, int length, int quantum)
{
	processArray = new Process[length];
	processArrayLength = length;
	for (int i = 0; i < length; i++)
	{
		processArray[i].setprocessInfo(p[i].getPid(), p[i].getProcessName(), p[i].getProcessExecTime());
	}
	timeQuantum = quantum;
}
void Schedular::assignProcess()
{
	Queue<Process>qu(2);
	for (int i = 0; i < processArrayLength; i++)
	{
		qu.enqueue(processArray[i]);
	}
	while (qu.getNoOfElements() != 0)
	{
		Process temp = qu.dequeue();
		cout << "The process currently executing has id: " << temp.getPid() << " its name is: " << temp.getProcessName()<<" and its exec time is: "<<temp.getProcessExecTime() << endl;
		int time = temp.getProcessExecTime();
		if (time <= timeQuantum)
		{
			time = 0;
			temp.setPtime(time);
			if (time == 0)
			{
				cout << "The process having id: " << temp.getPid() << " has completed its execution\n";
			}
		}
		int exectime = 0;
		if (time > timeQuantum)
		{
			time = time - timeQuantum;
			temp.setPtime(time);
			qu.enqueue(temp);
		}
	}
}