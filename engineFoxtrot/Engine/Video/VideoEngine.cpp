#include "stdafx.h"
#include <Events\AppTickEvent60.h>
#include <Events\EventSingleton.h>
#include "VideoEngine.h"

VideoEngine::VideoEngine()
{
	frameData = new FrameData;
	EventSingleton::get_instance().setEventCallback<AppTickEvent60>(BIND_EVENT_FN(VideoEngine::receiveTick));
	EventSingleton::get_instance().setEventCallback<FpsToggleEvent>(BIND_EVENT_FN(VideoEngine::toggleFps));
}

VideoEngine::~VideoEngine()
{
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
void VideoEngine::loadImage(const SpriteObject& spriteObject)
{
	try
	{
		videoFacade->loadImage(spriteObject);
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
		if (pointerToCurrentScene == nullptr) return;
		//if (pointerToObjectVector->capacity() <= 0) return;
		if ((*pointerToCurrentScene)->getAllObjectsInScene().size() <= 0) return;
		for (Object* obj : (*pointerToCurrentScene)->getAllObjectsInScene()) {
			if (obj != nullptr) {
				if (obj->getIsParticle())
				{
					drawParticle((ParticleAdapter*)obj);
				}
				else
				{
					renderCopy(*obj);
				}
			}
		}
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief
/// Calls the drawFps method with parameters for all calculated Fps types
void VideoEngine::drawFps() {
	//drawFps(FrameData::gameFps, FPS_X_POSITION, Y_POSITION_TOP_OF_SCREEN, "Game Fps: ");
	drawFps(FrameData::renderFps, FPS_X_POSITION, FPS_Y_POSITION_OFFSET, "Fps: ");
}

/// @brief
/// Gathers the given fps data, stores them in structs and passes the data to the videofacade if fps should be drawn
/// @param fps
/// The fps to show on screen
/// @param xPos
/// The X position of where the fps should be drawn
/// @param yPos
/// The Y position of where the fps should be drawn
/// @param prefix
/// The prefix message for the fps
void VideoEngine::drawFps(double fps, int xPos, int yPos, const string& prefix = "fps: ") {
	ostringstream stre;
	stre << prefix << fps;
	string str = stre.str();
	if (shouldDrawFps) {
		FpsMessage m(str, NO_RED, NO_BLUE, NO_GREEN);
		TextPosition p(xPos, yPos);
		videoFacade->drawMessageAt(m, p);
	}
}

/// @brief
/// Toggles fps visibility
void VideoEngine::toggleFps(Event& fpsEvent) {
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

/// @brief Draws the Particles
/// @param part pointer to the particle
void VideoEngine::drawParticle(ParticleAdapter* part)
{
	vector<ParticleData> particleData = part->getParticleDataVector();
	for (unsigned int index = 0; index < part->getParticleCount(); index++)
	{
		auto& partData = particleData[index];

		if (partData.size <= 0 || partData.colorA <= 0)
		{
			continue;
		}
		videoFacade->drawParticle(partData, part->getObjectId());
	}

}
