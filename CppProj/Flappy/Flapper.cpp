#include "Flapper.h"
#include "../Engine/Engine.h"

#define INIT_F 0.8f
#define GRAVITY -8
#define DEFAULT_FORCE 400

Flapper::Flapper() {
	flapForce = DEFAULT_FORCE;
	maxRot = 30;
	minRot = -maxRot;
}

Flapper::Flapper(Sprite _sprite):Flapper() {
	sprite = _sprite;
	Vector3 sizeOffset(0.9, 0.8, 1);
	Rect boundingRect = Rect();
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale() * sizeOffset);
	rb.Initialize(INIT_F, GRAVITY, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
}

void Flapper::Update() {
	sprite.Update();
	rb.Update();

	float yVel = rb.GetVel().y;
	if (flapForce == 0) {
		flapForce = DEFAULT_FORCE;
	}

	float newRot = (maxRot / flapForce) * yVel;
	//cout << yVel << "::" << newRot << endl;
	sprite.RotateTo(newRot);
}

void Flapper::Render() {
	sprite.Render();
	rb.Render(Vector3(1));
}

void Flapper::Flap() {
	rb.SetVel(Vector3(0, flapForce, 0));

	sprite.RotateTo(maxRot);
}

Sprite& Flapper::GetSprite() {
	return sprite;
}

Rigidbody& Flapper::GetRB() {
	return rb;
}