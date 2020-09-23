#pragma once
#include "SVI.h"
#include "Object.h"
#include <vector>


using namespace std;

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
	void updateScreen();
	void loadImage(int spriteID, const char* filename);

	void renderCopy(int spriteID, int xPos, int yPos, int width, int height);

	// Input Functions
	void input();

	vector <Object*> *pointerToObjectVector;
	vector <Object> objects;


	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
