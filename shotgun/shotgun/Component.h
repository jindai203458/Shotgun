#pragma once
#include "cstdint"

class Component {
public:
	/*
	コンストラクタ
	updateOrderが小さいコンポーネントほど早く更新される
	*/
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component(); //デストラクタ
	virtual void Update(float deltaTime); //デルタタイムで更新
	virtual void ProcessInput(const uint8_t* KeyState){} //コンポーネントの入力処理

protected:
	class Actor* mOwner; //所有しているActor
	int mUpdateOrder;    //コンポーネントの更新順番

public:
	int GetUpdateOrder() const { return mUpdateOrder; }
};