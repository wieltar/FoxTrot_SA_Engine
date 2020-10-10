#pragma once
#include "Object.h"
#include <map>

/// @brief Interface class for SDL2 facade
#if(EXPORT)
class DLLEXPORT ISVI
#else
class ISVI
#endif
{
public:
	ISVI() {};
	~ISVI() {};

	// Video Functions
	virtual void initSDL() = 0;

	virtual void clearScreen() = 0;
	virtual void drawScreen() = 0;
	virtual void loadImage(const int spriteID, const char* filename) = 0;

	//TODO delete this is only for POC
	virtual void renderCopy(const int spriteID, const int xPos, const int yPos, const int width, const int height, const int rotation) = 0;

	virtual void renderCopy(Object& object) = 0;


	// Input Functions
	virtual void input() = 0;

	// Sound Functions
	virtual void SetFiles(std::map<std::string, std::string> files) = 0;
	virtual void AddFile(const std::string& identifier, const std::string& file) = 0;
	virtual void PlayEffect(const std::string& identifier, const int volume) = 0;
	virtual void LoadEffect(const std::string& identifier) = 0;
	virtual void UnloadEffect(const std::string& identifier) = 0;
	virtual void StartLoopedEffect(const std::string& effect) = 0;
	virtual void StopLoopedEffect(const std::string& identifier) = 0;
	virtual void LoadMusic(const std::string& identifier) = 0;
	virtual void PlayMusic(const int volume) = 0;
	virtual void PlayMusic(const std::string& identifier, const int volume) = 0;
	virtual void ChangeMusic(const std::string& identifier) = 0;
	virtual void FadeOutMusic(const int fadeTime) = 0;
	virtual void FadeInMusic(const int fadeTime) = 0;
	virtual void FadeInMusic(const std::string& identifier, const int fadeTime) = 0;
	virtual void RewindMusic() = 0;
	virtual void StopMusic() = 0;
	virtual void PauseMusic() = 0;
	virtual void ResumeMusic() = 0;
	virtual void Flush() = 0;

	virtual bool IdentifierExists(const std::string& identifier) = 0;
	virtual bool IdentifierIsLoaded(const std::string& identifier) = 0;

private:

};
