#include "Rigidbody.h"
#include "../Engine.h"
#include "../Graphics/Texture.h"

#include "../Math/Math.h"
#include <vector>

Rigidbody::Rigidbody() {
	friction = 1;
	gravity = 0;
}

void Rigidbody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _boundingRect) {
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	lastRot = *rot;
	scale = _scale;
	size = _size;

	boundingRect = _boundingRect;
}

void Rigidbody::Update() {

	velocity.x *= friction;
	velocity.y += gravity;

	*pos = *pos + (velocity * Engine::GetDT());

	if (lastRot != *rot) {
		boundingRect.lowerLeftVertex = Math::RotatePoint(boundingRect.lowerLeftVertex, Vector3(0), *rot - lastRot);
		boundingRect.lowerRightVertex = Math::RotatePoint(boundingRect.lowerRightVertex, Vector3(0), *rot - lastRot);
		boundingRect.upperLeftVertex = Math::RotatePoint(boundingRect.upperLeftVertex, Vector3(0), *rot - lastRot);
		boundingRect.upperRightVertex = Math::RotatePoint(boundingRect.upperRightVertex, Vector3(0), *rot - lastRot);
		lastRot = *rot;
	}

}

void Rigidbody::Render(Vector3 c) {
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	glScalef(scale->x, scale->y, scale->z);

	//Rendering
	glColor4f(c.x, c.y, c.z, 1);
	/*glBegin(GL_LINES);
	{

		glVertex2f(boundingRect.lowerLeftVertex.x, boundingRect.lowerLeftVertex.y);
		glVertex2f(boundingRect.lowerRightVertex.x, boundingRect.lowerRightVertex.y);

		glVertex2f(boundingRect.lowerRightVertex.x, boundingRect.lowerRightVertex.y);
		glVertex2f(boundingRect.upperRightVertex.x, boundingRect.upperRightVertex.y);

		glVertex2f(boundingRect.upperRightVertex.x, boundingRect.upperRightVertex.y);
		glVertex2f(boundingRect.upperLeftVertex.x, boundingRect.upperLeftVertex.y);

		glVertex2f(boundingRect.upperLeftVertex.x, boundingRect.upperLeftVertex.y);
		glVertex2f(boundingRect.lowerLeftVertex.x, boundingRect.lowerLeftVertex.y);

	}
	glEnd();*/
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

bool Rigidbody::IsColliding(const Rigidbody& rbA, const Rigidbody& rbB) {
	Rect rectA = rbA.boundingRect;
	Rect rectB = rbB.boundingRect;

	Vector3 aUR = rectA.upperRightVertex	+ *rbA.pos;
	Vector3 aUL = rectA.upperLeftVertex		+ *rbA.pos;
	Vector3 aLR = rectA.lowerRightVertex	+ *rbA.pos;
	Vector3 aLL = rectA.lowerLeftVertex		+ *rbA.pos;
	Vector3 bUR = rectB.upperRightVertex	+ *rbB.pos;
	Vector3 bUL = rectB.upperLeftVertex		+ *rbB.pos;
	Vector3 bLR = rectB.lowerRightVertex	+ *rbB.pos;
	Vector3 bLL = rectB.lowerLeftVertex		+ *rbB.pos;

	float aMax = 0;
	float aMin = 0;
	float bMax = 0;
	float bMin = 0;

	Vector3 axis1 = aUR - aUL;
	Vector3 axis2 = aUR - aLR;
	Vector3 axis3 = bUL - bLL;
	Vector3 axis4 = bUL - bUR;

	vector<Vector3> axes;
	axes.push_back(axis1);
	axes.push_back(axis2);
	axes.push_back(axis3);
	axes.push_back(axis4);

	for (int i = 0; i < axes.size(); i++) {
		Vector3 aURProj = Vector3::Project(aUR, axes[i]);
		Vector3 aULProj = Vector3::Project(aUL, axes[i]);
		Vector3 aLRProj = Vector3::Project(aLR, axes[i]);
		Vector3 aLLProj = Vector3::Project(aLL, axes[i]);
		Vector3 bURProj = Vector3::Project(bUR, axes[i]);
		Vector3 bULProj = Vector3::Project(bUL, axes[i]);
		Vector3 bLRProj = Vector3::Project(bLR, axes[i]);
		Vector3 bLLProj = Vector3::Project(bLL, axes[i]);


		float aURScalar = Vector3::Dot(aURProj, axes[i]);
		float aULScalar = Vector3::Dot(aULProj, axes[i]);
		float aLRScalar = Vector3::Dot(aLRProj, axes[i]);
		float aLLScalar = Vector3::Dot(aLLProj, axes[i]);
		float bURScalar = Vector3::Dot(bURProj, axes[i]);
		float bULScalar = Vector3::Dot(bULProj, axes[i]);
		float bLRScalar = Vector3::Dot(bLRProj, axes[i]);
		float bLLScalar = Vector3::Dot(bLLProj, axes[i]);

		vector<float> aScalars;
		aScalars.push_back(aURScalar);
		aScalars.push_back(aULScalar);
		aScalars.push_back(aLRScalar);
		aScalars.push_back(aLLScalar);
		aMin = Math::Min(aScalars);
		aMax = Math::Max(aScalars);

		vector<float> bScalars;
		bScalars.push_back(bURScalar);
		bScalars.push_back(bULScalar);
		bScalars.push_back(bLRScalar);
		bScalars.push_back(bLLScalar);
		bMin = Math::Min(bScalars);
		bMax = Math::Max(bScalars);

		// gap between projections, then no colliding. check all four edges
		if( !(bMin <= aMax && bMax >= aMin)) {
			return false;
		}
	}

	return true;
}