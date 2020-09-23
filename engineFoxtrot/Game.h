#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "mEngine.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"

class OnCollisionListener : public EventListener {
public:
    OnCollisionListener() { }
    void update(mObject* object) {
        object->onCollision();
    }
};

class Game {
private:
    mEngine engine = mEngine();
public:
    Game() {
        engine.addEventListener(new OnCollisionListener(), EventType::COLLISION);

        engine.addObject({ new Enemy() });

        auto player = new Player();
        engine.addObject(player);
    }

    void run() {
        engine.run();
    }
};