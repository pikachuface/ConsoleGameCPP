#pragma once
#include<ctime>
#include<stdlib.h>
class RandomNum
{
public:
	//Generates random number in range
	//returns Void
	static int newNum(unsigned int max, unsigned int min = 0)
	{
		srand((unsigned)time(0));
		int result = min + (rand() % ((max-min) + 1));
		return result;
	}
};

