#pragma once

#define FRAME_VALUES 100
#define TIMESTEP 1.f

#if(EXPORT)
class DLLEXPORT FrameData
#else
class FrameData
#endif
{
public:
	FrameData();
	~FrameData();
	double calculateAverageFps();
	void startTimer();
	static double gameFps;
	static double renderFps;

private:
	list<chrono::duration<double>> frametimes;
	chrono::high_resolution_clock::time_point startTime;
	double framesPerSecond = 0;
};