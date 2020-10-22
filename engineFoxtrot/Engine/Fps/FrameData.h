#pragma once
#include <SDL.h>
#include <iostream>

#define FRAME_VALUES 100
#define TIMESTEP 1.f

using namespace std;

class FrameData
{
public:
	FrameData();
	~FrameData();
	float calculateAverageFps();
	void startTimer();
	static double gameFps;
	static double renderFps;

private:
	list<chrono::duration<double>> frametimes;
	chrono::high_resolution_clock::time_point startTime;
	double framespersecond;
};