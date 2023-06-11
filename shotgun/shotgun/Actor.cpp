#include "Game.h"
#include "Actor.h"
#include "Component.h"
#include "algorithm"

Actor::Actor(Game* game) : mState(EActive), mPosition(Vector2::Zero), mScale(1.0f), mRotation(0.0f), mGame(game) {
	mGame->AddActor(this); //Actor�ǉ�
}

Actor::~Actor() {
	mGame->RemoveActor(this); //Actor�폜
	//�R���|�[�l���g�폜
// ~Component�ł�RemoveActor���Ăяo�����̂ŁA�ʂ̎�ނ̃��[�v���g��
	while (!mComponents.empty()){
		delete mComponents.back();
	}
}

//�X�V
void Actor::Update(float deltaTime) {
	if (mState == EActive || mState == EPaused){
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

//�R���|�[�l���g�X�V
void Actor::UpdateComponents(float deltaTime) {
	for (auto comp : mComponents) {
		comp->Update(deltaTime);
	}
}

//Actor�X�V
void Actor::UpdateActor(float deltaTime) {

}

void Actor::ProcessInput(const uint8_t* keyState)
{
	if (mState == EActive)
	{
		//�R���|�[�l���g�ɑ΂���ŏ��̃v���Z�X����
		for (auto comp : mComponents)
		{
			comp->ProcessInput(keyState);
		}

		ActorInput(keyState);
	}
}

//�@�\�ǉ����I�[�o�[���C�h����֐�
void Actor::ActorInput(const uint8_t* keyState){
}

//�R���|�[�l���g�ǉ�
void Actor::AddComponent(Component* component)
{
	// �ݒ肳�ꂽ�X�V���Ƀ\�[�g����
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// iterator�̈ʒu�̑O�ɗv�f��}��
	mComponents.insert(iter, component);
}

//�R���|�[�l���g�폜
void Actor::RemoveComponent(Component* component){
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}
