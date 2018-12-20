#ifndef GAME_RIGIDBODY
#define GAME_RIGIDBODY

#include "../Math/Vector3.h"
#include "../Math/Rect.h"

//control the sprite behavior separate from sprite itself
class Rigidbody {

public:
	static bool IsColliding(const Rigidbody& rbA, const Rigidbody& rbB);

	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _boundingRect);

	void Update();
	void Render(Vector3 c); // not meant for the game since sprite's already been rendered, for other purposes such as debug.

	void AddForce(Vector3 f);

	Vector3 GetVel();
	void SetVel(Vector3 _v);

private:
	// use pointers to affect sprite values
	Vector3* pos;
	float* rot;
	float lastRot;
	Vector3* scale;
	Vector3* size;

	float gravity;
	float friction;
	Vector3 velocity;
	
	Rect boundingRect;
};

#endif // !GAME_RIGIDBODY

