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

	// Input Functions
	void input();

	vector <int*> pointerToObjectVector;
	vector <Object> objects;


	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
