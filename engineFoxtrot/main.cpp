#pragma once
#include <iostream>
#include "Engine.h"

#include "box2d/box2d.h"
#include <chrono>
#include "GroundData.h"
#include "PhysicsFacade.h"
#include "Object.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;
PhysicsFacade phy;

int main() {


	//house
	Object* o = new Object(1);
	o->setName("house");
	o->setHeight(80);
	o->setWidth(80);
	o->setX(30);
	o->setY(0);

	o->setSpeed(100);
	o->setJumpHeight(400);
	o->setDensity(1);
	o->setFriction(0);
	o->setRestitution(0);

	phy.temp.push_back(o);
	phy.registerRectangle(o);

	GroundData g;
	g.hx = 500; // width
	g.hy = 10; // height
	g.x = 20; // x 20 left down
	g.y = 300; // y 300 left down
	
	phy.addGround(g);
	



	Object* z = phy.getObject(1);
	for (int32 i = 0; i < 10000; ++i)
	{
		phy.MoveRight(1);
		phy.update();
		Object* z = phy.getObject(1);
		GroundData box;
		box.hx = z->getWidth();
		box.hy = z->getHeight();
		box.x = z->getX();
		box.y = z->getY();
		float x = i;

		printf("counter: %4.2f xPos: %4.2f yPos: %4.2f \n", x, box.x, box.y);
		GroundData paint;
		paint.hx = g.hx;
		paint.hy = g.hy;
		paint.x = g.x;
		paint.y = g.y;

		engine.svi.testLoopVideo(box, paint);
		

		SDL_Delay(10);
	}

	//Engine* engine{ new Engine };
	//engine->addEventListener(new PhysicsEngine, EventType::MOVE);
	//engine->eventManager.notify(EventType::MOVE, new Object);

	cout << "Hello world!" << endl;
	return 0;



	//engine.svi.load("../Assets/Sound/b423b42.wav");
	//engine.svi.play();
	
	//
	//while (1)
	//{
	//	engine.svi.input();
	//}
}


