#pragma once
#include "Particle.h"
#include "./SceneManager/Object.h"

class ParticleInit : public Particle
{
public:
    ParticleInit(){};
    virtual ~ParticleInit() {}

    enum ParticleStyle
    {
        NONE,
        FIRE,
        FIRE_WORK,
        SUN,
        GALAXY,
        FLOWER,
        METEOR,
        SPIRAL,
        EXPLOSION,
        SMOKE,
        SNOW,
        RAIN,
    };

    ParticleStyle style_ = NONE;
    API void setStyle(ParticleStyle style);
};
