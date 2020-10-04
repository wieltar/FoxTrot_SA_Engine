#pragma once
#include "EventManager.h"
#include "SVI.h"
#include <vector>


using namespace std;

#if(EXPORT)
struct DLLEXPORT Sprite
#else
struct Sprite
#endif
{
	int spriteID = 0;
	const char* filename = "";
};

/// @brief 
/// SVIEngine is the SDL2 wrapper

#if(EXPORT)
class DLLEXPORT SVIEngine
#else
class SVIEngine : public EventListener
#endif
{
public:
	SVIEngine();
	~SVIEngine();
	
	// Sound Functions
	void load(const char* filename);
	void play();

	// Video Functions
	void testLoopVideo(Object& g, Object& b);

	void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(int spriteID, const char* filename);
	void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation);

	void updateScreen();

	void update(Object* object) override;
	void receiveTick();

	// Input Functions
	void input();

	vector <Object*> *pointerToObjectVector = nullptr;


	//Set to private after testing!!!
	EventManager* eventManager = nullptr;
	ISVI * sviEngine = new SVI;
private:
};
