#pragma once
#include "ParticleSystem/ParticleLib/ParticleInit.h"
#include "SceneManager/Object.h"

/// @brief 
/// Particle Bridge that inherits from Object and ParticleInit(Cocos2dx Library)
class ParticleAdapter : public Object, public ParticleInit
{
public:
	API ParticleAdapter(const int id) : Object(id, true) {};
	API ~ParticleAdapter() {};

private:

};


