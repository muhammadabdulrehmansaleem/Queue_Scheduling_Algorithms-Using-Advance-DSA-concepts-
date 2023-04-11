#include <iostream>
#include"Process.h"
#include"Schedular.h"
using namespace std;
int main()
{
	Process arr[3] = { Process(1,"vlc",12),Process(3,"vsc",4),Process(43,"explorer",20) };
	Schedular s(arr, 3, 5);
	s.assignProcess();
	return 0;
}