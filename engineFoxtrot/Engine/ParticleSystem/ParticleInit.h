#pragma once
#include "Particle.h"
#include "./SceneManager/Object.h"

class ParticleInit : public Particle
{
public:
    ParticleInit(const int id) : Particle(id){};
    virtual ~ParticleInit() {}

    enum PatticleStyle
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

    PatticleStyle style_ = NONE;
    void setStyle(PatticleStyle style);
};
