#include <iostream>
#include <string>

enum MouseButton {
	None,
	Left,
	Middle,
	Right
};

enum class InputType {
	Key,
	Button
};

class InputEvent {
public:
	InputType type;
	int value;
	int *x;
	int *y;
	InputEvent(InputType t, int v, int *px = 0, int *py = 0) {
		type = t;
		value = v;
		x = px;
		y = py;
	};
	InputEvent() {
		type = InputType::Key;
		value = 0;
		x = 0;
		y = 0;
	}
};

class Command {
public:
	Command() {};
	bool isActive = false;
	InputEvent event;
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
		std::cout << "Attack at " << *event.x << ", " << *event.y << std::endl;
	}
};