#pragma once
#include "vector"
#include "cstdint"
#include "Vector3.h"

class Actor {
public:
	enum State {
		EActive, EPaused, EDead
	};

	Actor(class Game* game);
	virtual ~Actor();

	void Update(float deltaTime); //�Ăяo�����X�V�֐�
	void UpdateComponents(float deltaTime); //Actor�̃R���|�[�l���g���X�V
	virtual void UpdateActor(float deltaTime); //Actor�̍X�V

	void ProcessInput(const uint8_t* KeyState); //�Ăяo�����֐�
	virtual void ActorInput(const uint8_t* KeyState);

	//�R���|�[�l���g�̒ǉ��A�폜
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	// Actor�̏��
	State mState;

	//�ݒ�(�ʒu��傫���Ȃ�)
	Vector2 mPosition;
	float mScale;
	float mRotation;

	std::vector<class Component*> mComponents;
	class Game* mGame;

public:
	//�Q�b�^�[�A�Z�b�^�[
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }

	Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation)); }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	class Game* GetGame() { return mGame; }
};