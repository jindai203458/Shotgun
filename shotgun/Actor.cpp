#include "Game.h"
#include "Actor.h"
#include "Component.h"
#include "algorithm"

Actor::Actor(Game* game) : mState(EActive), mPosition(Vector2::Zero), mScale(1.0f), mRotation(0.0f), mGame(game) {
	mGame->AddActor(this); //Actor追加
}

Actor::~Actor() {
	mGame->RemoveActor(this); //Actor削除
	//コンポーネント削除
// ~ComponentではRemoveActorが呼び出されるので、別の種類のループを使う
	while (!mComponents.empty()){
		delete mComponents.back();
	}
}

//更新
void Actor::Update(float deltaTime) {
	if (mState == EActive || mState == EPaused){
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

//コンポーネント更新
void Actor::UpdateComponents(float deltaTime) {
	for (auto comp : mComponents) {
		comp->Update(deltaTime);
	}
}

//Actor更新
void Actor::UpdateActor(float deltaTime) {

}

void Actor::ProcessInput(const uint8_t* keyState)
{
	if (mState == EActive)
	{
		//コンポーネントに対する最初のプロセス入力
		for (auto comp : mComponents)
		{
			comp->ProcessInput(keyState);
		}

		ActorInput(keyState);
	}
}

//機能追加時オーバーライドする関数
void Actor::ActorInput(const uint8_t* keyState){
}

//コンポーネント追加
void Actor::AddComponent(Component* component)
{
	// 設定された更新順にソートする
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// iteratorの位置の前に要素を挿入
	mComponents.insert(iter, component);
}

//コンポーネント削除
void Actor::RemoveComponent(Component* component){
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}
