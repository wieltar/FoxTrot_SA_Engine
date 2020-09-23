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
	void drawScreen();
	void loadImage(int spriteID, const char* filename);
	void renderCopy(int spriteID, int xPos, int yPos, int width, int height);

	void updateScreen(vector<Object> objects);

	void receiveTick();

	// Input Functions
	void input();

	vector <Object*> *pointerToObjectVector;
	vector <Object> objects;
	// TODO: in de wrapper een foreach maken om door de vector te lopen en de sprites te tekenen.


	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
