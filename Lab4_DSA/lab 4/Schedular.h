#ifndef SCHEDULAR_H
#define SCHEDUAR_H
#include"Process.h"
class Schedular
{
	Process* processArray;
	int processArrayLength;
	int timeQuantum;
public:
	Schedular(Process*, int, int);
	void assignProcess();
};
#endif // !SCHEDULAR_H
