#include <iostream>

class Command {
public:
	Command() {};
	bool isActive = false;
	virtual ~Command() {}
	virtual void execute() = 0;
};

class MoveRight : public Command {
public:
	MoveRight() {

	}

	~MoveRight() {

	}

	void execute() {
		std::cout << "Move right!" << std::endl;
	}
};

class MoveLeft : public Command {
public:
	MoveLeft() {

	}

	void execute() {
		std::cout << "Move Left!" << std::endl;
	}
};

class Jump : public Command {
public:
	Jump() {

	}

	void execute() {
		std::cout << "Jump!" << std::endl;
	}
};

class Block : public Command {
public:
	Block() {

	}

	void execute() {
		std::cout << "Block!" << std::endl;
	}
};

class Roll : public Command {
public:
	Roll() {

	}

	void execute() {
		std::cout << "Roll!" << std::endl;
	}
};

class Attack : public Command {
public:
	Attack() {

	}

	void execute() {
		std::cout << "Attack!" << std::endl;
	}
};