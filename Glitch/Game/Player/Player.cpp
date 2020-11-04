#include "Player.h"

Player::Player() : Object(2) {
	this->setName("person");
	this->setHeight(80);
	this->setWidth(80);
	this->setPositionX(100);
	this->setPositionY(80);

	this->setSpeed(75);
	this->setJumpHeight(400);
	this->setDensity(100);
	this->setFriction(0);
	this->setRestitution(0);
	this->setStatic(false);
	this->setRotatable(false);

	EventSingleton::get_instance().setEventCallback<OnCollisionBeginEvent>(BIND_EVENT_FN(Player::onCollisionBeginEvent));
	EventSingleton::get_instance().setEventCallback<OnCollisionEndEvent>(BIND_EVENT_FN(Player::onCollisionEndEvent));
	EventSingleton::get_instance().setEventCallback<KeyPressedEvent>(BIND_EVENT_FN(Player::onKeyPressed));
}

/// @brief 
/// Handles when an collision event begins, when the direction of the collision happend on the bottom side of the player object, 
/// set can jump true
void Player::onCollisionBeginEvent(Event& event) {
	auto collisionEvent = static_cast<OnCollisionBeginEvent&>(event);
	if (collisionEvent.GetObjectOneId() != this->getObjectId() && collisionEvent.GetObjectTwoId() != this->getObjectId()) return;

	auto map = collisionEvent.getDirectionMap();
	auto collidedDirection = map[this->getObjectId()];

	if (std::find(collidedDirection.begin(), collidedDirection.end(), Direction::DOWN) != collidedDirection.end()) {
		this->canJump = true;
		if (this->getXAxisVelocity() == 0)
			this->changeToState(SpriteState::DEFAULT);
		else if (this->getXAxisVelocity() > 0)
			this->changeToState(SpriteState::RUN_RIGHT);
		else
			this->changeToState(SpriteState::RUN_LEFT);
	}
}

/// @brief 
/// Handles when an collision event ends, when the direction of the collision happend on the bottom side of the player object, set can jump false
void Player::onCollisionEndEvent(Event& event) {
	auto collisionEvent = static_cast<OnCollisionEndEvent&>(event);
	if (collisionEvent.GetObjectOneId() != this->getObjectId() && collisionEvent.GetObjectTwoId() != this->getObjectId()) return;

	auto map = collisionEvent.getDirectionMap();
	auto collidedDirection = map[this->getObjectId()];

	if (std::find(collidedDirection.begin(), collidedDirection.end(), Direction::DOWN) != collidedDirection.end()) {
		this->canJump = false;
	}
}

void Player::setYAxisVelocity(const float val) {

	if (!canJump) {
		if (val > 0 && !changed) {
			if (this->getXAxisVelocity() > 0)
				this->changeToState(SpriteState::AIR_FALL_RIGHT);
			else
				this->changeToState(SpriteState::AIR_FALL_LEFT);
		}
	}

	if (val == 0) {
		changed = false;
	}

	Object::setYAxisVelocity(val);
}

/// @brief 
/// Handles when an key pressed event happend, Player can move right, left and jump
void Player::onKeyPressed(Event& event) {
	auto keyPressedEvent = static_cast<KeyPressedEvent&>(event);
	// TODO command pattern
	switch (keyPressedEvent.GetKeyCode())
	{
	case KeyCode::KEY_A:
			EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::LEFT, this->getObjectId()));
			if (canJump)
				this->changeToState(SpriteState::RUN_LEFT);
			else if (this->getYAxisVelocity() > 0) 
				this->changeToState(SpriteState::AIR_FALL_LEFT);
			else
				this->changeToState(SpriteState::AIR_JUMP_LEFT);
		break;
	case KeyCode::KEY_D:
			EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::RIGHT, this->getObjectId()));
			if (canJump) {
				this->changeToState(SpriteState::RUN_RIGHT);
			}
			else if (this->getYAxisVelocity() > 0)
				this->changeToState(SpriteState::AIR_FALL_RIGHT);
			else 
				this->changeToState(SpriteState::AIR_JUMP_RIGHT);
		break;
	case KeyCode::KEY_SPACE:
		if (canJump) {
			if (this->getXAxisVelocity() > 0)
				this->changeToState(SpriteState::AIR_JUMP_RIGHT);
			else
				this->changeToState(SpriteState::AIR_JUMP_LEFT);
			EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::UP, this->getObjectId()));
		}
		break;
	default:
		break;
	}
}

bool Player::getCanJump() const { return this->canJump; };
void Player::setCanJump(bool val) { this->canJump = val; }