#include "Glitch.h"

Engine engine;

void sceneTestSetup()
{
	engine.linkSpriteIDWithAssetPath(1, "../Assets/Sprites/character/adventure.png");
	engine.linkSpriteIDWithAssetPath(2, "../Assets/Sprites/character/adventure.png");
	engine.linkSpriteIDWithAssetPath(101, "../Assets/Sprites/World/LIGHT TILE WITHOUT TOP.png");
	engine.linkSpriteIDWithAssetPath(11, "./Engine/ParticleSystem/fire.png");

	map<string, string> soundL1 = {
		{"Level_1_Sound", "../Assets/Sound/file_example_WAV_1MG.wav"},
	};

	Level* testScene = new Level(100, soundL1);

	Object* object = new Object(1);
	object->setName("house");
	object->setHeight(80);
	object->setWidth(80);
	object->setPositionX(30);
	object->setPositionY(80);
	object->setSpeed(100);
	object->setJumpHeight(400);
	object->setDensity(10);
	object->setFriction(0);
	object->setRestitution(0);
	object->setStatic(false);

	testScene->addNewObjectToLayer(3, object);
	
	Object* object2 = new Object(2);
	object2->setName("person");
	object2->setHeight(80);
	object2->setWidth(80);
	object2->setPositionX(100);
	object2->setPositionY(80);
	object2->setSpeed(100000);
	object2->setJumpHeight(4000000);
	object2->setDensity(10);
	object2->setFriction(0);
	object2->setRestitution(0);
	object2->setStatic(false);
	testScene->addNewObjectToLayer(3, object2);

	Object* staticGround = new Object(101);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	testScene->addNewObjectToLayer(3, staticGround);

	ParticleAdapter * particle1 = new ParticleAdapter(11);        // create a new particle system pointer
	testScene->addNewObjectToLayer(4, particle1);

	particle1->setPosition(800, 384);              // set the position
	particle1->setStyle(ParticleInit::FIRE);    // set the example effects
	particle1->setStartSpin(0);
	particle1->setStartSpinVar(90);
	particle1->setEndSpin(90);
	particle1->setStartSpinVar(90);

	ParticleAdapter * particle2 = new ParticleAdapter(11);        // create a new particle system pointer
	testScene->addNewObjectToLayer(2, particle2);

	particle2->setPosition(100, 384);              // set the position
	particle2->setStyle(ParticleInit::EXPLOSION);    // set the example effects
	particle2->setStartSpin(0);
	particle2->setStartSpinVar(90);
	particle2->setEndSpin(90);
	particle2->setStartSpinVar(90);
	
	engine.insertScene(testScene);
	engine.setCurrentScene(100);
	testScene->Start(); 

	engine.configureInput(KEY_A, engine.makeCommand<MoveLeft>());
	engine.configureInput(KEY_D, engine.makeCommand<MoveRight>());
	engine.configureInput(KEY_SPACE, engine.makeCommand<Jump>());
	engine.configureInput(KEY_F1, engine.makeCommand<ToggleFps>(), true);
	//Engine* command = engine.makeCommand<Engine>();

	engine.startTickThreads();
}


int main() {
	sceneTestSetup();
	
	bool gameRunning = true;

	while (gameRunning)
	{
		AppTickEvent60 appTick;
		AppTickEvent30 appTick30;

		engine.pollInput();
		EventSingleton::get_instance().dispatchEvent<AppTickEvent60>(appTick);
		EventSingleton::get_instance().dispatchEvent<AppTickEvent30>(appTick30);

		this_thread::sleep_for(chrono::milliseconds(10));
	}

	return 0;
}
