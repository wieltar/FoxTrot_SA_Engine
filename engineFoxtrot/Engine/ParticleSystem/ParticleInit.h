#pragma once
#include "Particle.h"
//#include "SDL_image.h"

class ParticleInit : public Particle
{
public:
    ParticleInit() {}
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
