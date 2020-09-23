#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "mEngine.h"
#include "mObject.h"
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
    void EngineEventHandler(mObject* objects) {
    }

    Game() {
        engine.addEventListener(new OnCollisionListener(), EventType::COLLISION);

        engine.registerGameObject({ new Enemy() });

        auto player = new Player();
        engine.registerGameObject(player);
    }

    void run() {
        engine.run();
    }
};