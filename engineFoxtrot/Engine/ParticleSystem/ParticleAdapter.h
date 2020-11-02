#pragma once
#include "ParticleInit.h"
#include "SceneManager/Object.h"

class ParticleAdapter : public Object, public ParticleInit
{
public:
	ParticleAdapter(const int id) : ParticleInit(id), Object(id, true) {};
	~ParticleAdapter() {};

private:

};


