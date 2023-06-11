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

	// 敵の追加や削除
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

	std::unordered_map<std::string, SDL_Texture*> mTextures; //マップテクスチャ

	std::vector<class Actor*> mActors; //出すActor
	std::vector<class Actor*> mPendingActors; //保留状態のActor

	std::vector<class SpriteComponent*> mSprites; //スプライト(描画)

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors; //Actor更新追跡

	class Ship* mShip; // 操作する
	std::vector<class Asteroid*> mAsteroids; //敵(破壊物)
};
