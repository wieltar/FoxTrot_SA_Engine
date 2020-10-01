#pragma once
#include <iostream>
#include "Engine.h"

#include "box2d/box2d.h"
#include <chrono>
#include "GroundData.h"
#include "PhysicsFacade.h"
#include "Object.h"

using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;
PhysicsFacade phy;


void moves(int i) {
	if (i == 10) {
		phy.JumpRight(1);
	}if (i == 100) {
		phy.JumpRight(1);
	}
}

int main() {

	//ground 1 - small
	Object o(1);
	o.setSpeed(10);
	o.setJumpHeight(400);
	o.setDensity(1);
	o.setFriction(0.2);
	o.setRestitution(0.01);
	o.setHeight(80);
	o.setWidth(80);
	o.setX(160);
	o.setY(0);


	phy.temp.push_back(o);
	phy.registerRectangle(o);
	phy.addGround();

	GroundData g;
	g.hx = 100;
	g.hy = 100;
	g.x = 200 - (g.hx/2);
	g.y = 200 - (g.hy/2);

	

	float timeStep = 1.0f / 60.0f;
	
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	for (int32 i = 0; i < 10000; ++i)
	{
		moves(i);
		phy.world.Step(timeStep, velocityIterations, positionIterations);
		Object z = phy.getObject(1);
		GroundData box;
		box.hx = z.getHeight()/2;
		box.hy = z.getWidth()/2;
		box.x = z.getX();
		box.y = z.getY();
		box.angle = 0;

		printf("%4.2f %4.2f %4.2f \n", box.x, box.y, box.hx);

		engine.svi.testLoopVideo(box, g);
		SDL_Delay(10);
	}

	Engine* engine{ new Engine };
	engine->addEventListener(new PhysicsEngine, EventType::MOVE);
	engine->eventManager.notify(EventType::MOVE, new Object);

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


