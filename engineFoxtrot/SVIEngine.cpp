#include "SVIEngine.h"

SVIEngine::SVIEngine()
{
}

SVIEngine::~SVIEngine()
{
}

void SVIEngine::load(string filename, string identifier)
{
	sviEngine->load(filename, identifier);
}

void SVIEngine::play(string identifier)
{
	sviEngine->play(identifier);
}

void SVIEngine::stop(string identifier)
{
	sviEngine->stop(identifier);
}

void SVIEngine::unload(string identifier)
{
	sviEngine->unload(identifier);
}

void SVIEngine::flush()
{
	sviEngine->flush();
}

void SVIEngine::testLoopVideo(int x, int y)
{
	sviEngine->testLoopVideo(x,y);
}

void SVIEngine::input()
{
	sviEngine->input();
}
