#pragma once
#include "../Events/EventManager.h"
#include "./VideoFacade.h"


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
/// Video is the SDL2 wrapper

#if(EXPORT)
class DLLEXPORT VideoEngine
#else
class VideoEngine : public EventListener
#endif
{
public:
	VideoEngine();
	~VideoEngine();

	void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(const int spriteID, const char* filename);

	void renderCopy(Object& object);

	void updateScreen();

	void update(Object* object) override;
	void receiveTick();

	vector <Object*>* pointerToObjectVector = nullptr;

	//Set to private after testing!!!
	EventManager* eventManager = nullptr;
	IVideo* videoFacade = new VideoFacade;

private:
};
