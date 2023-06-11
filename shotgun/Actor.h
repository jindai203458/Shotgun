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

	void Update(float deltaTime); //呼び出される更新関数
	void UpdateComponents(float deltaTime); //Actorのコンポーネントを更新
	virtual void UpdateActor(float deltaTime); //Actorの更新

	void ProcessInput(const uint8_t* KeyState); //呼び出される関数
	virtual void ActorInput(const uint8_t* KeyState);

	//コンポーネントの追加、削除
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	// Actorの状態
	State mState;

	//設定(位置や大きさなど)
	Vector2 mPosition;
	float mScale;
	float mRotation;

	std::vector<class Component*> mComponents;
	class Game* mGame;

public:
	//ゲッター、セッター
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