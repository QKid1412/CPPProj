#ifndef GAME_FLAPPER
#define GAME_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"
#include "../Engine/Math/Rect.h"

// simulate flappy(gravity related) behaviour
class Flapper {
public:
	Flapper();
	Flapper(Sprite _sprite);

	void Update();
	void Render();

	void Flap();
	void Reset();
	
	Sprite& GetSprite();
	Rigidbody& GetRB();

private:
	void HandleInput();

	Sprite sprite;
	Rigidbody rb;

	float flapForce;
	float maxRot;
	float minRot;
};

#endif // !GAME_FLAPPYITEM

