#pragma once

#include "GameObject.h"

class Enemy : public GameObject {
public:
    void move() override {
        std::cout << "Enemy move" << std::endl;
    }

    std::string get_name() override {
        return "ENEMY";
    }
};