#include "RockManager.h"
#include "../Engine/Engine.h"
#include "../Engine/Physics/Rigidbody.h"

#define RAND_MINX 350
#define RAND_MAXX 750
#define RAND_MINY 300
#define RAND_MAXY 650

RockManager::RockManager() :
	xSeparationSpeed(10),
	ySeparationSpeed(10),
	xRandMin(350),
	xRandMax(750),
	yRandMin(400),
	yRandMax(750),
	ySpawnMin(300),
	increaseSpeed(0),
	score(0)
{
	xSeparation = Math::RandomFloat(xRandMin, xRandMax);
	ySeparation = Math::RandomFloat(yRandMin, yRandMax);
	totalRocks = 0;
	Rock::Initialize();
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

		if (rocks[i]->GetX() < Engine::SCREEN_WIDTH / 2 && rocks[i]->GetHeight() > Engine::SCREEN_WIDTH / 2) {
			score++;
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

void RockManager::Reset() {
	xRandMin = 350;
	xRandMax = 750;
	yRandMin = 400;
	yRandMax = 750;
	ySpawnMin = 300;
	increaseSpeed = 0;

	for (int i = 0; i < rocks.size();i++) {
		delete rocks[i];
	}
	rocks.clear();

	totalRocks = 0;
	CreateRock();
}

void RockManager::CreateRock() {
	xSeparation = Math::RandomFloat(RAND_MINX, RAND_MAXX);
	ySeparation = Math::RandomFloat(RAND_MINY, RAND_MAXY);

	float spawnY = Math::RandomFloat(ySpawnMin, Engine::SCREEN_HEIGHT - ySpawnMin);
	Rock* rock = new Rock(Vector3(Engine::SCREEN_WIDTH, spawnY, 0), increaseSpeed);
	rock->SetGap(ySeparation);

	rocks.push_back(rock);
	totalRocks++;

	if (totalRocks % 2 == 0) {
		xRandMin += xSeparationSpeed;
		xRandMax -= xSeparationSpeed;

		yRandMin += ySeparationSpeed;
		yRandMax -= ySeparationSpeed;

		ySpawnMin -= ySeparationSpeed;
		increaseSpeed += 10;
	}
}