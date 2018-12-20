#ifndef GAME_ROCK
#define GAME_ROCK

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"

class Rock {
public:
	static Sprite* rockSprite;
	static void Initialize();

	Rock();
	Rock(Vector3 _pos);

	void Update();
	void Render();
	
	void MoveTo(Vector3 to);
	void MoveBy(Vector3 by);

	float GetX();
	float GetWidth();

	void SetGap(float _gap);
	
	Rigidbody GetTopRB();
	Rigidbody GetBotRB();

private:
	void UpdatePosition();

	Sprite topSprite;
	Sprite botSprite;

	Rigidbody topRB;
	Rigidbody botRB;

	Vector3 pos;

	float gap;
	float speed;

};

#endif // !GAME_ROCK

