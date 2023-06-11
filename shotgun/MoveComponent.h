#pragma once
#include "Component.h"

class MoveComponent : public Component {
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

private:
	float mAngularSpeed; //âÒì]êßå‰(radians/ïb)
	float mForwardSpeed; //à⁄ìÆêßå‰(units/ïb)

public:
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
};