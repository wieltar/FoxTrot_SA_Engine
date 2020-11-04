#pragma once
#define FRAME_VALUES 100
#define TIMESTEP 1.f

class FrameData
{
public:
	API FrameData();
	API ~FrameData();
	API double calculateAverageFps();
	API void startTimer();
	API static double gameFps;
	API static double renderFps;

private:
	list<chrono::duration<double>> frametimes;
	chrono::high_resolution_clock::time_point startTime;
	double framesPerSecond = 0;
};
