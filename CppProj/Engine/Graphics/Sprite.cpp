#include "Sprite.h"

Sprite::Sprite() {
	xPos = 0;
	yPos = 0;
	rot = 0;
	speed = 5;
	texture = Texture();
}

Sprite::Sprite(string imagePath) {
	texture = Texture(imagePath);
	xPos = 0;
	yPos = 0;
	rot = 0;
	speed = 5;
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos) {
	texture = Texture(imagePath);
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	speed = 5;
}

void Sprite::Update() {

}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	//translate -> rotate -> scale
	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale, yScale, 1);

	//Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex2f(0, 0);
	glTexCoord2f(1, 0);		glVertex2f(texture.GetWidth(), 0);
	glTexCoord2f(1, 1);		glVertex2f(texture.GetWidth(), texture.GetHeight());
	glTexCoord2f(0, 1);		glVertex2f(0, texture.GetHeight());

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SpeedTo(float x) {
	speed = x;
}

void Sprite::SpeedBy(float x) {
	speed += x;
}

void Sprite::MoveTo(float x, float y) {
	xPos = x;
	yPos = y;
}

void Sprite::MoveBy(float x, float y) {
	xPos += x;
	yPos += y;
}

void Sprite::RotateTo(float x) {
	rot = x;
}

void Sprite::RotateBy(float x) {
	rot += x;
}

void Sprite::SetScale(float x) {
	xScale = x;
	yScale = x;
}

void Sprite::SetScale(float x, float y) {
	xScale = x;
	yScale = y;
}