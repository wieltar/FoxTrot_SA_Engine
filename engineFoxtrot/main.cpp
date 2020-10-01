#pragma once
#include <iostream>
#include "Engine.h"

#include "box2d/box2d.h"
#include <chrono>
#include "GroundData.h"
using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;
int speed =1 ;

int remainingLeftSteps = 0;
int remainingRightSteps = 0;

bool movingJump = false;
bool movingLeft = false;
bool movingRight = false;


void moveLeft(b2Body* body) {
	body->ApplyLinearImpulse(b2Vec2(speed * 10 * -1, 0.0f), body->GetWorldCenter(), true);	
}
void moveRight(b2Body* body) {
	body->ApplyLinearImpulse(b2Vec2(speed * 10, 0.0f), body->GetWorldCenter(), true);
}
void moveJump(b2Body* body) {
	body->ApplyLinearImpulse(b2Vec2(0, -400), body->GetWorldCenter() , true);
}
void moveJumpLeft(b2Body* body) {
	body->ApplyLinearImpulse(b2Vec2(-100, -400), body->GetWorldCenter(), true);
}
void moveJumpRight(b2Body* body) {
	body->ApplyLinearImpulse(b2Vec2(100, -400), body->GetWorldCenter(), true);
}
void stopJump(b2Body* body) {
	body->ApplyLinearImpulse(b2Vec2(0, 0), body->GetWorldCenter(), true);
}



/*
move right 
jump straigt up
jump right
jump left
*/
void moveCommandos(int i) {

	/*if (i == 100) {
		movingRight = true;
	}
	if (i == 150) {
		movingRight = false;
	}
	
	if (i == 400) {
		movingJump = true;
	}
	if (i == 500) {
		movingJump = false;
	}
	if (i == 400) {
		movingJump = true;
		movingLeft = true;
	}
	if (i == 410) {
		movingJump = false;
		movingLeft = false;
	}
	if (i == 100) {
		movingJump = true;
		movingRight = true;
	}
	if (i == 110) {
		movingJump = false;
		movingRight = false;
	}
	*/
}

void move(b2Body* body) {
	if (movingJump) {
		if (movingRight) {
			moveJumpRight(body);
		}
		else if (movingLeft) {
			moveJumpLeft(body);
		}
		else {
			moveJump(body);
		}
	}
	else {
		stopJump(body);

		if (movingLeft)
			moveLeft(body);
		
		if (movingRight)
			moveRight(body);
		
	}

}


int main() {

	b2Vec2 gravity(0.0f, 80.0f);
	b2World world(gravity);

	//ground 1 - small
	b2BodyDef groundBodyDef;
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50,50, b2Vec2(200,200), 0);
	groundBody->CreateFixture(&groundBox, 0.0f);



	GroundData g;
	g.x = 200 - 50;
	g.y = 200 - 50;
	g.hx = 100;
	g.hy = 100;

	//house

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape bodyBox;
	bodyBox.SetAsBox(40, 40, b2Vec2(200, 0), 45);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &bodyBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.2f;
	fixtureDef.restitution = 0.01f;

	body->CreateFixture(&fixtureDef);



	float timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	for (int32 i = 0; i < 10000; ++i)
	{
		world.Step(timeStep, velocityIterations, positionIterations);
		//moveCommandos(i);//input handlings
		//move(body);
		b2Vec2 position = body->GetWorldCenter();
		float angle = body->GetAngle();
		printf("%4.2f %4.2f \n", position.x, position.y);
		GroundData box;
		box.hx = 40;
		box.hy = 40;
		box.x = position.x;
		box.y = position.y;

		engine.svi.testLoopVideo(box, g);
		SDL_Delay(10);
	}

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





