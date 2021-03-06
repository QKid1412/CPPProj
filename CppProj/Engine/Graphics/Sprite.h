#ifndef GAME_SPRITE
#define GAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"
#include "../Math/Math.h"

#include <iostream>
#include <string>
using namespace std;

//uses and displays the texture
class Sprite {
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _pos);

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(Vector3 v);
	void SetRandomScale(float minF, float maxF);
	void SetRandomScaleXY(float minX, float maxX, float minY, float maxY);

	void FlipHorizontal();
	void FlipVertical();

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

private:
	Texture texture;

	float speed;

	Vector3 pos;
	float rot;
	Vector3 scale;
	Vector3 size;
};

#endif
