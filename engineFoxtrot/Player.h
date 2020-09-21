#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Object.h"
#include "GameObject.h"

class Player : public GameObject {
public:
    void move() override {
        std::cout << "Player move" << std::endl;
    }

    std::string get_name() override {
        return "PLAYER";
    }
};