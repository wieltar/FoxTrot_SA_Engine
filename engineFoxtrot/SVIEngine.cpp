#include "SVIEngine.h"
#include "GroundData.h"

SVIEngine::SVIEngine()
{
}

SVIEngine::~SVIEngine()
{
}

void SVIEngine::load(const char* filename)
{
	sviEngine->load(filename);
}

void SVIEngine::play()
{
	sviEngine->play();
}

void SVIEngine::testLoopVideo(int x, int y, GroundData g)
{
	sviEngine->testLoopVideo(x,y, g);
}

void SVIEngine::input()
{
	sviEngine->input();
}
