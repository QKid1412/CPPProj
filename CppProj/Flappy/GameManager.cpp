#include "GameManager.h"

GameManager::GameManager() {
	mEngine = new Engine();
	mEngine->Initialize("GameWindow");

	Sprite testSprite = Sprite("Assets/Image/rocket.png", Vector3(Engine::SCREEN_WIDTH / 4, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.SetScale(0.8f);

	mFlapper = new Flapper(testSprite);
	mRockManager = new RockManager();

	mStartSprite = Sprite("Assets/Image/gamestart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mEndSprite = Sprite("Assets/Image/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));

	mState = State::START;
}

GameManager::~GameManager() {
	delete mEngine;
	delete mFlapper;
	delete mRockManager;
}
void GameManager::Start(){

	while (true) {
		mEngine->Update();
		
		switch (mState) {
			case State::START: {
				mEngine->BeginRender();
				mFlapper->Render();
				mRockManager->Render();
				mStartSprite.Render();
				mEngine->EndRender();

				if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
					SetState(State::GAMEPLAY);
				}
			}
			break;
			case State::GAMEPLAY: {
				mFlapper->Update();
				mRockManager->Update();
				bool isColliding = mRockManager->CheckCollision(*mFlapper);
				// cout << (isColliding ? "COLLIDING" : "....") << endl;
				if (isColliding) {
					SetState(State::GAMEOVER);
				}

				mEngine->BeginRender();
				mFlapper->Render();
				mRockManager->Render();
				mEngine->EndRender();
			}
			break;
			case State::GAMEOVER: {
				mEngine->BeginRender();
				mFlapper->Render();
				mRockManager->Render();
				mEndSprite.Render();
				mEngine->EndRender();

				if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
					SetState(State::START);
				}
			}
			break;
			default:
				cout << "Unhandled game state: " << static_cast<int>(mState) << endl;
				break;
		}
		
	}
}

void GameManager::SetState(State state) {
	mState = state;

	if (mState == State::START) {
		mFlapper->Reset();
		mRockManager->Reset();
	}
}