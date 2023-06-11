#pragma once
#include "cstdint"

class Component {
public:
	/*
	�R���X�g���N�^
	updateOrder���������R���|�[�l���g�قǑ����X�V�����
	*/
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component(); //�f�X�g���N�^
	virtual void Update(float deltaTime); //�f���^�^�C���ōX�V
	virtual void ProcessInput(const uint8_t* KeyState){} //�R���|�[�l���g�̓��͏���

protected:
	class Actor* mOwner; //���L���Ă���Actor
	int mUpdateOrder;    //�R���|�[�l���g�̍X�V����

public:
	int GetUpdateOrder() const { return mUpdateOrder; }
};