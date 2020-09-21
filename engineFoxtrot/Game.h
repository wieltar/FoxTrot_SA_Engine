#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Engine.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"

class Game {
private:
    Engine engine = Engine();
public:
    Game() {
        engine.addObject({ new Enemy() });
        engine.addObject({ new Player() });
    }

    void run() {
        engine.run();
        /*while (true) {
            for (std::vector<int>::size_type i = 0; i != e.size(); i++) {
                auto x = enemies[i];
                x->move();
                e.manager.notify(MOVE, x);
            }
        }*/
    }
};