#include "glpch.h"
#include "Renderer2d.h"

namespace Glitch {

	/// @brief 
	/// Inits SDL2 renderer on window
	void Renderer2d::Init()
	{
		facadeTest->createRenderer();

	}

	void Renderer2d::OnUpdate()
	{
		clearScreen();
		drawScreen();
		// TODO draw object vector
	}

	void Renderer2d::Shutdown()
	{
		//facadeTest.deallocateSurface();
	}

	/// @brief 
	/// Clears SDL screen
	void Renderer2d::clearScreen()
	{
		facadeTest->clearScreen();
	}

	/// @brief 
	/// Draws SDL screen
	void Renderer2d::drawScreen()
	{
		facadeTest->drawScreen();
	}

	/// @brief 
	/// Loads PNG files and makes them textures to be added to the unordered map
	/// @param spriteID 
	/// @param filename 
	void Renderer2d::loadImage(int spriteID, const char* filename)
	{
		facadeTest->loadImage(spriteID, filename);
	}

	/// @brief 
	/// Takes the sprites from the Textuture map and copys them to the screen
	/// @param spriteID 
	/// @param xPos 
	/// @param yPos 
	/// @param width 
	/// @param height 
	/// @param rotation 
	void Renderer2d::renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation)
	{
		facadeTest->renderCopy(spriteID, xPos, yPos, width, height, rotation);
	}


}