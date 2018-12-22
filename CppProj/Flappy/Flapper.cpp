#include "Flapper.h"
#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"

#define INIT_F 0.8f
#define GRAVITY -9.8
#define DEFAULT_FORCE 300
#define MAX_ROT 30

Flapper::Flapper() {
	flapForce = DEFAULT_FORCE;
	maxRot = MAX_ROT;
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

	HandleInput();

	sprite.Update();
	rb.Update();

	float yVel = rb.GetVel().y;
	if (flapForce == 0) {
		flapForce = DEFAULT_FORCE;
	}

	float newRot = (maxRot / flapForce) * yVel;
	//cout << yVel << "::" << newRot << endl;

	// give min limit to avoid over rotate
	if( newRot > minRot)
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

void Flapper::Reset() {
	sprite.MoveTo(Vector3(Engine::SCREEN_WIDTH / 4, Engine::SCREEN_HEIGHT / 2, 0));
	sprite.RotateTo(0);
	rb.SetVel(Vector3(0, 0, 0));
}

Sprite& Flapper::GetSprite() {
	return sprite;
}

Rigidbody& Flapper::GetRB() {
	return rb;
}

void Flapper::HandleInput() {
	if (Keyboard::Key(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		Flap();
	}
}