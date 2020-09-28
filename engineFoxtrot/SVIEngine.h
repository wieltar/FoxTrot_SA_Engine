#pragma once
#include "SVI.h"
#include "Object.h"
#include <vector>


using namespace std;

struct Sprite
{
	int spriteID = 0;
	const char* filename = "";
};

class SVIEngine
{
public:
	SVIEngine();
	~SVIEngine();
	
	// Sound Functions
	void load(const char* filename);
	void play();

	// Video Functions
	void testLoopVideo(int x, int y);

	void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(int spriteID, const char* filename);
	void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation);

	void updateScreen();

	void receiveTick();

	// Input Functions
	void input();

	vector <Object*> *pointerToObjectVector;


	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
