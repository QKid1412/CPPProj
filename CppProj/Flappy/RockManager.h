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

private:
	void CreateRock();
	
	vector<Rock*> rocks;

	float xSeparation;
	float ySeparation;
};

#endif // !GAME_ROCKMANAGER

