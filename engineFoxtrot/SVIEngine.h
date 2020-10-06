#pragma once
#include "EventManager.h"
#include "SVI.h"
#include <vector>


using namespace std;

#define MAX_VOLUME 128

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

	// Sound functions
	void SetFiles(map<string, string> files);
	void AddFile(const string& identifier, const string& file);
	void PlayEffect(const string& identifier, int volume);
	void LoadEffect(const string& identifier);
	void UnloadEffect(const string& identifier);
	void StartLoopedEffect(const string& effect);
	void StopLoopedEffect(const string& identifier);
	void LoadMusic(const string& identifier);
	void PlayMusic(int volume);
	void PlayMusic(const string& identifier, int volume);
	void ChangeMusic(const string& identifier);
	void FadeOutMusic(int fadeTime);
	void FadeInMusic(int fadeTime);
	void FadeInMusic(const string& identifier, int fadeTime);
	void RewindMusic();
	void StopMusic();
	void PauseMusic();
	void ResumeMusic();
	void Flush();
	void onPlayEffect(const string& identifier, int volume);
	void onChangeBackgroundMusic(const string& identifier, int volume);

	bool IdentifierExists(const string& identifier);
	bool IdentifierIsLoaded(const string& identifier);

	vector <Object*> *pointerToObjectVector = nullptr;


	//Set to private after testing!!!
	EventManager* eventManager = nullptr;
	ISVI * sviFacade = new SVI;
private:
};
