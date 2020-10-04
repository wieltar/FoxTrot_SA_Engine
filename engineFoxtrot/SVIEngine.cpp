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

void SVIEngine::testLoopVideo(GroundData box, GroundData g)
{
	sviEngine->testLoopVideo(box, g);
}

void SVIEngine::input()
{
	sviEngine->input();
}
