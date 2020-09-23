#include "SDL.h"
#include "CTimer.h"
#include "CGame.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) 
{
	CTimer time;
	time.setFPS();
	time.TimeContrler();
	while (1)
	{
		for (long long int i = 0; i < 1000000; i++)
		{
			int a = 7;
			a += 7;
		}
		cout << time.GetRealFPS() << endl;
		time.TimeContrler();
	}
    return 0;
	//thank you
}