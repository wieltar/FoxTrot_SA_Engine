#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "GameObject.h"

class Player : public GameObject {
public:
    std::string get_name() override {
        return "PLAYER";
    }

    void move() override {
        std::cout << "PLAYER move" << std::endl;
    }

    virtual void interact() {
        std::cout << "PLAYER interact" << std::endl;
    }

    void onCollision() override {
        std::cout << "PLAYER COLLIDED" << std::endl;
    }

    virtual void draw() override {

    }

    virtual void animate() override {

    }

    virtual void playSound() override {

    }
};

