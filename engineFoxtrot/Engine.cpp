#include "Engine.h"


Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::initScene()
{
	// TODO: Set object list to other object list
	registerSceneManagerPointerWithSVIPointer();
}

void Engine::registerSceneManagerPointerWithSVIPointer()
{
	svi.pointerToObjectVector = &sceneManager.pointerToCurrentObjectVector;
}

void Engine::loadSpriteArray(vector<Sprite> spritesVector)
{
	cout << spritesVector.size() << endl;
	for (auto sprite : spritesVector) {
		cout << sprite.spriteID << "," << sprite.filename << endl;
		svi.loadImage(sprite.spriteID, sprite.filename);
	}
}

void Engine::TESTfillSpriteVector()
{
	Sprite sprite;

	sprite.spriteID = 1;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-00.png";
	sprites.push_back(sprite);

	sprite.spriteID = 2;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-01.png";
	sprites.push_back(sprite);

	sprite.spriteID = 3;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-02.png";
	sprites.push_back(sprite);

	sprite.spriteID = 4;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-03.png";
	sprites.push_back(sprite);

	sprite.spriteID = 5;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-00.png";
	sprites.push_back(sprite);

	sprite.spriteID = 6;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-01.png";
	sprites.push_back(sprite);

	sprite.spriteID = 7;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-02.png";
	sprites.push_back(sprite);

	sprite.spriteID = 8;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-03.png";
	sprites.push_back(sprite);

	sprite.spriteID = 9;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-04.png";
	sprites.push_back(sprite);

	sprite.spriteID = 10;
	sprite.filename = "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/helmet_02a.png";
	sprites.push_back(sprite);

	//for (auto sprite : sprites) {
	//	cout << sprite.spriteID << endl;
	//	cout << sprite.filename << endl;
	//}

}

