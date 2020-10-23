#include "stdafx.h"
#include "FrameData.h"

double FrameData::gameFps = 0;
double FrameData::renderFps = 0;

FrameData::FrameData() {
	framespersecond = 0;
	//frametimelast = SDL_GetTicks();
}

FrameData::~FrameData() {
	
}

/// @brief
/// Sets the start time for the fps counter (use at beginning of loop)
void FrameData::startTimer() {
	startTime = chrono::high_resolution_clock::now();
}

/// @brief
/// Calculates the average fps of the last few ticks
float FrameData::calculateAverageFps()
{
	chrono::high_resolution_clock::time_point endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = chrono::duration_cast<chrono::duration<double>>(endTime - startTime);
	double avgFps = 0;

	if (frametimes.size() >= FRAME_VALUES) {
		frametimes.pop_front();
	}
	frametimes.push_back(diff);

	for (auto const &time : frametimes) {
		avgFps += time.count();
	}

	avgFps /= frametimes.size();

	framespersecond = TIMESTEP / avgFps;
	return framespersecond;
}