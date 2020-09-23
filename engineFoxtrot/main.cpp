#pragma once
#include <iostream>
#include "Engine.h"
#include "Game.h"

#include "box2d/box2d.h"
using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;

int main() {

	b2Vec2 gravity(0.0f, 10.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 130.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);

	groundBody->CreateFixture(&groundBox, 0.0f);




	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 0.0f);
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 10.0f;
	fixtureDef.friction = 0.3f;

	fixtureDef.restitution = 0.9f;

	body->CreateFixture(&fixtureDef);

	float timeStep = 1.0f / 60.0f;
	
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	for (int32 i = 0; i < 1000; ++i)
	{
		world.Step(timeStep, velocityIterations, positionIterations);
		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
		engine.svi.testLoopVideo((int)position.x, (int)position.y);
		SDL_Delay(10);
	}

	Game g = Game();
	g.run();
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





