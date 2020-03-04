#pragma once
#include<chrono>

using namespace std;
using namespace std::chrono;
class Timer
{
private:
	high_resolution_clock::time_point p1;
	high_resolution_clock::time_point p2;

public:
	Timer();


	double restart();
};

double Timer::restart()
{
	p2 = high_resolution_clock::now();
	duration<double> timeDelta = duration_cast<duration<double>>(p2 - p1);
	p1 = high_resolution_clock::now();
	return timeDelta.count();
}

Timer::Timer()
{
	p1 = high_resolution_clock::now();
}