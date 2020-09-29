#include "SVIEngine.h"

SVIEngine::SVIEngine()
{
}

SVIEngine::~SVIEngine()
{
}

/// @brief Loads audio files
/// @param filename 
void SVIEngine::load(const char* filename)
{
	sviEngine->load(filename);
}

/// @brief 
/// Plays sounds
void SVIEngine::play()
{
	sviEngine->play();
}

/// @brief TO BE REMOVED
/// @param x 
/// @param y 
void SVIEngine::testLoopVideo(int x, int y)
{
	sviEngine->testLoopVideo(x,y);
}

/// @brief 
/// Inits SDL2 and creates the window
void SVIEngine::initSDL()
{
	sviEngine->initSDL();
}

/// @brief 
/// Clears the SDL screen
void SVIEngine::clearScreen()
{
	sviEngine->clearScreen();
}

/// @brief 
/// Draws the SDL screen
void SVIEngine::drawScreen()
{
	sviEngine->drawScreen();
}

/// @brief Loads the PNG files AKA sprites
/// @param spriteID 
/// @param filename
void SVIEngine::loadImage(int spriteID, const char* filename)
{
	sviEngine->loadImage(spriteID, filename);
}

/// @brief Sets the sprite on the screen
/// @param spriteID 
/// @param xPos 
/// @param yPos 
/// @param width 
/// @param height 
/// @param rotation 
void SVIEngine::renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation)
{
	sviEngine->renderCopy(spriteID, xPos, yPos, width, height, rotation);
}

/// @brief 
/// Update all the sprites on the screen
void SVIEngine::updateScreen()
{
	if (pointerToObjectVector->capacity() <= 0) return;
	if (pointerToObjectVector->size() <= 0) return;
	for (auto obj : *pointerToObjectVector) {
		if (obj != nullptr) {
			sviEngine->renderCopy(obj->getSpriteID(), obj->getPositionX(), obj->getPositionY(), obj->getWidth(), obj->getHeight(), obj->getRotation());
		}
	}
}

/// @brief 
/// Update function
void SVIEngine::receiveTick()
{
	clearScreen();
	updateScreen();
	drawScreen();
}

/// @brief 
/// Receives input
void SVIEngine::input()
{
	sviEngine->input();
}
