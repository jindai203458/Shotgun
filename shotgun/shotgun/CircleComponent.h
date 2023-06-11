#pragma once
#include "Vector3.h"
#include "Component.h"

class CircleComponent : public Component {
public:
	CircleComponent(class Actor* owner);

	float GetRadius() const;

	const Vector2& GetCenter() const;

private:
	float mRadius;

public:
	void SetRadius(float radius) { mRadius = radius; }
};

bool Intersect(const CircleComponent& a, const CircleComponent& b);