#include "Game.h"
#include "Random.h"
#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleComponent.h"

Asteroid::Asteroid(Game* game) : Actor(game), mCircle(nullptr) {
	//ランダムな位置と向きで初期化
	Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));
	SetPosition(randPos);

	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	//SpriteComponentを作成、テクスチャを設定
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid.png"));

	//MoveComponentを作成、前進速度を設定
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	game->AddAsteroid(this);
}

Asteroid::~Asteroid() {
	GetGame()->RemoveAsteroid(this);
}