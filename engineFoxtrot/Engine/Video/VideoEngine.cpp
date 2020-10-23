#include "stdafx.h"
#include <Events\AppTickEvent60.h>
#include <Events\EventSingleton.h>
#include "VideoEngine.h"

VideoEngine::VideoEngine()
{
	frameData = new FrameData;
	EventSingleton::get_instance().setEventCallback<AppTickEvent60>(BIND_EVENT_FN(VideoEngine::receiveTick));
}

VideoEngine::~VideoEngine()
{
}

/// @brief 
/// Inits SDL2 and creates the window
void VideoEngine::initSDL()
{
	try
	{
		videoFacade->initSDL();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Clears the SDL screen
void VideoEngine::clearScreen()
{
	try
	{
		videoFacade->clearScreen();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Draws the SDL screen
void VideoEngine::drawScreen()
{
	try
	{
		videoFacade->drawScreen();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief Loads the PNG files AKA sprites
/// @param spriteID 
/// @param filename
void VideoEngine::loadImage(int spriteID, const char* filename)
{
	try
	{
		videoFacade->loadImage(spriteID, filename);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief Sets the sprite on the screen
/// @param Object 
void VideoEngine::renderCopy(Object& object) {
	try
	{
		videoFacade->renderCopy(object);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Update all the sprites on the screen
void VideoEngine::updateScreen()
{
	try
	{
		if (pointerToObjectVector == nullptr) return;
		//if (pointerToObjectVector->capacity() <= 0) return;
		if (pointerToObjectVector->size() <= 0) return;
		for (Object* obj : *pointerToObjectVector) {
			if (obj != nullptr) {
				videoFacade->renderCopy(*obj);
			}
		}
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

void VideoEngine::drawFps() {
	drawFps(FrameData::gameFps, FPS_X, Y_ZERO, "Game Fps: ");
	drawFps(FrameData::renderFps, FPS_X, SDL_FPS_Y, "SDL Fps: ");
}

void VideoEngine::drawFps(double fps, int xPos, int yPos, const string& prefix = "fps: ") {
	ostringstream stre;
	stre << prefix << fps;
	string str = stre.str();
	if (shouldDrawFps) {
		Message m(str, NO_RED, NO_BLUE, NO_GREEN);
		Position p(xPos, yPos);
		videoFacade->drawMessageAt(m, p);
	}
}

void VideoEngine::toggleFps() {
	shouldDrawFps = !shouldDrawFps;
}

/// @brief 
/// Update function
void VideoEngine::update(Object* object)
{
	clearScreen();
	updateScreen();
	drawScreen();
}

/// @brief Handle the tick update from the thread
void VideoEngine::receiveTick(Event& tickEvent)
{
	//tickEvent = static_cast<AppTickEvent&>(tickEvent);
	frameData->startTimer();
	clearScreen();
	updateScreen();
	drawFps();
	drawScreen();
	FrameData::renderFps = frameData->calculateAverageFps();
}