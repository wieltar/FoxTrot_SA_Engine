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

	if (i == 100) {
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

	if (i == 1000) {
		movingJump = true;
		movingLeft = true;
	}
	if (i == 1010) {
		movingJump = false;
		movingLeft = false;
	}
	if (i == 1300) {
		movingJump = true;
		movingRight = true;
	}
	if (i == 1310) {
		movingJump = false;
		movingRight = false;
	}
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

	//ground 1
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 50);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	//ground 2
	b2BodyDef groundBodyDef2;
	groundBodyDef2.position.Set(0.0f, 130);

	b2Body* groundBody2 = world.CreateBody(&groundBodyDef2);

	b2PolygonShape groundBox2;
	groundBox2.SetAsBox(1000.0f, 10.0f);
	groundBody2->CreateFixture(&groundBox2, 0.0f);

	GroundData g;
	g.x = 0;
	g.y = 130;
	g.hx = 1000.0f;
	g.hy = 10.0f;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 0.0f);
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.2f;
	fixtureDef.restitution = 0.01f;

	fixtureDef.restitution = 0.0f;

	body->CreateFixture(&fixtureDef);

	float timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	b2Body* temp;
	for (int32 i = 0; i < 10000; ++i)
	{
		world.Step(timeStep, velocityIterations, positionIterations);
		moveCommandos(i);//input handlings
		temp = world.GetBodyList();
		while (temp) {
			move(temp);
			temp = temp->GetNext();
		}
		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		printf("%4.2f %4.2f %4.2f \n", position.x, position.y, angle);
		engine.svi.testLoopVideo(position.x, position.y, g);
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





