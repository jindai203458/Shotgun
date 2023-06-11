#include "Actor.h"
#include "InputComponent.h"

InputComponent::InputComponent(class Actor* owner) : MoveComponent(owner), mForwardKey(0), mBackKey(0), mClockwiseKey(0), mCounterClockwiseKey(0) {

}

void InputComponent::ProcessInput(const uint8_t* keyState) {
	//MoveComponent用に前進速度計算
	float forwardSpeed = 0.0f;
	if (keyState[mForwardKey]) {
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState[mBackKey]) {
		forwardSpeed -= mMaxForwardSpeed;
	}
	SetForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (keyState[mClockwiseKey]) {
		angularSpeed += mMaxAngularSpeed;
	}
	if (keyState[mCounterClockwiseKey]) {
		angularSpeed -= mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);
}