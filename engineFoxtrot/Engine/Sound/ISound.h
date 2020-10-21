#pragma once

/// @brief Interface class for Sound facade
#if(EXPORT)
class DLLEXPORT ISVI
#else
class ISound
#endif
{
public:
	ISound() {};
	~ISound() {};

	virtual bool isMix_PlayingMusic() = 0;
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
