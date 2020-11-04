#pragma once
#include <api.h>
#include "../SpriteState.h"

class Player : public Object {
public:
	Player();
	/// @brief 
	/// Handles when an collision event begins, when the direction of the collision happend on the bottom side of the player object, 
	/// set can jump true
	void onCollisionBeginEvent(Event& event);
	/// @brief 
	/// Handles when an collision event ends, when the direction of the collision happend on the bottom side of the player object, set can jump false
	void onCollisionEndEvent(Event& event);
	void setYAxisVelocity(const float val) override;

	/// @brief 
	/// Handles when an key pressed event happend, Player can move right, left and jump
	void onKeyPressed(Event& event);

	bool getCanJump() const;
	void setCanJump(bool val);
private:
	bool canJump = false;
};