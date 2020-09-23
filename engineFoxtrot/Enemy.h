#pragma once

#include "GameObject.h"

class Enemy : public GameObject {
public:
    std::string get_name() override {
        return "ENEMY";
    }

    void move() override {
        std::cout << "ENEMY Loopt" << std::endl;
    }

    virtual void interact() {
    }

    void onCollision() override {
        std::cout << "ENEMY COLLIDED" << std::endl;
    }

    virtual void draw() override {

    }

    virtual void animate() override {

    }

    virtual void playSound() override {

    }
};