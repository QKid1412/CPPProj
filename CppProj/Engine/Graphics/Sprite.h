#ifndef GAME_SPRITE
#define GAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"

#include <iostream>
#include <string>
using namespace std;

//uses and displays the texture
class Sprite {
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float _xPos, float _yPos);

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(float x, float y);
	void MoveBy(float x, float y);

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(float x, float y);

private:
	Texture texture;

	float speed;

	float xPos;
	float yPos;
	float rot;
	float xScale;
	float yScale;
};

#endif
