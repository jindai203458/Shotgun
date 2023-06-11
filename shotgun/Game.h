#pragma once
#include "SDL.h"
#include "unordered_map"
#include "string"
#include "vector"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	// �G�̒ǉ���폜
	void AddAsteroid(class Asteroid* ast);
	void RemoveAsteroid(class Asteroid* ast);
	std::vector<class Asteroid*>& GetAsteroids() { return mAsteroids; }

	SDL_Texture* GetTexture(const std::string& fileName);

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	std::unordered_map<std::string, SDL_Texture*> mTextures; //�}�b�v�e�N�X�`��

	std::vector<class Actor*> mActors; //�o��Actor
	std::vector<class Actor*> mPendingActors; //�ۗ���Ԃ�Actor

	std::vector<class SpriteComponent*> mSprites; //�X�v���C�g(�`��)

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors; //Actor�X�V�ǐ�

	class Ship* mShip; // ���삷��
	std::vector<class Asteroid*> mAsteroids; //�G(�j��)
};
