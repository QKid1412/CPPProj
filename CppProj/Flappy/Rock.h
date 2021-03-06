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
	Rock(Vector3 _pos, float _speed);

	void Update();
	void Render();
	
	void MoveTo(Vector3 to);
	void MoveBy(Vector3 by);

	float GetX();
	float GetWidth();
	float GetHeight();

	void SetGap(float _gap);
	void SetSpeed(float _speed);
	
	Rigidbody GetTopRB();
	Rigidbody GetBotRB();

private:
	void UpdatePosition();

	Sprite topSprite;
	Sprite botSprite;

	Rigidbody topRB;
	Rigidbody botRB;

	Vector3 pos;
	float height;

	float gap;
	float speed;

};

#endif // !GAME_ROCK

