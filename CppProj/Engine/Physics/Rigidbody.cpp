#include "Rigidbody.h"
#include "../Engine.h"
#include "../Graphics/Texture.h"

Rigidbody::Rigidbody() {
	friction = 1;
	gravity = 0;
}

void Rigidbody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size) {
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
}

void Rigidbody::Update() {

	velocity.x *= friction;
	velocity.y += gravity;

	*pos = *pos + (velocity * Engine::GetDT());

}

void Rigidbody::Render(Vector3 c) {
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);

	//Rendering
	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{

		glVertex2i(-(int)size->x / 2,	-(int)size->y / 2);
		glVertex2i((int)size->x / 2,	 -(int)size->y / 2);

		glVertex2i((int)size->x / 2,	-(int)size->y / 2);
		glVertex2i((int)size->x / 2,	(int)size->y / 2);

		glVertex2i((int)size->x / 2,	(int)size->y / 2);
		glVertex2i(-(int)size->x / 2, (int)size->y / 2);

		glVertex2i(-(int)size->x / 2, (int)size->y / 2);
		glVertex2i(-(int)size->x / 2, -(int)size->y / 2);
	}
	glEnd();
}

void Rigidbody::AddForce(Vector3 f) {

	velocity = velocity + f;
}

Vector3 Rigidbody::GetVel() {
	return velocity;
}

void Rigidbody::SetVel(Vector3 v) {
	velocity = v;
}