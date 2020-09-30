#include "SVIEngine.h"

SVIEngine::SVIEngine()
{
}

SVIEngine::~SVIEngine()
{
}

void SVIEngine::testLoopVideo(int x, int y)
{
	sviEngine->testLoopVideo(x,y);
}

void SVIEngine::input()
{
	sviEngine->input();
}
