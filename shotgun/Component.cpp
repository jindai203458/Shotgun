#include "Component.h"
#include "Actor.h"

Component::Component(Actor* owner, int updateOrder) : mOwner(owner), mUpdateOrder(updateOrder) {
	mOwner->AddComponent(this); // Actorにコンポーネントを追加
}

Component::~Component() {
	mOwner->RemoveComponent(this); // Actorからコンポーネントを削除
}

void Component::Update(float deltaTime) {

}
