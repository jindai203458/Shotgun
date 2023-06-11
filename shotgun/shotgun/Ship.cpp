#include "Game.h"
#include "Laser.h"
#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"

Ship::Ship(Game* game) : Actor(game), mLaserCooldown(0.0f){
	//�X�v���C�g�R���|�[�l���g�쐬
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	//InputComponent���쐬���A�L�[��X�s�[�h��ݒ�
	InputComponent* ic = new InputComponent(this);
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->SetClockwiseKey(SDL_SCANCODE_A);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_D);
	ic->SetMaxForwardSpeed(300.0f);
	ic->SetMaxAngularSpeed(Math::TwoPi);
}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown -= deltaTime;
}

void Ship::ActorInput(const uint8_t* keyState)
{
	if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f)
	{
		//���[�U�[�쐬
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());

		//���[�U�[�̃N�[���^�C��������
		mLaserCooldown = 0.5f;
	}
}