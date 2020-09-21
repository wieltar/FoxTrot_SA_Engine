#pragma once

#include <iostream>
#include <string>

class Object {
private:
    std::string name;
public:
    int X;
    int Y;

    virtual std::string get_name() = 0;
};