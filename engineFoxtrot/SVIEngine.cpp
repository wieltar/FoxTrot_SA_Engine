#include "SVIEngine.h"

SVIEngine::SVIEngine()
{
}

SVIEngine::~SVIEngine()
{
}

/// @brief 
/// Inits SDL2 and creates the window
void SVIEngine::initSDL()
{
	try
	{
		sviFacade->initSDL();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Clears the SDL screen
void SVIEngine::clearScreen()
{
	try
	{
		sviFacade->clearScreen();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Draws the SDL screen
void SVIEngine::drawScreen()
{
	try
	{
		sviFacade->drawScreen();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief Loads the PNG files AKA sprites
/// @param spriteID 
/// @param filename
void SVIEngine::loadImage(int spriteID, const char* filename)
{
	try
	{
		sviFacade->loadImage(spriteID, filename);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

//TODO delete this is only for POC
void SVIEngine::renderCopy(const int spriteID, const int xPos, const int yPos, const int width, const int height, const int rotation)
{
	try
	{
		sviFacade->renderCopy(spriteID, xPos, yPos, width, height, rotation);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}
/// @brief Sets the sprite on the screen
/// @param Object 
void SVIEngine::renderCopy(Object& object) {
	try
	{
		sviFacade->renderCopy(object);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Update all the sprites on the screen
void SVIEngine::updateScreen()
{
	try
	{
		if (pointerToObjectVector == nullptr) return;
		//if (pointerToObjectVector->capacity() <= 0) return;
		if (pointerToObjectVector->size() <= 0) return;
		for (Object * obj : *pointerToObjectVector) {
			if (obj != nullptr) {
				sviFacade->renderCopy(*obj);
			}
		}
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Update function
void SVIEngine::update(Object* object)
{
	
	clearScreen();
	updateScreen();
	drawScreen();
}

/// @brief Handle the tick update from the thread
void SVIEngine::receiveTick()
{
	clearScreen();
	updateScreen();
	drawScreen();
}

/// @brief 
/// Receives input
void SVIEngine::input()
{
	sviFacade->input();
}

/// @brief 
/// @param files 
void SVIEngine::SetFiles(map<string, string> files)
{
	sviFacade->SetFiles(files);
}
/// @brief 
/// @param identifier 
/// @param file 
void SVIEngine::AddFile(const string& identifier, const string& file)
{
	sviFacade->AddFile(identifier, file);
}
/// @brief 
/// @param effect 
/// @param volume 
void SVIEngine::PlayEffect(const string& effect, int volume = MAX_VOLUME)
{
	sviFacade->PlayEffect(effect, volume);
}
/// @brief 
/// @param identifier 
void SVIEngine::LoadEffect(const string& identifier)
{
	sviFacade->LoadEffect(identifier);
}
/// @brief 
/// @param identifier 
void SVIEngine::UnloadEffect(const string& identifier)
{
	sviFacade->UnloadEffect(identifier);
}
/// @brief 
/// @param effect 
void SVIEngine::StartLoopedEffect(const string& effect)
{
	sviFacade->StartLoopedEffect(effect);
}
/// @brief 
/// @param identifier 
void SVIEngine::StopLoopedEffect(const string& identifier)
{
	sviFacade->StopLoopedEffect(identifier);
}
/// @brief 
/// @param identifier 
void SVIEngine::LoadMusic(const string& identifier)
{
	sviFacade->LoadMusic(identifier);
}
/// @brief 
/// @param volume 
void SVIEngine::PlayMusic(int volume = MAX_VOLUME)
{
	sviFacade->PlayMusic(volume);
}
/// @brief 
/// @param identifier 
/// @param volume 
void SVIEngine::PlayMusic(const string& identifier, int volume = MAX_VOLUME)
{
	sviFacade->PlayMusic(identifier, volume);
}
/// @brief 
/// @param identifier 
void SVIEngine::ChangeMusic(const string& identifier)
{
	sviFacade->ChangeMusic(identifier);
}
/// @brief 
/// @param fadeTime 
void SVIEngine::FadeOutMusic(int fadeTime)
{
	sviFacade->FadeOutMusic(fadeTime);
}
/// @brief 
/// @param fadeTime 
void SVIEngine::FadeInMusic(int fadeTime)
{
	sviFacade->FadeInMusic(fadeTime);
}
/// @brief 
/// @param identifier 
/// @param fadeTime 
void SVIEngine::FadeInMusic(const string& identifier, int fadeTime)
{
	sviFacade->FadeInMusic(identifier, fadeTime);
}
/// @brief 
void SVIEngine::RewindMusic()
{
	sviFacade->RewindMusic();
}
/// @brief 
void SVIEngine::StopMusic()
{
	sviFacade->StopMusic();
}
/// @brief 
void SVIEngine::PauseMusic()
{
	sviFacade->PauseMusic();
}
/// @brief 
void SVIEngine::ResumeMusic()
{
	sviFacade->ResumeMusic();
}
/// @brief 
void SVIEngine::Flush()
{
	sviFacade->Flush();
}

/// @brief
/// Event listener for when the music has to be changed
/// @param identifier
/// The identifier of the music to play
/// @param volume
/// The volume to play the music at. Ranges from 0 to 128
void SVIEngine::onChangeBackgroundMusic(const string& identifier, int volume = MIX_MAX_VOLUME) {
	if (IdentifierExists(identifier)) {
		if (Mix_PlayingMusic()) {
			ChangeMusic(identifier);
		}
		else {
			LoadMusic(identifier);
			PlayMusic(volume);
		}
	}
}

/// @brief
/// Event listener for when an effect has to be played
/// @param identifier
/// The identifier of the effect to play
/// @param volume
/// The volume to play the effect at. Ranges from 0 to 128
void SVIEngine::onPlayEffect(const string& identifier, const int volume = MIX_MAX_VOLUME) {
	if (IdentifierExists(identifier)) {
		if (IdentifierIsLoaded(identifier)) {
			PlayEffect(identifier, volume);
		}
		else {
			LoadEffect(identifier);
			PlayEffect(identifier, volume);
		}
	}
}

/// @brief 
/// @param identifier 
/// @return 
bool SVIEngine::IdentifierExists(const string& identifier)
{
	return sviFacade->IdentifierExists(identifier);
}

/// @brief 
/// @param identifier 
/// @return 
bool SVIEngine::IdentifierIsLoaded(const string& identifier)
{
	return sviFacade->IdentifierIsLoaded(identifier);
}
