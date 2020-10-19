#pragma once
class ParticleTest
{
public:
	ParticleTest();
	ParticleTest(float x, float y, float xVel, float yVel, int life, int color);
	~ParticleTest();

	float x, y, xvel, yvel;
	int endTime;
	int color;

	void move();
	void show();
	void isDead();


private:

};

