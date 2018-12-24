#ifndef GAME_ROCKMANAGER
#define GAME_ROCKMANAGER

#include "Rock.h"
#include "Flapper.h"
#include <vector>

using namespace std;

class RockManager {
public:
	RockManager();
	~RockManager();

	void Update();
	void Render();

	bool CheckCollision(Flapper& flapper);
	void Reset();

private:
	void CreateRock();
	
	vector<Rock*> rocks;

	float xSeparation;
	float ySeparation;
	float xSeparationSpeed;
	float ySeparationSpeed;
	float increaseSpeed;

	float xRandMin;
	float xRandMax;
	float yRandMin;
	float yRandMax;

	float ySpawnMin;

	int totalRocks;
	int score;
};

#endif // !GAME_ROCKMANAGER

