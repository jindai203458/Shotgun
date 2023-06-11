#include "Component.h"
#include "Actor.h"

Component::Component(Actor* owner, int updateOrder) : mOwner(owner), mUpdateOrder(updateOrder) {
	mOwner->AddComponent(this); // Actor�ɃR���|�[�l���g��ǉ�
}

Component::~Component() {
	mOwner->RemoveComponent(this); // Actor����R���|�[�l���g���폜
}

void Component::Update(float deltaTime) {

}
