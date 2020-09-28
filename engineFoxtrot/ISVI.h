#pragma once

class ISVI
{
public:
	ISVI();
	~ISVI();

	// Sound Functions
	virtual void load(const char* filename) = 0;
	virtual void play() = 0;

	// Video Functions
	virtual void testLoopVideo(int x, int y) = 0;

	virtual void initSDL() = 0;

	virtual void clearScreen() = 0;
	virtual void drawScreen() = 0;
	virtual void loadImage(int spriteID, const char* filename) = 0;

	virtual void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation) = 0;


	// Input Functions
	virtual void input() = 0;

private:

};
