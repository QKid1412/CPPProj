#include "RockManager.h"
#include "../Engine/Engine.h"
#include "../Engine/Physics/Rigidbody.h"

RockManager::RockManager() : xSeparation(100), ySeparation(500) {
	CreateRock();
}

RockManager::~RockManager() {
	for (int i = 0; i < rocks.size(); i++) {
		delete rocks[i];
	}
}

void RockManager::Update() {
	vector<int> rocksFadeOut;
		
	for (int i = 0; i < rocks.size(); i++) {
		rocks[i]->Update();
		
		if (rocks[i]->GetX() < -(rocks[i]->GetWidth())) {
			rocksFadeOut.push_back(i);
		}

		// create new rock if the rightmost is reached
		if (i == rocks.size() - 1) {
			if (rocks[i]->GetX() < Engine::SCREEN_WIDTH - xSeparation) {
				CreateRock();
			}
		}
	}

	for (int i = 0; i < rocksFadeOut.size(); i++) {
		delete rocks[rocksFadeOut[i]];
		rocks.erase(rocks.begin() + rocksFadeOut[i]);
	}
}

void RockManager::Render() {
	for (int i = 0; i < rocks.size(); i++) {
		rocks[i]->Render();
	}
}

bool RockManager::CheckCollision(Flapper& flapper) {
	bool isColliding = false;
	for (int i = 0; i < rocks.size(); i++) {
		isColliding = Rigidbody::IsColliding(flapper.GetRB(), rocks[i]->GetTopRB()) ||
			Rigidbody::IsColliding(flapper.GetRB(), rocks[i]->GetBotRB());
		if (isColliding)
			break;
	}

	return isColliding;
}

void RockManager::CreateRock() {
	rocks.push_back(new Rock(Vector3(2000, Engine::SCREEN_HEIGHT / 2, 0)));
}