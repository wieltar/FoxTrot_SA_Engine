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

/// @brief Sets the sprite on the screen
/// @param spriteID 
/// @param xPos 
/// @param yPos 
/// @param width 
/// @param height 
/// @param rotation 
void SVIEngine::renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation)
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

/// @brief 
/// Update all the sprites on the screen
void SVIEngine::updateScreen()
{
	try
	{
		if (pointerToObjectVector == nullptr) return;
		//if (pointerToObjectVector->capacity() <= 0) return;
		if (pointerToObjectVector->size() <= 0) return;
		for (auto obj : *pointerToObjectVector) {
			if (obj != nullptr) {
				//sviFacade->renderCopy(obj->getSpriteID(), obj->getPositionX(), obj->getPositionY(), obj->getWidth(), obj->getHeight(), obj->getRotation());
				sviFacade->renderCopy(obj);
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

//Sound 
void SVIEngine::SetFiles(map<string, string> files)
{
	sviFacade->SetFiles(files);
}
void SVIEngine::AddFile(const string& identifier, const string& file)
{
	sviFacade->AddFile(identifier, file);
}
void SVIEngine::PlayEffect(const string& effect, int volume = MAX_VOLUME)
{
	sviFacade->PlayEffect(effect, volume);
}
void SVIEngine::LoadEffect(const string& identifier)
{
	sviFacade->LoadEffect(identifier);
}
void SVIEngine::UnloadEffect(const string& identifier)
{
	sviFacade->UnloadEffect(identifier);
}
void SVIEngine::StartLoopedEffect(const string& effect)
{
	sviFacade->StartLoopedEffect(effect);
}
void SVIEngine::StopLoopedEffect(const string& identifier)
{
	sviFacade->StopLoopedEffect(identifier);
}
void SVIEngine::LoadMusic(const string& identifier)
{
	sviFacade->LoadMusic(identifier);
}
void SVIEngine::PlayMusic(int volume = MAX_VOLUME)
{
	sviFacade->PlayMusic(volume);
}
void SVIEngine::PlayMusic(const string& identifier, int volume = MAX_VOLUME)
{
	sviFacade->PlayMusic(identifier, volume);
}
void SVIEngine::ChangeMusic(const string& identifier)
{
	sviFacade->ChangeMusic(identifier);
}
void SVIEngine::FadeOutMusic(int fadeTime)
{
	sviFacade->FadeOutMusic(fadeTime);
}
void SVIEngine::FadeInMusic(int fadeTime)
{
	sviFacade->FadeInMusic(fadeTime);
}
void SVIEngine::FadeInMusic(const string& identifier, int fadeTime)
{
	sviFacade->FadeInMusic(identifier, fadeTime);
}
void SVIEngine::RewindMusic()
{
	sviFacade->RewindMusic();
}
void SVIEngine::StopMusic()
{
	sviFacade->StopMusic();
}
void SVIEngine::PauseMusic()
{
	sviFacade->PauseMusic();
}
void SVIEngine::ResumeMusic()
{
	sviFacade->ResumeMusic();
}
void SVIEngine::Flush()
{
	sviFacade->Flush();
}

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

void SVIEngine::onPlayEffect(const string& identifier, int volume = MIX_MAX_VOLUME) {
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

bool SVIEngine::IdentifierExists(const string& identifier)
{
	return sviFacade->IdentifierExists(identifier);
}

bool SVIEngine::IdentifierIsLoaded(const string& identifier)
{
	return sviFacade->IdentifierIsLoaded(identifier);
}
