#include "SVIEngine.h"

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

void SVIEngine::testLoopVideo(int x, int y)
{
	sviEngine->testLoopVideo(x,y);
}

void SVIEngine::initSDL()
{
	sviEngine->initSDL();
}

void SVIEngine::clearScreen()
{
	sviEngine->clearScreen();
}

void SVIEngine::drawScreen()
{
	sviEngine->drawScreen();
}

void SVIEngine::loadImage(int spriteID, const char* filename)
{
	sviEngine->loadImage(spriteID, filename);
}

void SVIEngine::renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation)
{
	sviEngine->renderCopy(spriteID, xPos, yPos, width, height, rotation);
}

void SVIEngine::updateScreen()
{
	for (auto obj : *pointerToObjectVector) {
		sviEngine->renderCopy(obj->getSpriteID(), obj->getPositionX(), obj->getPositionY(), obj->getWidth(), obj->getHeight(),obj->getRotation());
	}
}

void SVIEngine::receiveTick()
{
	clearScreen();
	updateScreen();
	drawScreen();
}

void SVIEngine::input()
{
	sviEngine->input();
}
