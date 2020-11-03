#include "stdafx.h"
#include "ParticleInit.h"

void ParticleInit::setStyle(ParticleStyle style)
{
    if (style_ == style)
    {
        return;
    }
    style_ = style;
    if (style == ParticleStyle::NONE)
    {
        stopSystem();
    }
    switch (style)
    {
    case ParticleInit::ParticleStyle::FIRE:
    {
        initWithTotalParticles(250);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        this->_emitterMode = Mode::GRAVITY;

        // Gravity Mode: gravity
        this->modeA.gravity = { 0, 0 };

        // Gravity Mode: radial acceleration
        this->modeA.radialAccel = 0;
        this->modeA.radialAccelVar = 0;

        // Gravity Mode: speed of particles
        this->modeA.speed = -60;
        this->modeA.speedVar = 20;

        // starting angle
        _angle = 90;
        _angleVar = 10;

        // life of particles
        _life = 3;
        _lifeVar = 0.25f;

        // size, in pixels
        _startSize = 54.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per frame
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.76f;
        _startColor.green = 0.25f;
        _startColor.blue = 0.12f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.0f;
        _startColorVar.green = 0.0f;
        _startColorVar.blue = 0.0f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 0.0f;
        _endColor.green = 0.0f;
        _endColor.blue = 0.0f;
        _endColor.alpha = 0.0f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 40.0f, 20.0f };
        break;
    }
    case ParticleInit::ParticleStyle::FIRE_WORK:
    {
        initWithTotalParticles(1500);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        this->_emitterMode = Mode::GRAVITY;

        // Gravity Mode: gravity
        this->modeA.gravity = { 0.0f, 90.0f };

        // Gravity Mode:  radial
        this->modeA.radialAccel = 0.0f;
        this->modeA.radialAccelVar = 0.0f;

        //  Gravity Mode: speed of particles
        this->modeA.speed = -180.0f;
        this->modeA.speedVar = 50.0f;

        // angle
        this->_angle = 90.0f;
        this->_angleVar = 20.0f;

        // life of particles
        this->_life = 3.5f;
        this->_lifeVar = 1.0f;

        // emits per frame
        this->_emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.5f;
        _startColor.green = 0.5f;
        _startColor.blue = 0.5f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.5f;
        _startColorVar.green = 0.5f;
        _startColorVar.blue = 0.5f;
        _startColorVar.alpha = 0.1f;
        _endColor.red = 0.1f;
        _endColor.green = 0.1f;
        _endColor.blue = 0.1f;
        _endColor.alpha = 0.2f;
        _endColorVar.red = 0.1f;
        _endColorVar.green = 0.1f;
        _endColorVar.blue = 0.1f;
        _endColorVar.alpha = 0.2f;

        // size, in pixels
        _startSize = 8.0f;
        _startSizeVar = 2.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        _posVar = { 0, 0 };
        break;
    }
    case ParticleInit::ParticleStyle::SUN:
    {
        initWithTotalParticles(350);

        // additive
        //this->setBlendAdditive(true);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity mode: radial acceleration
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity mode: speed of particles
        setSpeedParticle(-20);
        setSpeedVar(5);

        // angle
        _angle = 90;
        _angleVar = 360;

        // life of particles
        _life = 1;
        _lifeVar = 0.5f;

        // size, in pixels
        _startSize = 30.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per seconds
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.76f;
        _startColor.green = 0.25f;
        _startColor.blue = 0.12f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.0f;
        _startColorVar.green = 0.0f;
        _startColorVar.blue = 0.0f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 0.0f;
        _endColor.green = 0.0f;
        _endColor.blue = 0.0f;
        _endColor.alpha = 1.0f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 0, 0 };
        break;
    }
    case ParticleInit::ParticleStyle::GALAXY:
    {
        initWithTotalParticles(200);
        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity Mode: speed of particles
        setSpeedParticle(-60);
        setSpeedVar(10);

        // Gravity Mode: radial
        setRadialAccel(-80);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(80);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // life of particles
        _life = 4;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 37.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.12f;
        _startColor.green = 0.25f;
        _startColor.blue = 0.76f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.0f;
        _startColorVar.green = 0.0f;
        _startColorVar.blue = 0.0f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 0.0f;
        _endColor.green = 0.0f;
        _endColor.blue = 0.0f;
        _endColor.alpha = 1.0f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 0, 0 };
        break;
    }
    case ParticleInit::ParticleStyle::FLOWER:
    {
        initWithTotalParticles(250);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity Mode: speed of particles
        setSpeedParticle(-80);
        setSpeedVar(10);

        // Gravity Mode: radial
        setRadialAccel(-60);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(15);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // life of particles
        _life = 4;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 30.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.50f;
        _startColor.green = 0.50f;
        _startColor.blue = 0.50f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.5f;
        _startColorVar.green = 0.5f;
        _startColorVar.blue = 0.5f;
        _startColorVar.alpha = 0.5f;
        _endColor.red = 0.0f;
        _endColor.green = 0.0f;
        _endColor.blue = 0.0f;
        _endColor.alpha = 1.0f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 0, 0 };
        break;
    }
    case ParticleInit::ParticleStyle::METEOR:
    {
        initWithTotalParticles(150);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(-200, -200));

        // Gravity Mode: speed of particles
        setSpeedParticle(-15);
        setSpeedVar(5);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // life of particles
        _life = 2;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 60.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.2f;
        _startColor.green = 0.4f;
        _startColor.blue = 0.7f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.0f;
        _startColorVar.green = 0.0f;
        _startColorVar.blue = 0.2f;
        _startColorVar.alpha = 0.1f;
        _endColor.red = 0.0f;
        _endColor.green = 0.0f;
        _endColor.blue = 0.0f;
        _endColor.alpha = 1.0f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 0, 0 };
        break;
    }
    case ParticleInit::ParticleStyle::SPIRAL:
    {
        initWithTotalParticles(500);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity Mode: speed of particles
        setSpeedParticle(-150);
        setSpeedVar(0);

        // Gravity Mode: radial
        setRadialAccel(-380);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(45);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 0;

        // life of particles
        _life = 12;
        _lifeVar = 0;

        // size, in pixels
        _startSize = 20.0f;
        _startSizeVar = 0.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.5f;
        _startColor.green = 0.5f;
        _startColor.blue = 0.5f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.5f;
        _startColorVar.green = 0.5f;
        _startColorVar.blue = 0.5f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 0.5f;
        _endColor.green = 0.5f;
        _endColor.blue = 0.5f;
        _endColor.alpha = 1.0f;
        _endColorVar.red = 0.5f;
        _endColorVar.green = 0.5f;
        _endColorVar.blue = 0.5f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 0, 0 };
        break;
    }
    case ParticleInit::ParticleStyle::EXPLOSION:
    {
        initWithTotalParticles(700);

        // duration
        _duration = 0.1f;

        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity Mode: speed of particles
        setSpeedParticle(-70);
        setSpeedVar(40);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // life of particles
        _life = 5.0f;
        _lifeVar = 2;

        // size, in pixels
        _startSize = 15.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles / _duration;

        // color of particles
        _startColor.red = 0.7f;
        _startColor.green = 0.1f;
        _startColor.blue = 0.2f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.5f;
        _startColorVar.green = 0.5f;
        _startColorVar.blue = 0.5f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 0.5f;
        _endColor.green = 0.5f;
        _endColor.blue = 0.5f;
        _endColor.alpha = 0.0f;
        _endColorVar.red = 0.5f;
        _endColorVar.green = 0.5f;
        _endColorVar.blue = 0.5f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 0, 0 };
        break;
    }
    case ParticleInit::ParticleStyle::SMOKE:
    {
        initWithTotalParticles(200);

        // duration
        _duration = DURATION_INFINITY;

        // Emitter mode: Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity Mode: radial acceleration
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: speed of particles
        setSpeedParticle(-25);
        setSpeedVar(10);

        // angle
        _angle = 90;
        _angleVar = 5;

        // life of particles
        _life = 4;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 60.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per frame
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.red = 0.8f;
        _startColor.green = 0.8f;
        _startColor.blue = 0.8f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.02f;
        _startColorVar.green = 0.02f;
        _startColorVar.blue = 0.02f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 0.0f;
        _endColor.green = 0.0f;
        _endColor.blue = 0.0f;
        _endColor.alpha = 1.0f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 20.0f, 0.0f };
        break;
    }
    case ParticleInit::ParticleStyle::SNOW:
    {
        initWithTotalParticles(700);

        // duration
        _duration = DURATION_INFINITY;

        // set gravity mode.
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 1));

        // Gravity Mode: speed of particles
        setSpeedParticle(-5);
        setSpeedVar(1);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(1);

        // Gravity mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(1);

        // angle
        _angle = -90;
        _angleVar = 5;

        // life of particles
        _life = 45;
        _lifeVar = 15;

        // size, in pixels
        _startSize = 10.0f;
        _startSizeVar = 5.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = 10;

        // color of particles
        _startColor.red = 1.0f;
        _startColor.green = 1.0f;
        _startColor.blue = 1.0f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.0f;
        _startColorVar.green = 0.0f;
        _startColorVar.blue = 0.0f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 1.0f;
        _endColor.green = 1.0f;
        _endColor.blue = 1.0f;
        _endColor.alpha = 0.0f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 1.0f * x_, 0.0f };
        break;
    }
    case ParticleInit::ParticleStyle::RAIN:
    {
        initWithTotalParticles(1000);

        // duration
        _duration = DURATION_INFINITY;

        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(10, 10));

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(1);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(1);

        // Gravity Mode: speed of particles
        setSpeedParticle(-130);
        setSpeedVar(30);

        // angle
        _angle = -90;
        _angleVar = 5;

        // life of particles
        _life = 4.5f;
        _lifeVar = 0;

        // size, in pixels
        _startSize = 4.0f;
        _startSizeVar = 2.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = 20;

        // color of particles
        _startColor.red = 0.7f;
        _startColor.green = 0.8f;
        _startColor.blue = 1.0f;
        _startColor.alpha = 1.0f;
        _startColorVar.red = 0.0f;
        _startColorVar.green = 0.0f;
        _startColorVar.blue = 0.0f;
        _startColorVar.alpha = 0.0f;
        _endColor.red = 0.7f;
        _endColor.green = 0.8f;
        _endColor.blue = 1.0f;
        _endColor.alpha = 0.5f;
        _endColorVar.red = 0.0f;
        _endColorVar.green = 0.0f;
        _endColorVar.blue = 0.0f;
        _endColorVar.alpha = 0.0f;

        _posVar = { 1.0f * x_, 0.0f };
        break;
    }
    default:
        break;
    }
}
