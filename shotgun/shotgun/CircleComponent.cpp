#include "Actor.h"
#include "CircleComponent.h"

CircleComponent::CircleComponent(class Actor* owner) : Component(owner), mRadius(0.0f) {

}

const Vector2& CircleComponent::GetCenter() const {
	return mOwner->GetPosition();
}

float CircleComponent::GetRadius() const {
	return mOwner->GetScale() * mRadius;
}

bool Intersect(const CircleComponent& a, const CircleComponent& b) {
	//�����̓��
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.LengthSq();

	// ���a�̘a��2��
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}