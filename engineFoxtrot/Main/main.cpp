#pragma once
#include "stdafx.h"
#include "../Engine/Engine.h"
#include "../Engine/Events/AppTickEvent30.h"
#include "../Engine/Events/AppTickEvent60.h"

#include "Events/Window/WindowCloseEvent.h"

#include "./ParticlesTest/ParticleExample.h"
#include "SDL.h"
#undef main

// TODO engine.h & engine.cpp

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

//Engine engine;

//void sceneTestSetup()
//{
//
//	engine.linkSpriteIDWithAssetPath(1, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-00.png");
//	engine.linkSpriteIDWithAssetPath(2, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-01.png");
//	engine.linkSpriteIDWithAssetPath(3, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-02.png");
//	engine.linkSpriteIDWithAssetPath(4, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-03.png");
//	engine.linkSpriteIDWithAssetPath(5, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-00.png");
//	engine.linkSpriteIDWithAssetPath(6, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-01.png");
//	engine.linkSpriteIDWithAssetPath(7, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-02.png");
//	engine.linkSpriteIDWithAssetPath(8, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-03.png");
//	engine.linkSpriteIDWithAssetPath(9, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-04.png");
//	engine.linkSpriteIDWithAssetPath(10, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/helmet_02a.png");
//	engine.linkSpriteIDWithAssetPath(101, "../Assets/Sprites/Project assets/LIGHT TILE WITHOUT TOP.png");
//
//	Scene* testScene = new Scene(3);
//
//	Object* object = new Object(1);
//	object->setName("house");
//	object->setHeight(80);
//	object->setWidth(80);
//	object->setPositionX(30);
//	object->setPositionY(80);
//	object->setSpeed(100);
//	object->setJumpHeight(400);
//	object->setDensity(10);
//	object->setFriction(0);
//	object->setRestitution(0);
//	object->setStatic(false);
//
//	testScene->addNewObjectToLayer(1, object);
//	
//	Object* object2 = new Object(2);
//	object2->setName("person");
//	object2->setHeight(80);
//	object2->setWidth(80);
//	object2->setPositionX(100);
//	object2->setPositionY(80);
//	object2->setSpeed(100000);
//	object2->setJumpHeight(4000000);
//	object2->setDensity(10);
//	object2->setFriction(0);
//	object2->setRestitution(0);
//	object2->setStatic(false);
//	testScene->addNewObjectToLayer(1, object2);
//
//	Object* staticGround = new Object(101);
//	staticGround->setWidth(500); // width
//	staticGround->setHeight(10);// height
//	staticGround->setPositionX(20); // x 20 left down
//	staticGround->setPositionY(300);// y 300 left down
//	staticGround->setStatic(true);
//	testScene->addNewObjectToLayer(1, staticGround);
//	
//	engine.insertScene(testScene);
//	engine.insertScene(new Scene(4));
//
//	engine.configureInput(KEY_A, new MoveLeft);
//	engine.configureInput(KEY_D, new MoveRight);
//	engine.configureInput(KEY_SPACE, new Jump);
//
//	engine.setCurrentScene(3);
//	engine.startTickThreads();
//}

int main() {
	//sceneTestSetup();

	//bool gameRunning = true;
	//while (gameRunning)
	//{
	//	AppTickEvent60 appTick;
	//	AppTickEvent30 appTick30;

	//	engine.pollInput();
	//	EventSingleton::get_instance().dispatchEvent<AppTickEvent60>(appTick);
	//	EventSingleton::get_instance().dispatchEvent<AppTickEvent30>(appTick30);


	//	this_thread::sleep_for(chrono::milliseconds(10));
	//}

	/*return 0;*/
	SDL_Init(SDL_INIT_VIDEO);
	auto win = SDL_CreateWindow("SDL2 Particles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL);
	auto ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	auto p = new ParticleExample();        // create a new particle system pointer
	p->setRenderer(ren);                   // set the renderer
	p->setPosition(512, 384);              // set the position
	p->setStyle(ParticleExample::FIRE);    // set the example effects
	p->setStartSpin(0);
	p->setStartSpinVar(90);
	p->setEndSpin(90);
	p->setStartSpinVar(90);

	while (1)
	{
		SDL_Event e;
		SDL_PollEvent(&e);
		if (e.type == SDL_KEYUP)
		{
			int s = (e.key.keysym.sym - SDLK_a + 1);
			p->setStyle(ParticleExample::PatticleStyle(s));    // switch the example effects
		}
		if (e.type == SDL_QUIT)
		{
			break;
		}

		SDL_RenderClear(ren);
		p->draw();    // you have to draw it in each loop
		SDL_RenderPresent(ren);
		SDL_Delay(10);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	delete p;    // destroy it

	return 0;
}
