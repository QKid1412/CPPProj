#ifndef GAME_RIGIDBODY
#define GAME_RIGIDBODY

#include "../Math/Vector3.h"

//control the sprite behavior separate from sprite itself
class Rigidbody {

public:
	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size);

	void Update();
	void Render(Vector3 c); // not meant for the game since sprite's already been rendered, for other purposes such as debug.

	void AddForce(Vector3 f);

	Vector3 GetVel();
	void SetVel(Vector3 _v);

private:
	// use pointers to affect sprite values
	Vector3* pos;
	float* rot;
	Vector3* scale;
	Vector3* size;

	float gravity;
	float friction;
	Vector3 velocity;
};

#endif // !GAME_RIGIDBODY

