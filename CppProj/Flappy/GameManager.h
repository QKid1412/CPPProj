#ifndef GAME_GAMEMANAGER
#define GAME_GAMEMANAGER

#include "../Engine/Engine.h"
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"

#include "Flapper.h"
#include "RockManager.h"

class GameManager {
public:
	enum class State {
		START,
		GAMEPLAY,
		GAMEOVER,
		COUNT
	};

	GameManager();
	~GameManager();

	void Start();

private:
	void SetState(State state);

	Engine* mEngine;
	Flapper* mFlapper;
	RockManager* mRockManager;

	Sprite mStartSprite;
	Sprite mEndSprite;

	State mState;
};

#endif // !GAME_GAMEMANAGER

