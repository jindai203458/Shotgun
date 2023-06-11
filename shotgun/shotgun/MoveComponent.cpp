#include "Actor.h"
#include "MoveComponent.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder) : Component(owner, updateOrder), mAngularSpeed(0.0f), mForwardSpeed(0.0f) {

}
/*
MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	//, mForwardSpeed(0.0f)
	, mMass(1.0f)
	, mForces(Vector2::Zero)
{

}
*/

void MoveComponent::Update(float deltaTime) {
	//��]���x��0�ɋ߂���Ίp�x���X�V���Ȃ�
	if (!Math::NearZero(mAngularSpeed)) {
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}
	if (!Math::NearZero(mForwardSpeed)) {
		Vector2 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;

		if (pos.x < 0.0f) { pos.x = 1022.0f; }
		else if (pos.x > 1024.0f) { pos.x = 2.0f; }

		if (pos.y < 0.0f) { pos.y = 766.0f; }
		else if (pos.y > 768.0f) { pos.y = 2.0f; }

		mOwner->SetPosition(pos);
	}
}