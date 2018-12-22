#include "Rock.h"
#include "../Engine/Math/Rect.h"
#include "../Engine/Math/Math.h"
#include "../Engine/Engine.h"

#define DEFAULT_GAP 550
#define DEFAULT_SPEED 100

#define MIN_SCALE_X 1
#define MAX_SCALE_X 2.8
#define MIN_SCALE_Y 1.3
#define MAX_SCALE_Y 2.8

#define SIZEOFFSET_X 0.8
#define SIZEOFFSET_Y 0.8



Sprite* Rock::rockSprite = NULL;

void Rock::Initialize() {
	rockSprite = new Sprite("Assets/Image/rock.png");
}

Rock::Rock() {
	if (!rockSprite) {
		return;
	}

	topSprite = Sprite(*rockSprite);
	botSprite = Sprite(*rockSprite);

	gap = DEFAULT_GAP;
	speed = DEFAULT_SPEED;
}

Rock::Rock(Vector3 _pos, float _speed) : Rock() {
	speed += _speed ;

	if (!rockSprite) {
		return;
	}

	pos = _pos + Vector3(GetWidth(), 0, 0);

	UpdatePosition();

	// Top part
	topSprite.SetRandomScaleXY(MIN_SCALE_X, MAX_SCALE_X, MIN_SCALE_Y, MAX_SCALE_Y);
	topSprite.FlipVertical();

	Rect topRC = Rect();
	topRC.SetSize(Vector3(Math::Abs(topSprite.GetSize()->x * topSprite.GetScale()->x * SIZEOFFSET_X), Math::Abs(topSprite.GetSize()->y * topSprite.GetScale()->y * SIZEOFFSET_Y), 1));
	topRB = Rigidbody();
	topRB.Initialize(1, 0, topSprite.GetPos(), topSprite.GetRot(), topSprite.GetScale(), topSprite.GetSize(), topRC);

	// Bottom Part
	botSprite.SetRandomScaleXY(MIN_SCALE_X, MAX_SCALE_X, MIN_SCALE_Y, MAX_SCALE_Y);

	Rect botRC = Rect();
	botRC.SetSize(Vector3(Math::Abs(botSprite.GetSize()->x * botSprite.GetScale()->x * SIZEOFFSET_X), Math::Abs(botSprite.GetSize()->y * botSprite.GetScale()->y * SIZEOFFSET_Y), 1));
	botRB = Rigidbody();
	botRB.Initialize(1, 0, botSprite.GetPos(), botSprite.GetRot(), botSprite.GetScale(), botSprite.GetSize(), botRC);
	
	// make the rocks move
	topRB.AddForce(Vector3(-speed, 0, 0));
	botRB.AddForce(Vector3(-speed, 0, 0));
}

void Rock::Update() {
	//topSprite.MoveBy(Vector3(-speed * Engine::GetDT(), 0, 0));
	//botSprite.MoveBy(Vector3(-speed * Engine::GetDT(), 0, 0));
	topRB.Update();
	botRB.Update();
}

void Rock::Render() {
	topSprite.Render();
	botSprite.Render();
	topRB.Render(Vector3(1, 1, 1));
	botRB.Render(Vector3(1, 1, 1));
}

void Rock::MoveTo(Vector3 to) {
	pos = to;
	UpdatePosition();
}

void Rock::MoveBy(Vector3 by) {
	pos = pos + by;
	UpdatePosition();
}

void Rock::UpdatePosition() {
	// update top and bottom positions
	Vector3 topPos = pos;
	topPos.y += (gap / 2) + Math::Abs(topSprite.GetSize()->y * topSprite.GetScale()->y / 2);
	topSprite.MoveTo(topPos);

	Vector3 botPos = pos;
	botPos.y -= (gap / 2) + Math::Abs((botSprite.GetSize()->y * botSprite.GetScale()->y) / 2);
	botSprite.MoveTo(botPos);
}

float Rock::GetX() {
	return topSprite.GetPos()->x;
}

float Rock::GetWidth() {
	return topSprite.GetSize()->x * topSprite.GetScale()->x;
}

void Rock::SetGap(float _gap) {
	gap = _gap;
	UpdatePosition();
}

void Rock::SetSpeed(float _speed) {
	speed = _speed;
}

Rigidbody Rock::GetTopRB() {
	return topRB;
}
Rigidbody Rock::GetBotRB() {
	return botRB;
}